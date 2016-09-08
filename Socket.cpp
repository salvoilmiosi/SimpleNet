#include "Socket.h"

#include "SocketClosedError.h"
#include "FailedConnectionError.h"

Socket::Socket() {
	sockfd = ::socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) throw SocketError(this);
}

Socket::Socket(Address addr) {
	sockfd = ::socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) throw SocketError(this);
	connect(addr);
}

Socket::Socket(int sockfd, Address addr) {
	this->sockfd = sockfd;
	this->addr = addr;
}

void Socket::connect(const Address &addr) {
	this->addr = addr;

	int err = ::connect(sockfd, (struct sockaddr *) &(addr.addr_in), sizeof(addr.addr_in));
	if (err == -1) {
		err = WSAGetLastError();
		switch (err) {
		case WSAECONNREFUSED:
			throw FailedConnectionError(this, err);
			break;
		default:
			throw SocketError(this, err);
		}
	}
}

Address &Socket::getAddress() {
	return addr;
}

void Socket::send(ByteArray &data) {
	int bytes = ::send(sockfd, data.getData(), data.getSize(), 0);
	data.setSize(bytes);

	if (bytes == -1) throw SocketError(this);
}

void Socket::receive(ByteArray *data, int maxdatasize) {
	if (maxdatasize > data->getSize()) {
		data->makeNew(maxdatasize);
	} else {
		data->zero();
	}

	int bytes = ::recv(sockfd, data->getData(), maxdatasize, 0);
	data->setSize(bytes);

	if (bytes == 0) {
		throw SocketClosedError(this, 0);
	} else if (bytes == -1) {
		int err = WSAGetLastError();
		switch (err) {
		case WSAECONNABORTED:
		case WSAECONNRESET:
			throw SocketClosedError(this, err);
			break;
		default:
			throw SocketError(this, err);
		}
	}
}

ByteArray *Socket::receive(int maxdatasize) {
	ByteArray *data = new ByteArray;
	receive(data, maxdatasize);
	return data;
}

void Socket::close() {
	::closesocket(sockfd);
}
