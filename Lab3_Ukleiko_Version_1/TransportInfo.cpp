#include "TransportInfo.h"
#include "Validator.h"
#include "Exceptions.h"
#include <string>

#define MAX_LENGTH 100

using namespace std;

TransportInfo::TransportInfo() {}

TransportInfo::TransportInfo(int trainNumber, int day, int month, int year, int hour, int minute) 
{
	setTransportInfo(trainNumber, day, month, year, hour, minute);
}

TransportInfo::~TransportInfo() {}

int TransportInfo::getTrainNumber() 
{
	return trainNumber;
}

Date TransportInfo::getDepartureDate() 
{
	return this->departureDate;
}

Time TransportInfo::getDepartureTime()
{
	return this->departureTime;
}

void TransportInfo::setTrainNumber(int trainNumber) 
{
	Validator validator;
	if (validator.isTrainNumberValid(trainNumber))
		this->trainNumber = trainNumber;
	else throw Exceptions("The number train number is wrong!");
}

void TransportInfo::setDepartureDate(int day, int month, int year) 
{

	this->departureDate.setDate(day, month, year);
}

void TransportInfo::setDepartureDate(Date date) 
{
	this->departureDate = date;
}

void TransportInfo::setDepartureTime(int hour, int minute)
{

	this->departureTime.setTime(hour, minute);
}

void TransportInfo::setDepartureTime(Time time)
{
	this->departureTime = time;
}

void TransportInfo::setTransportInfo(int trainNumber, int day, int month, int year, int hour, int minute) 
{
	setTrainNumber(trainNumber);
	setDepartureDate(day, month, year);
	setDepartureTime(hour, minute);
}

string TransportInfo::toString()
{
	string str = "Train number ";
	str = str + to_string(trainNumber) + "\nDeparture date : " + departureDate.toString() + ", departure time : " +
		departureTime.toString();
	return str;
}

char* TransportInfo::toCharArray() 
{
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(temp, sizeStr, "Train number ");
	strcpy_s(str, sizeStr, temp);
	_itoa_s(this->trainNumber, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\n");
	strcat_s(str, sizeStr, this->departureDate.toCharArray());
	strcat_s(str, sizeStr, "\n");
	strcat_s(str, sizeStr, this->departureTime.toCharArray());
	return str;
}







