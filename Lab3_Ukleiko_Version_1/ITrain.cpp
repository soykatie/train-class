#include <iostream>
#include "ITransportInfo.h"
#include "ITrain.h"
#include "Validator.h"

#define MAX_LENGTH 100

using namespace std;


Train ITrain::iConsole() 
{
	Train train;
	Validator validator;
	ITransportInfo iTransportInfo;
	TransportInfo transportInfo = iTransportInfo.inputTransportInfo();
	train.setTransportInfo(transportInfo);

	int temp = 0;

	char destination[100];
	cout << "Enter destination of the train (for example: Minsk):" << endl;
	cin >> destination;
	train.setDestination(destination);

	do 
	{
		cout << "Enter number of all seats(from 1 to 999): " << endl;
		cin >> temp;
		temp = check(cin, temp);
	} while (!validator.isNumberOfAllSeatsValid(temp));
	train.setAllSeats(temp);

	do 
	{
		cout << "Enter number of compartment seats (from 1 to 36): " << endl;
		cin >> temp;
		temp = check(cin, temp);
	} while (!validator.isNumberOfCompartmentSeatsValid(temp));
	train.setCompartmentSeats(temp);

	do 
	{
		cout << "Enter number of reserved seats (from 1 to 54):" << endl;
		cin >> temp;
		temp = check(cin, temp);
	} while (!validator.isNumberOfReservedSeatsValid(temp));
	train.setReservedSeats(temp);

	return train;
}
