#include <iostream>
#include "IDate.h"
#include "Validator.h"
#include "ITransportInfo.h"
using namespace std;

Date IDate::iDateConsole() 
{
	Date date;
	int year, month, day;
	Validator validator;
	do 
	{
		cout << "Enter year:" << endl;
		cin >> year;
		year = check(cin, year);
	} while (!validator.isYearValid(year));

	do 
	{
		cout << "Enter month:" << endl;
		cin >> month;
		month = check(cin, month);
	} while (!validator.isMonthValid(month));

	do 
	{
		cout << "Enter day:" << endl;
		cin >> day;
		day = check(cin, day);
	} while (!validator.isDayValid(day, month, year));

	date.setDate(day, month, year);
	return date;
}