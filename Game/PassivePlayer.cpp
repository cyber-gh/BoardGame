#include "PassivePlayer.h"

std::pair<int, int> PassivePlayer::nextPoz() {
	return std::make_pair(poz.first + 1, poz.second + 1);
}

void PassivePlayer::ability() {
	this->speed = ((this->speed % 3) + 1) % 3;
}
