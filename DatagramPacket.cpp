#include "DatagramPacket.h"

const DatagramPacket & DatagramPacket::operator =(const DatagramPacket &old_pack) {
	addr = old_pack.addr;
	
	return *this;
}

DatagramPacket::DatagramPacket(Address addr, char *data, int datasize) : ByteArray(data, datasize) {
	setAddress(addr);
}

DatagramPacket::DatagramPacket(Address addr, const int datasize) : ByteArray(datasize) {
	setAddress(addr);
}