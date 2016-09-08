#ifndef __HOSTNAMEERROR_H_
#define __HOSTNAMEERROR_H_

#include "NetError.h"

static const char *MESSAGE = "unresolvable host";

class DECLSPEC HostnameError : public NetError {
public:
	HostnameError(const int code): NetError(MESSAGE, code) {}

	HostnameError(const char *message, const int code) : NetError(message, code) {}
};

#endif
