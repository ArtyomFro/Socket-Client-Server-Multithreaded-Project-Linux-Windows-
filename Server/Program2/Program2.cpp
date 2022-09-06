// Program2.cpp: определяет точку входа для приложения.
//

#include "Program2.h"

int main()
{
	long SUCCESSFUL;
	char32_t ca=NULL;
#ifdef _WIN32
	WSAData WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1); 
	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);
	if (SUCCESSFUL != 0) {
		printf("WSAStartup failed with error: %d\n", SUCCESSFUL);
		return 1;
	}
	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);
	SOCKET sock_LISTEN; 
	SOCKET sock_CONNECTION;
#else
	int sock_CONNECTION;
	int sock_LISTEN;
	struct sockaddr_in ADDRESS;
	socklen_t AddressSize = sizeof(ADDRESS);
#endif
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(3000);
	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
#ifdef _WIN32
	bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
#else
	bind(sock_LISTEN, (struct sockaddr*)&ADDRESS, sizeof(ADDRESS));
#endif
	listen(sock_LISTEN, SOMAXCONN);
	std::cout << "\n\tSERVER: WAITING for incoming data...\n";
	while (1) {
#ifdef _WIN32
		sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize);
#else
		sock_CONNECTION = accept(sock_LISTEN, (struct sockaddr*)&ADDRESS, &AddressSize);
#endif	
			if (recv(sock_CONNECTION, (char*)&ca, sizeof(char32_t), NULL)) {
				if (ca != NULL) {
					int Num =static_cast<int>(ca);
					std::string NumCount = std::to_string(Num);
					if ((NumCount.size() >= 2) && ((Num % 32) == 0)) {
						std::cout << "SERVER: RECIEVED following data:" << std::endl;
						std::cout << Num << std::endl;
					}
					else {
						std::cerr << "ERROR: Incorrect data. " << std::endl;
					}
					ca = NULL;
				}

			}
	}
	return 0;
}
