#pragma once
#include "Player.h"
class PassivePlayer :
	public Player
{
public:
	PassivePlayer(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) : Player(poz, id) { }

	virtual std::pair<int, int> nextPoz();

	virtual void ability();

	~PassivePlayer() {};
};

