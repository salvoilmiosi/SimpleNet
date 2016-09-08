#ifndef __SOCKET_ERROR_
#define __SOCKET_ERROR_

#include "NetError.h"

class Socket;

class DECLSPEC SocketError : public NetError {
	Socket *sock;
public:
	SocketError(Socket *sock) : NetError(), sock(sock) {}

	SocketError(Socket *sock, const int code) : NetError(code), sock(sock) {}

	SocketError(Socket *sock, const char *message, const int code) :
		NetError(message, code), sock(sock) {}

	Socket *getSocket() {
		return sock;
	}
};

#endif
