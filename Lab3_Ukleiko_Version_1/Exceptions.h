#pragma once

class Exceptions
{
private:
	char str[200];
public:
	Exceptions(const char* str);
	const char* what();
};

