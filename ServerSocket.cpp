#include "ServerSocket.h"

#include "SocketError.h"

ServerSocket::ServerSocket(short int port, int backlog) : Socket() {
	bind(port, backlog);
}

void ServerSocket::bind(short int port, int backlog) {
	bind(Address((long int)INADDR_ANY, (short int)port), backlog);
}

void ServerSocket::bind(const Address &addr, int backlog) {
	this->addr = addr;
	
	int errno1 = ::bind(sockfd, (struct sockaddr *) &(addr.addr_in), sizeof(addr.addr_in));
	if (errno1 == -1) throw SocketError(this);
	
	int errno2 = ::listen(sockfd, backlog);
	if (errno2 == -1) throw SocketError(this);
}

Socket *ServerSocket::accept() {
	Address new_addr;
	
	int addrlen = sizeof(new_addr.addr_in);
	
	int new_fd = ::accept(sockfd, (struct sockaddr *) &(new_addr.addr_in), &addrlen);
	if (new_fd == -1) throw SocketError(this);
	
	Socket *sock = new Socket(new_fd, new_addr);
	
	return sock;
}