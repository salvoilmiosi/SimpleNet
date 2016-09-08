#ifndef __SOCKET_H_
#define __SOCKET_H_

#include "SimpleNet.h"

#include <winsock.h>

#include "Address.h"
#include "ByteArray.h"

class DECLSPEC Socket {
protected:
	int sockfd;
	Address addr;

public:
	Socket();
	Socket(const Address addr);

	virtual ~Socket() {
		close();
	}

private:
	Socket(int sockfd, Address addr);

	Socket(const Socket &old_sock) {} // copying not allowed

	friend class ServerSocket;

public:
	void connect(const Address &addr);
	Address &getAddress();

	void send(ByteArray &data);

	void receive(ByteArray *data, int maxdatasize);
	ByteArray *receive(int maxdatasize);

	void close();
};

#endif
