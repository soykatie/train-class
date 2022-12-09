#pragma once

class Validator
{
public:
	bool isYearValid(int year);
	bool isMonthValid(int year);
	bool isLeap(int year);
	bool isDayValid(int day, int month, int year);
	bool isHourValid(int hour);
	bool isMinuteValid(int minute);
	bool isTimeValid(int hour, int minute);
	bool isTrainNumberValid(int trainNumber);
	bool isNumberOfAllSeatsValid(int allSeats);
	bool isNumberOfCompartmentSeatsValid(int compartmentSeats); //купейные места
	bool isNumberOfReservedSeatsValid(int reservedSeats); //плацкартные места
};

