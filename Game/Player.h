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


	Player(std::pair<int, int> poz = std::make_pair(0, 0), int id = 0) {
		this->poz = poz;
		this->identifier = id;
		
	}


	
	virtual void ability() {
		
	}
	virtual void attack(IPlayer&) {};

	void attack(Player& other) {

		int damageToDeal = this->damage;
		if (other.armor > 0) {
			if (damageToDeal / 2 >= other.armor) {
				other.armor -= damageToDeal / 2;
				return;
			}
			else {
				damageToDeal -= other.armor / 2;
				other.armor = 0;
				other.health -= damageToDeal;
			}
		}
		else {
			other.health -= damageToDeal;
		}
		if (other.health < 0) other.isDead = true;
	}
	~Player() {};
};

