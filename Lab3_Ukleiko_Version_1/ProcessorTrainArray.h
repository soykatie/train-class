#pragma once
#include "Train.h"

class ProcessorTrainArray
{
public:
	static Train* chooseDestination(Train* arrayTrain, int size, char* destination, int& newSize);
	static Train* chooseDestinationAndHour(Train* arrayTrain, int size, char* destination, int hour, int& newSize);
	static Train* chooseDestinationAndHasAllSeats(Train* arrayTrain, int size, char* destination, int allSeats, int& newSize);
};

