#pragma once

#include <algorithm>
class IMap
{
public:
	virtual bool inRange(std::pair<int, int> poz) = 0;
	virtual std::pair<int, int> randomValidPosition() = 0;
	virtual bool movePiece(std::pair<int, int> from, std::pair<int, int> to) = 0;
	virtual int getClosestPiece(std::pair<int, int> poz) const = 0;
};

