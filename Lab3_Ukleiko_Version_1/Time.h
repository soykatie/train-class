#pragma once
#include<iostream>
#include <string>
class Time
{
	int hour;
	int minute;
public:
	Time();
	Time(int hour, int minute);
	~Time();

	void setHour(int hour);
	void setMinute(int minute);
	void setTime(int hour, int minute);

	int getHour();
	int getMinute();

	std::string toString();
	char* toCharArray();
};

