#ifndef __FAILEDCONNECTIONERROR_H_
#define __FAILEDCONNECTIONERROR_H_

#include "SocketError.h"

static const char *FAILED_CONN_MESSAGE = "connection failed";

class DECLSPEC FailedConnectionError : public SocketError {
public:
	FailedConnectionError(Socket *sock, const int code) :
		SocketError(sock, FAILED_CONN_MESSAGE, code) {}

	FailedConnectionError(Socket *sock, const char *message, const int code) :
		SocketError(sock, message, code) {}
};

#endif // __FAILEDCONNECTIONERROR_H_
