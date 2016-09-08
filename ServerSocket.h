#ifndef __SERVERSOCKET_H_
#define __SERVERSOCKET_H_

#include "SimpleNet.h"

#include "Socket.h"

static const int BACKLOG_DEFAULT = 20;

class DECLSPEC ServerSocket: public Socket {
public:
	ServerSocket(short int port, int backlog = BACKLOG_DEFAULT);

public:
	void bind(short int port, int backlog = BACKLOG_DEFAULT);
	void bind(const Address &addr, int backlog = BACKLOG_DEFAULT);

	Socket *accept();
};

#endif
