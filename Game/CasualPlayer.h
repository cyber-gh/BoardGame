#pragma once
#include "Player.h"
class CasualPlayer :
	public Player
{
public:
	CasualPlayer(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) : Player(poz, id) { }

	virtual std::pair<int, int> nextPoz();

	virtual void ability();
	~CasualPlayer() {};
};

