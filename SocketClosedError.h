#ifndef __SOCKETCLOSEDERROR_H_
#define __SOCKETCLOSEDERROR_H_

#include "SocketError.h"

static const char *SOCK_CLOSE_MESSAGE = "socket is closed";

class DECLSPEC SocketClosedError : public SocketError {
public:
	SocketClosedError(Socket *sock, const int code) :
		SocketError(sock, SOCK_CLOSE_MESSAGE, code) {}

	SocketClosedError(Socket *sock, const char *message, const int code) :
		SocketError(sock, message, code) {}
};

#endif
