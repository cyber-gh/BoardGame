#pragma once
#include "Player.h"
class AgressivePlayer :
	public Player
{
public:
	AgressivePlayer(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) : Player(poz, id) { damage = 20; }

	virtual std::pair<int, int> nextPoz();
	virtual void ability();

	~AgressivePlayer() {};
};

