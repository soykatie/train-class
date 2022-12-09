#include <string>
#include <iostream>
#include "Exceptions.h"
using namespace std;

Exceptions::Exceptions(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* Exceptions::what() {
	return str;
}
