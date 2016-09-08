#include "NetError.h"

#include <winsock.h>
#include <windows.h>
#include <cstdio>

NetError::NetError() {
	errorCode = WSAGetLastError();
	getDefaultMessage();
}

NetError::NetError(const int code) {
	errorCode = code;
	getDefaultMessage();
}

NetError::NetError(const char *message, const int code) {
	strncpy(this->message, message, MESSAGE_SIZE);
	errorCode = code;
}

const char *NetError::getMessage() {
	return getDefaultMessage();
	//return getErrorCodeMessage();
	//return message;
}

const char *NetError::getErrorCodeMessage() {
    sprintf(message, "Net error: %d", errorCode);
    return message;
}

const char *NetError::getDefaultMessage() {
	char *msg = NULL;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&msg, 0, NULL);
	strncpy(message, msg, MESSAGE_SIZE);
	return msg;
}
