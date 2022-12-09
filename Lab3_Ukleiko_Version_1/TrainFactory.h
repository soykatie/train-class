#pragma once
#include "Train.h"

class TrainFactory
{
public:
	static Train iTrain();
	static Train* iArrayTrain(int size);
};



