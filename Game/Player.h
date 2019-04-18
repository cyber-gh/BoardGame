#pragma once
#include "IPlayer.h"

class Map;

class Player :
	public IPlayer
{
protected:

	const int dx[4] = { 1,0,-1,0 };
	const int dy[4] = { 0,-1,0,1 };

	int identifier;
	int health = 100;
	int armor = 100;
	bool isVisible = true;
	int damage = 15;
	int speed = 1;
	bool isDead = false;
	std::pair<int, int> poz;

	friend class Map;
	friend void fight(Player& first, Player& second);
public:


	Player(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0);


	
	virtual void ability() {
		
	}
	virtual void attack(IPlayer&) {};

	void attack(Player& other);
	~Player() {};
};

