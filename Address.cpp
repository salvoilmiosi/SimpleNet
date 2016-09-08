#include "Address.h"

#include "HostnameError.h"

void Address::zeroAddr() {
	memset(&addr_in, '\0', sizeof(addr_in));
	addr_in.sin_family = AF_INET;
}

Address::Address(char *hostname, short int port) {
	zeroAddr();

	setHostname(hostname);
	setPort(port);
}

Address::Address(long int addr, short int port) {
	zeroAddr();

	setIP(addr);
	setPort(port);

	addr_in.sin_port = htons(port);
}

void Address::setHostname(char *hostname) {
	struct hostent *h = NULL;
	h = gethostbyname(hostname);

	if (h == NULL) throw HostnameError(WSAGetLastError());

	addr_in.sin_family = AF_INET;
	addr_in.sin_addr = *((struct in_addr *)h->h_addr);
}

char *Address::getHostname() const {
	return inet_ntoa(addr_in.sin_addr);
}

void Address::setPort(short int port) {
	addr_in.sin_port = htons(port);
}

short int Address::getPort() const {
	return ntohs(addr_in.sin_port);
}
