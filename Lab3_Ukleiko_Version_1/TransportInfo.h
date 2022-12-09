#pragma once
#include<string>
#include "Date.h"
#include "Time.h"
using namespace std;

#define TRAIN_NUMBER 9999

class TransportInfo
{
	int trainNumber;
	Date departureDate;
	Time departureTime;

public:
	TransportInfo();
	TransportInfo(int trainNumber, int day, int month, int year, int hour, int minute);
	~TransportInfo();

	int getTrainNumber();
	Date getDepartureDate();
	Time getDepartureTime();
	string toString();
	char* toCharArray();

	void setTrainNumber(int trainNumber);
	void setDepartureDate(int day, int month, int year);
	void setDepartureDate(Date date);
	void setDepartureTime(int hour, int minute);
	void setDepartureTime(Time time);
	void setTransportInfo(int trainNumber, int day, int month, int year, int hour, int minute);
};

