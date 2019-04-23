#include "AgressivePlayer.h"

std::pair<int, int> AgressivePlayer::nextPoz() {
	return std::make_pair(poz.first - 1, poz.second - 1);
}

void AgressivePlayer::ability() {
	this->damage += 5;
}
