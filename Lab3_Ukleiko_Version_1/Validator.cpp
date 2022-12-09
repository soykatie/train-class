#include <time.h>
#include "Validator.h"

#define MAX_TRAIN_NUMBER 9999
#define MAX_NUMBER_OF_ALL_SEATS 999
#define MAX_NUMBER_OF_COMPARTMENT_SEATS 36
#define MAX_NUMBER_OF_RESERVED_SEATS 54

bool Validator::isYearValid(int year) 
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int currentYear = newtime.tm_year + 1900;
	if (year >= 0 && year <= currentYear) return true;
	else return false;
}

bool Validator::isMonthValid(int month) 
{
	if (month >= 1 && month <= 12) return true;
	else return false;
}

bool Validator::isLeap(int year) 
{
	return !(year % 4 != 0 || year % 100 == 0 && year % 400 != 0);
}

bool Validator::isDayValid(int day, int month, int year) 
{
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYearValid(year) && isYearValid(month)) 
	{
		if (isLeap(year)) lastMonthDay[1] = 29;
		if (day >= 1 && day <= lastMonthDay[month - 1]) return true;
		else return false;
	}
	else return false;
}

bool Validator::isHourValid(int hour)
{
	if (hour >= 0 && hour <= 24) return true;
	else return false;
}

bool Validator::isMinuteValid(int minute)
{
	if (minute >= 0 && minute <= 59) return true;
	else return false;
}

bool Validator::isTimeValid(int hour, int minute)
{
	if (isHourValid(hour) && isMinuteValid(minute)) return true;
	else return false;
}

bool Validator::isTrainNumberValid(int trainNumber)
{
	if (trainNumber >= 1 && trainNumber <= MAX_TRAIN_NUMBER) return true;
	else return false;
}

bool Validator::isNumberOfAllSeatsValid(int allSeats)
{
	if (allSeats >= 1 && allSeats <= MAX_NUMBER_OF_ALL_SEATS) return true;
	else return false;
}

bool Validator::isNumberOfCompartmentSeatsValid(int compartmentSeats)
{
	if (compartmentSeats >= 1 && compartmentSeats <= MAX_NUMBER_OF_COMPARTMENT_SEATS) return true;
	else return false;
}

bool Validator::isNumberOfReservedSeatsValid(int reservedSeats)
{
	if (reservedSeats >= 1 && reservedSeats <= MAX_NUMBER_OF_RESERVED_SEATS) return true;
	else return false;
}


