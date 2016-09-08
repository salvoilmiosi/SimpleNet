#include "ByteArray.h"

#include <cstring>

ByteArray::ByteArray() {
	data = NULL;
	datasize = 0;
	isNew = false;
}

ByteArray::ByteArray(const int datasize) {
	makeNew(datasize);
}

ByteArray::ByteArray(char *data, int datasize) {
	setData(data, datasize);
	isNew = false;
}

ByteArray::ByteArray(const ByteArray &old_ba) {
	*this = old_ba;
}

ByteArray::~ByteArray() {
	if (isNew) delete[] data;
}

const ByteArray &ByteArray::operator = (const ByteArray &old_ba) {
	data = old_ba.data;
	datasize = old_ba.datasize;
	isNew = old_ba.isNew;
	
	return *this;
}

void ByteArray::makeNew(int datasize) {
	data = new char[datasize];
	
	this->datasize = datasize;
	isNew = true;
}

void ByteArray::zero() {
	memset(data, '\0', datasize);
}

void ByteArray::setData(char *data, int datasize) {
	this->data = data;
	this->datasize = datasize;
	isNew = false;
}

char *ByteArray::getData() const {
	return data;
}

char *ByteArray::getString() const {
	static char *substr = NULL;
	if (substr != NULL) delete[] substr;
	substr = new char[datasize+1];
	strncpy(substr, data, datasize);
	substr[datasize] = '\0';
	return substr;
}

void ByteArray::setSize(int datasize) {
	this->datasize = datasize;
}

int ByteArray::getSize() const {
	return datasize;
}
