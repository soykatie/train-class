#include <iostream>
#include "Date.h"
#include "Exceptions.h"
#include "IDate.h"
#include "ITime.h"
#include "TransportInfo.h"
#include "ITransportInfo.h"
#include "Train.h"
#include "ITrain.h"
#include "TrainFactory.h"
#include "ProcessorTrainArray.h"

using namespace std;

int main() 
{
	try 
	{
		Train* trainArray;
		int sizeTrainArray;
		do 
		{
			cout << "Input size of train array: ";
			cin >> sizeTrainArray;
		} while (sizeTrainArray <= 0);

		trainArray = TrainFactory::iArrayTrain(sizeTrainArray);
		cout << endl << endl;
		cout << "Array of trains:" << endl;
		for (int i = 0; i < sizeTrainArray; i++)
		{
			cout << trainArray[i].toCharArray() << endl << endl;
		}
		cout << "Menu" << endl;
		cout << "Press 1 - to see the list of trains with the given destination" << endl;
		cout << "Press 2 - to see the list of trains with the given destination and later than the given departure time" << endl;
		cout << "Press 3 - to see the list of trains with the given destination and have all seats" << endl;
		int num;
		cin >> num;
		switch (num)
		{
		case 1: 
		{
			int newSize = 0;
			char destination[100];
			cout << "Choose destination: ";
			cin >> destination;
			cout << endl << "\nResult array of trains to " << destination << endl;
			Train* res = ProcessorTrainArray::chooseDestination(trainArray, sizeTrainArray, destination, newSize);
			if (newSize == 0)
			{
				cout << "No such!" << endl;
			}

			for (int i = 0; i < newSize; i++)
			{
				cout << res[i].toCharArray() << endl << endl;
			}
			break;
		}
		case 2: 
		{
			int newSize = 0;
			char destination[100];
			int hour;
			cout << "Choose destination: ";
			cin >> destination;
			cout << "Choose hour: ";
			cin >> hour;
			cout << "\nResult array of trains to " << destination<< " after " << hour << " hour:" << endl;
			Train* res = ProcessorTrainArray::chooseDestinationAndHour(trainArray, sizeTrainArray, destination, hour, newSize);
			if (newSize == 0)
			{
				cout << "No such!" << endl;
			}

			for (int i = 0; i < newSize; i++)
			{
				cout << res[i].toCharArray() << endl << endl;
			}
			break;
		}
		case 3:
		{
			int newSize = 0;
			char destination[100];
			int allSeats = 0;
			cout << "Choose destination: ";
			cin >> destination;
			cout << "Choose number of all seats: ";
			cin >> allSeats;
			cout << endl << "\nResult array of trains to " << destination  << " with all seats = " << allSeats << endl;
			Train* res = ProcessorTrainArray::chooseDestinationAndHasAllSeats(trainArray, sizeTrainArray, destination, allSeats, newSize);
			if (newSize == 0 || allSeats == 0)
			{
				cout << "No such!" << endl;
			}

			for (int i = 0; i < newSize; i++)
			{
				cout << res[i].toCharArray() << endl << endl;
			}
			break;
		}
		default: {cout << "You've chosen the wrong number!" << endl; break;}
		}
		
	}

	catch (Exceptions& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}

	system("pause");
	return 0;
}