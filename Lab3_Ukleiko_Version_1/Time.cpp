#include <iostream>
#include <time.h>
#include "Time.h"
#include "Exceptions.h"
#include "Validator.h"
using namespace std;

Time::Time()
{
	struct tm newtime {};
	this->hour = newtime.tm_hour;
	this->minute = newtime.tm_min;
}

Time::Time(int hour, int minute)
{
	setHour(hour);
	setMinute(minute);
	setTime(hour, minute);
}

Time::~Time() {}

void Time::setHour(int hour)
{
	Validator validator;
	if (validator.isHourValid(hour))
		this->hour = hour;
	else throw Exceptions("The hour is wrong!");
}

void Time::setMinute(int minute)
{
	Validator validator;
	if (validator.isMinuteValid(minute))
		this->minute = minute;
	else throw Exceptions("The minute is wrong!");
}

void Time::setTime(int hour, int minute)
{
	Validator validator;
	if (validator.isTimeValid(hour, minute))
	{
		this->hour = hour;
		this->minute = minute;
	}
	else throw Exceptions("The time is wrong!");
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

char* Time::toCharArray()
{
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(temp, sizeStr, "Departure date: ");
	strcpy_s(str, sizeStr, temp);
	_itoa_s(this->hour, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, ":");
	_itoa_s(this->minute, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}

string Time::toString()
{
	string str;
	str = std::to_string(hour) + ".";
	str += std::to_string(minute);
	return str;
}
