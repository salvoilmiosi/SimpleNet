#include "SimpleNet.h"

#include <iostream>

#include <windows.h>
#include <winsock.h>

bool SimpleNet_Init() {
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		return false;
	}
	return true;
}

bool SimpleNet_Quit() {
	WSACleanup();
	return true;
}
