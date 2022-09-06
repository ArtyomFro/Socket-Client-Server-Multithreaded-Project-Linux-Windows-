// Program2.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#define SCKVERSION2 0x0202
#include <iostream>
#include <string>
#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 
#endif
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
