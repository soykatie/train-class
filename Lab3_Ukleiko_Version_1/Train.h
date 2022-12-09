#pragma once
#include "TransportInfo.h"

#define DESTINATION_LENGTH 100
#define NUMBER_OF_ALL_SEATS 999
#define NUMBER_OF_COMPARTMENT_SEATS 36
#define NUMBER_OF_RESERVED_SEATS 54

class Train
{
	char destination[DESTINATION_LENGTH];
	TransportInfo transportInfo;
	int allSeats;
	int compartmentSeats;
	int reservedSeats;
	int hour;
public:
	Train();
	Train(char* destination, TransportInfo transportInfo, int allSeats, int compartmentSeats, int reservedSeats, int hour);
	~Train();

	void setDestination(char* destination);
	void setTransportInfo(TransportInfo transportInfo);
	void setAllSeats(int allSeats);
	void setCompartmentSeats(int compartmentSeats);
	void setReservedSeats(int reservedSeats);
	void setHour(int hour);

	char* getDestination();
	int getAllSeats();
	int getCompartmentSeats();
	int getReservedSeats();
	int getHour();
	TransportInfo getTransportInfo();

	string toString();
	char* toCharArray();
};


