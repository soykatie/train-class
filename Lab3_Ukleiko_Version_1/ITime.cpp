#include <iostream>
#include "ITime.h"
#include "Validator.h"
#include "ITransportInfo.h"
using namespace std;

Time ITime::iTimeConsole() 
{
	Time time;
	int hour, minute;
	Validator validator;
	do {
		cout << "Enter hour of departure:" << endl;
		cin >> hour;
		hour = check(cin, hour);
	} while (!validator.isHourValid(hour));

	do {
		cout << "Enter minute of departure:" << endl;
		cin >> minute;
		minute = check(cin, minute);
	} while (!validator.isMinuteValid(minute));

	time.setTime(hour, minute);
	return time;
}