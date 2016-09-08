#ifndef __BYTEARRAY_H_
#define __BYTEARRAY_H_

#include "SimpleNet.h"

class DECLSPEC ByteArray {
	char *data;
	int datasize;

	bool isNew;

public:
	ByteArray();
	ByteArray(const int datasize);
	ByteArray(char *data, int datasize);

	virtual ~ByteArray();

	ByteArray(const ByteArray &old_ba);
	const ByteArray &operator = (const ByteArray &old_ba);

public:
	void makeNew(int datasize);
	void zero();

	void setData(char *data, int datasize);
	char *getData() const;

	char *getString() const;

	int getSize() const;
	void setSize(int datasize);
};

#endif
