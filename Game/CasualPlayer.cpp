#include "CasualPlayer.h"

 std::pair<int, int> CasualPlayer::nextPoz() {
	return std::make_pair(poz.first - 1, poz.second + 1);
}


 void CasualPlayer::ability() {
	this->armor += 10;
}
