#include <string>
#include "Train.h"
#include "Validator.h"
#include "Exceptions.h"

#define MAX_LENGTH 100

using namespace std;

Train::Train(){}

Train::Train(char* destination, TransportInfo transportInfo, int allSeats, int compartmentSeats, int reservedSeats, int hour)
{
	strcpy_s(this->destination, strlen(destination) + 1, destination);
	setTransportInfo(transportInfo);
	this->allSeats = 0;
	this->compartmentSeats = 0;
	this->reservedSeats = 0;
}

Train::~Train(){}

int Train::getAllSeats() 
{
	return allSeats;
}

int Train::getCompartmentSeats()
{
	return compartmentSeats;
}

int Train::getReservedSeats()
{
	return reservedSeats;
}

TransportInfo Train::getTransportInfo() 
{
	return this->transportInfo;
}

char* Train::getDestination() 
{
	return this->destination;
}

int Train::getHour()
{
	return hour;
}

void Train::setAllSeats(int allSeats) 
{
	Validator validator;
	if (validator.isNumberOfAllSeatsValid(allSeats))
		this->allSeats = allSeats;
	else throw Exceptions("The number of all seats is wrong!");
}

void Train::setCompartmentSeats(int compartmentSeats)
{
	Validator validator;
	if (validator.isNumberOfCompartmentSeatsValid(compartmentSeats))
		this->compartmentSeats = compartmentSeats;
	else throw Exceptions("The number of compartment seats is wrong!");
}

void Train::setReservedSeats(int reservedSeats)
{
	Validator validator;
	if (validator.isNumberOfCompartmentSeatsValid(reservedSeats))
		this->reservedSeats = reservedSeats;
	else throw Exceptions("The number of reserved seats is wrong!");
}

void Train::setDestination(char* destination) 
{
	if (strlen(destination) <= 100)
		strcpy_s(this->destination, strlen(destination) + 1, destination);
	else throw Exceptions("The destination is wrong!");
}

void Train::setTransportInfo(TransportInfo transportInfo) 
{
	this->transportInfo = transportInfo;
}

void Train::setHour(int hour)
{
	Validator validator;
	if (validator.isHourValid(hour))
		this->hour = hour;
	else throw Exceptions("The hour is wrong!");
}

char* Train::toCharArray() 
{
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(str, sizeStr, "\n");
	strcat_s(str, sizeStr, this->transportInfo.toCharArray());
	strcpy_s(str, sizeStr, "\nDestination: ");
	strcpy_s(temp, MAX_LENGTH + 1, this->destination);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nNumber of all seats: ");
	_itoa_s(this->allSeats, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nNumber of compartment seats: ");
	_itoa_s(this->compartmentSeats, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nNumber of reserved seats: ");
	_itoa_s(this->reservedSeats, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}

string Train::toString() 
{
	string str = transportInfo.toString() + "\nDestination: "
		+ this->destination + "\nNumber of all seats: " + to_string(this->allSeats) + "\nNumber of compartment seats: "
		+ to_string(this->compartmentSeats) + "\nNumber of reserved seats: " + to_string(this->reservedSeats);
	return str;
}