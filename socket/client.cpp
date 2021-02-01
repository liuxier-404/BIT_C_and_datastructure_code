#define WIN32_LEAN_AND_MEAN
# define _WINSOCK_DEPRECATED_NO_WARNINGS 
#pragma execution_character_set("utf-8")

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include<string>
#include <stdio.h>
#include<iostream>
using namespace std;

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int   main()
{

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        return -1;
    }
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("192.168.112.128");
    serveraddr.sin_port = htons(12345);
    connect(client, (sockaddr*)&serveraddr, sizeof(serveraddr));
    char sn[100];
    cin >> sn;
    send(client, (char*)&sn, sizeof(sn),0);

    WSACleanup();
    return 0;
}