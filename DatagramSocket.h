#ifndef __DATAGRAMSOCKET_H_
#define __DATAGRAMSOCKET_H_

#include "SimpleNet.h"

#include "Socket.h"
#include "DatagramPacket.h"

class DECLSPEC DatagramSocket: public Socket {
public:
	DatagramSocket();

	DatagramSocket(int port);

	DatagramSocket(const Address &addr);

public:
	void bind(int port);

	void send(DatagramPacket &packet);

	DatagramPacket receive(int maxdatasize);
	void receive(DatagramPacket *packet, int maxdatasize);
};

#endif
