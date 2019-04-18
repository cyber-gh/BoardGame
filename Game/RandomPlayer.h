#pragma once
#include "Player.h"
class RandomPlayer :
	public Player
{
public:
	RandomPlayer(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) : Player(poz, id) { }

	virtual std::pair<int, int> nextPoz() {
		return std::make_pair(poz.first - 1, poz.second - 1);
	}
	virtual void ability() {
		this->isVisible = !this->isVisible;
	}

	~RandomPlayer() {};
};

