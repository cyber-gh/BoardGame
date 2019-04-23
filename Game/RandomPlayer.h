#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) : Player(poz, id) { damage = 10; }

	virtual std::pair<int, int> nextPoz();
	virtual void ability();

	~RandomPlayer() {};
};

