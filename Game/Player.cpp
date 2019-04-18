#include "Player.h"

void fight(Player& first, Player& second) {
	while (!first.isDead || !second.isDead) {
		first.attack(second);
		second.attack(first);
	}
}

