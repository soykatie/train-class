#include "TrainFactory.h"
#include "ITrain.h"
Train TrainFactory::iTrain()
{
	return ITrain::iConsole();
}

Train* TrainFactory::iArrayTrain(int size)
{
	Train* arrayTrain;
	arrayTrain = new Train[size];
	for (size_t i = 0; i < size; i++)
	{
		arrayTrain[i] = TrainFactory::iTrain();
	}
	return arrayTrain;
}
