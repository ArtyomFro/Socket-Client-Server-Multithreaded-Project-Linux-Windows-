// Program1.cpp: определяет точку входа для приложения.
//

#include "Program1.h"
#include "TH1.h"
#include "TH2.h"

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef _WIN32
	WSAData WinSockData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	long err=WSAStartup(DLLVersion, &WinSockData);
	if (err != 0) {                                
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}
	SOCKADDR_IN ADDRESS;
	SOCKET sock;
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(3000);
#else
	int sock;
	struct sockaddr_in ADDRESS;
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(3000);
#endif
	std::string Buffer;
	TH1 x;
	TH2 y;
	int success;
	std::cout << "Enter an integer(64 characters or less)" << std::endl;
	while (1) {
		sock = socket(AF_INET, SOCK_STREAM, NULL);
#ifdef _WIN32
		success = connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
#else
		success = connect(sock, (struct sockaddr*)&ADDRESS, sizeof(ADDRESS));
#endif
		std::thread Thread_one([&x, &Buffer]() {
			x.InputString();
			bool NotNumber = x.CheckString();
			if (NotNumber == false) {
					x.SortString();
					x.mtx.lock();
				    Buffer = x.InsertString();
					x.mtx.unlock();
			}
			});
		std::thread Thread_two([&y, &Buffer, &sock, &success]() {
			if (!Buffer.empty()) {
					y.DisplayString(Buffer);
					y.CountSum(Buffer);
					y.ClearBuffer(Buffer);
					char c = static_cast<char>(y.sum);
					if (success == 0) {
						send(sock, &c, sizeof(char), NULL);
					}
				y.sum = 0;
			}
			});
	Thread_one.join();
	Thread_two.join();
#ifdef _WIN32
		closesocket(sock);
#else
		close(sock);
#endif
	}
#ifdef _WIN32
	WSACleanup();
#endif
	return 0;
}


