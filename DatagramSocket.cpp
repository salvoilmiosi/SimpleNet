#include "DatagramSocket.h"

#include "SocketClosedError.h"

DatagramSocket::DatagramSocket() {
	sockfd = ::socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) throw SocketError(this);
}

DatagramSocket::DatagramSocket(int port) {
	sockfd = ::socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) throw SocketError(this);
	bind(port);
}

DatagramSocket::DatagramSocket(const Address &addr) {
	sockfd = ::socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) throw SocketError(this);
	connect(addr);
}

void DatagramSocket::bind(int port) {
	Address addr((long int)INADDR_ANY, (short int)port);
	int err = ::bind(sockfd, (struct sockaddr *) &(addr.addr_in), sizeof(addr.addr_in));
	if (err == -1) throw SocketError(this);
}

void DatagramSocket::send(DatagramPacket &packet) {
	int bytes = ::sendto(sockfd, packet.getData(), packet.getSize(), 0,
		(struct sockaddr *) &(packet.getAddress().addr_in), sizeof(packet.getAddress().addr_in));
	packet.setSize(bytes);

	if (bytes == -1) throw SocketError(this);
}

DatagramPacket DatagramSocket::receive(int maxdatasize) {
	DatagramPacket packet;
	receive(&packet, maxdatasize);
	return packet;
}

void DatagramSocket::receive(DatagramPacket *packet, int maxdatasize) {
	if (maxdatasize > packet->getSize()) {
		packet->makeNew(maxdatasize);
	} else {
		packet->zero();
	}

	struct sockaddr_in addr_in;
	int addrlen = sizeof(addr_in);

	int bytes = ::recvfrom(sockfd, packet->getData(), maxdatasize, 0, (struct sockaddr *) &addr_in, &addrlen);
	packet->setSize(bytes);

	Address addr(addr_in.sin_addr.s_addr, ntohs(addr_in.sin_port));
	packet->setAddress(addr);

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
