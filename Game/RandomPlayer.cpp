#include "RandomPlayer.h"

std::pair<int, int> RandomPlayer::nextPoz() {
	return std::make_pair(poz.first - 1, poz.second - 1);
}

void RandomPlayer::ability() {
	this->isVisible = !this->isVisible;
}
