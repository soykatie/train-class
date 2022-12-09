#include <iostream>
#include <time.h>
#include "Date.h"
#include "Exceptions.h"
#include "Validator.h"
using namespace std;

Date::Date() 
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	this->day = newtime.tm_mday;
	this->month = static_cast<Month>(newtime.tm_mon + 1);
	this->year = newtime.tm_year + 1900;
}

Date::Date(int day, int month, int year) 
{
	setYear(year);
	setMonth(month);
	setDate(day, month, year);
}

Date::~Date() {}

void Date::setMonth(int month) 
{
	Validator validator;
	if (validator.isMonthValid(month))
		this->month = static_cast<Month>(month);
	else throw Exceptions("The month is wrong!");
}

void Date::setYear(int year) 
{
	Validator validator;
	if (validator.isYearValid(year))
		this->year = year;
	else throw Exceptions("The year is wrong!");
}

void Date::setDate(int day, int month, int year)
{
	Validator validator;
	if (validator.isDayValid(day, month, year)) 
	{
		this->day = day;
		this->month = static_cast<Month>(month);
		this->year = year;
	}
	else throw Exceptions("The date is wrong!");
}

int Date::getDay() 
{
	return day;
}

int Date::getMonth() 
{
	return month;
}

int Date::getYear() 
{
	return year;
}

char* Date::toCharArray() 
{
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(temp, sizeStr, "Departure date: ");
	strcpy_s(str, sizeStr, temp);
	_itoa_s(this->day, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, ".");
	_itoa_s(this->month, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, ".");
	_itoa_s(this->year, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}

std::string Date::toString() 
{
	std::string str;
	str = std::to_string(day);
	str = str + " " + monthString[month - 1] + " ";
	str += std::to_string(year);
	return str;
}
