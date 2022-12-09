#include "ITransportInfo.h"
#include "IDate.h"
#include "ITime.h"
#include "Validator.h"

void ignoreAll(istream& is)
{
	is.clear();
	is.sync();
	is.ignore(is.rdbuf()->in_avail());
}

TransportInfo ITransportInfo::inputTransportInfo()
{
	TransportInfo transportInfo;
	Validator validator;

	int temp = 0;

	do
	{
		cout << "Enter train number:" << endl;
		cin >> temp;
		temp = check(cin, temp);
	} while (!validator.isTrainNumberValid(temp));
	transportInfo.setTrainNumber(temp);

	Date date = IDate::iDateConsole();
	transportInfo.setDepartureDate(date);

	Time time = ITime::iTimeConsole();
	transportInfo.setDepartureTime(time);
	return transportInfo;
}

int check(istream& cin, int temp) 
{
	while (cin.fail()) 
	{
		ignoreAll(cin);
		cout << "Try again! Enter number: ";
		cin >> temp;
	}
	return temp;
}

