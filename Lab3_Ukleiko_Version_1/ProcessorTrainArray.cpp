#include "ProcessorTrainArray.h"
#include "Time.h"
#include "Date.h"

Train* ProcessorTrainArray::chooseDestination(Train* arrayTrain, int size, char* destination, int& newSize)
{
	Train* arrayTr = new Train[size];
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(destination, arrayTrain[i].getDestination()))
		{
			arrayTr[newSize] = arrayTrain[i];
			newSize++;
		}
	}
	return arrayTr;
}

Train* ProcessorTrainArray::chooseDestinationAndHour(Train* arrayTrain, int size, char* destination, int hour, int& newSize)
{
	Train* arrayTr = new Train[size];
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if ((!strcmp(destination, arrayTrain[i].getDestination())) && ((arrayTrain[i].getHour()) >= hour))
		{
			arrayTr[newSize] = arrayTrain[i];
			newSize++;
		}
	}
	return arrayTr;
}

Train* ProcessorTrainArray::chooseDestinationAndHasAllSeats(Train* arrayTrain, int size, char* destination, int allSeats, int& newSize)
{
	Train* arrayTr = new Train[size];
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(destination, arrayTrain[i].getDestination()) && arrayTrain[i].getAllSeats() == allSeats)
		{
			arrayTr[newSize] = arrayTrain[i];
			newSize++;
		}
	}
	return arrayTr;
}
