#ifndef __NETERROR_H_
#define __NETERROR_H_

#include "SimpleNet.h"

const int MESSAGE_SIZE = 128;

class DECLSPEC NetError {
	char message[MESSAGE_SIZE];
	int errorCode;
public:
	NetError();

	NetError(const int code);

	NetError(const char *message, const int code);

	const char *getMessage();

	const int getErrorCode() {
		return errorCode;
	}

	const char *getErrorCodeMessage();

	const char *getDefaultMessage();
};

#endif
