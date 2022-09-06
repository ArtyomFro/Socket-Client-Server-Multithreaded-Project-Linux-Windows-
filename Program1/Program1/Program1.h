// CMakeIntrn.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#define SCK_VERSION2 0x0202
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 
#endif

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
