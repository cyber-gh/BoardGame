#include "Player.h"

void fight(Player& first, Player& second) {
	while (!first.isDead || !second.isDead) {
		first.attack(second);
		second.attack(first);
	}
}

Player::Player(std::pair<int, int> poz, int id) {
	this->poz = poz;
	this->identifier = id;

}

void Player::attack(Player& other) {

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
