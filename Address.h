#ifndef __ADDRESS_H_
#define __ADDRESS_H_

#include "SimpleNet.h"

#include <winsock.h>

class DECLSPEC Address {
	struct sockaddr_in addr_in;
	void zeroAddr();

	friend class DatagramSocket;
	friend class ServerSocket;
	friend class Socket;

public:
	Address() {
		zeroAddr();
	}

	Address(char *hostname, short int port);
	Address(long int ip, short int port);

	Address(const Address &old_addr) {
		*this = old_addr;
	}

	const Address &operator = (const Address &old_addr) {
		addr_in = old_addr.addr_in;
		return *this;
	}

public:
	void setIP(long int ip) {
		addr_in.sin_addr.s_addr = ip;
	}

	long int getIP() const {
		return addr_in.sin_addr.s_addr;
	}

	void setHostname(char *hostname);
	char *getHostname() const;

	void setPort(short int port);
	short int getPort() const;
};

#endif
