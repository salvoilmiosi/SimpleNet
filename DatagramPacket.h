#ifndef __DATAGRAMPACKET_H_
#define __DATAGRAMPACKET_H_

#include "SimpleNet.h"

#include "Address.h"
#include "ByteArray.h"

class DECLSPEC DatagramPacket: public ByteArray {
	Address addr;

public:
	DatagramPacket() : ByteArray() {}

	DatagramPacket(Address addr, char *data, int datasize);

	DatagramPacket(Address addr, const int datasize);

	DatagramPacket(const DatagramPacket &old_pack) {
		*this = old_pack;
	}

	const DatagramPacket &operator = (const DatagramPacket &old_pack);

public:
	const Address &getAddress() const {
		return addr;
	}

	void setAddress(const Address &addr) {
		this->addr = addr;
	}
};

#endif
