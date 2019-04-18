#pragma once
#include <algorithm>
#include "IMap.h"

class IPlayer
{
public:
	virtual std::pair<int,int> nextPoz() = 0;
	virtual void ability() = 0;
	virtual void attack(IPlayer& ) = 0;
};

