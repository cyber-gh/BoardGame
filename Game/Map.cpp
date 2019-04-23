#include "Map.h"





std::ostream& operator<<(std::ostream& os, const Map& mp) {
	for (int i = 0; i < mp.nrLines; i++) {
		for (int j = 0; j < mp.nrCols; j++) {
			os << std::setw(2) << (mp.board[i][j] == -1 ? 0: mp.board[i][j]);
			os << " ";
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

inline std::pair<int, int> Map::randomValidPosition() {
	std::pair<int, int> poz;
	do {
		poz = std::make_pair(rand() % nrLines, rand() % nrCols);
	} while (board[poz.first][poz.second] != -1);
	return poz;
}

inline bool Map::isValidPosition(std::pair<int, int> poz) {
	return poz.first >= 0 && poz.first < nrLines && poz.second >= 0 && poz.second < nrCols;
}

inline void Map::initializeMatrix() {

	board = new int* [nrLines];
	for (int i = 0; i < nrLines; i++) board[i] = new int[nrCols];

	for (int i = 0; i < nrLines; i++)
		for (int j = 0; j < nrCols; j++) board[i][j] = -1;
}

inline void Map::generatePlayers(int numberOfPlayersOfEachType) {
	int id = 0; //code duplication, might use templates
	for (int steps = numberOfPlayersOfEachType; steps--; nrPlayers++) {
		std::pair<int, int> playerPoz = randomValidPosition();
		board[playerPoz.first][playerPoz.second] = id;
		res.push_back(new AgressivePlayer(playerPoz, id++));
	}
	for (int steps = numberOfPlayersOfEachType; steps--; nrPlayers++) {
		std::pair<int, int> playerPoz = randomValidPosition();
		board[playerPoz.first][playerPoz.second] = id;
		res.push_back(new PassivePlayer(playerPoz, id++));
	}

	for (int steps = numberOfPlayersOfEachType; steps--; nrPlayers++) {
		std::pair<int, int> playerPoz = randomValidPosition();
		board[playerPoz.first][playerPoz.second] = id;
		res.push_back(new RandomPlayer(playerPoz, id++));
	}
	for (int steps = numberOfPlayersOfEachType; steps--; nrPlayers++) {
		std::pair<int, int> playerPoz = randomValidPosition();
		board[playerPoz.first][playerPoz.second] = id;
		res.push_back(new CasualPlayer(playerPoz, id++));
	}
}

Map::Map(int nrLines, int nrCols, int numberOfPlayersEach) {

	srand(time(NULL));
	this->nrLines = nrLines;
	this->nrCols = nrCols;
	initializeMatrix();
	nrPlayers = 0;
	generatePlayers(numberOfPlayersEach);
}

 Map::~Map() {
	for (int i = 0; i < nrLines; i++) delete board[i];
	delete board;
}

 void Map::playRound() {
	 std::setw(3);
	 for (auto it : res) {
		 if (it->isDead) {
			 board[it->poz.first][it->poz.second] = -1;
			 continue;
		 }
		 for (int i = it->speed; i--;) {
			 std::pair<int, int> nxt = it->nextPoz();
			 if (isValidPosition(nxt)) {
				 if (board[nxt.first][nxt.second] != -1) {
					 Player* other = res[board[nxt.first][nxt.second]];
					 fight(*it, *other);
					 if (it->isDead && other->isDead) {
						 board[it->poz.first][it->poz.second] = -1;
						 board[other->poz.first][other->poz.second] = -1;
						 break;
					 }
					 else if (it->isDead) {
						 nrPlayers--;
						 board[it->poz.first][it->poz.second] = -1;
						 std::cout << "Player " << it->identifier << " dead" << " -- killed by Player " <<
							 other->identifier << std::endl;
						 break;
					 }
					 else if (other->isDead) {
						 nrPlayers--;
						 board[it->poz.first][it->poz.second] = -1;
						 board[nxt.first][nxt.second] = it->identifier;
						 it->poz = nxt;
						 std::cout << "Player " << other->identifier << " dead" <<
							 " -- killed by Player " << it->identifier << std::endl;

					 }
				 }
				 else {
					 board[it->poz.first][it->poz.second] = -1;
					 board[nxt.first][nxt.second] = it->identifier;
					 it->poz = nxt;
				 }
			 }
			 else {
				 nrPlayers--;
				 it->isDead = true;
				 board[it->poz.first][it->poz.second] = -1;
				 std::cout << "Player " << it->identifier << " suicide -- tried to leave the map" << std::endl;
				 break;
			 }
		 }
	 }
 }
