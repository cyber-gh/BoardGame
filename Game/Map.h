#pragma once
#include "IMap.h"
#include "AgressivePlayer.h"
#include "PassivePlayer.h"
#include "RandomPlayer.h"
#include "CasualPlayer.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <random>
#include <time.h>

class Map :
	public IMap
{
	int** board;
	int nrLines, nrCols;
	std::vector<Player*> res;

	virtual std::pair<int, int> randomValidPosition() {
		std::pair<int, int> poz;
		do {
			poz = std::make_pair(rand() % nrLines, rand() % nrCols);
		} while (board[poz.first][poz.second] != -1);
		return poz;
	}

	bool isValidPosition(std::pair<int, int> poz) {
		return poz.first >= 0 && poz.first < nrLines && poz.second >= 0 && poz.second < nrCols;
	}

	void initializeMatrix() {

		board = new int* [nrLines];
		for (int i = 0; i < nrLines; i++) board[i] = new int[nrCols];

		for (int i = 0; i < nrLines; i++)
			for (int j = 0; j < nrCols; j++) board[i][j] = -1;
	}

	void generatePlayers(int numberOfPlayersOfEachType) {
		int id = 0;
		for (int steps = numberOfPlayersOfEachType; steps--;) {
			std::pair<int, int> playerPoz = randomValidPosition();
			board[playerPoz.first][playerPoz.second] = id;
			res.push_back(new AgressivePlayer(playerPoz, id++));
		}
		for (int steps = numberOfPlayersOfEachType; steps--;) {
			std::pair<int, int> playerPoz = randomValidPosition();
			board[playerPoz.first][playerPoz.second] = id;
			res.push_back(new PassivePlayer(playerPoz, id++));
		}

		for (int steps = numberOfPlayersOfEachType; steps--;) {
			std::pair<int, int> playerPoz = randomValidPosition();
			board[playerPoz.first][playerPoz.second] = id;
			res.push_back(new RandomPlayer(playerPoz, id++));
		}
		for (int steps = numberOfPlayersOfEachType; steps--;) {
			std::pair<int, int> playerPoz = randomValidPosition();
			board[playerPoz.first][playerPoz.second] = id;
			res.push_back(new CasualPlayer(playerPoz, id++));
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Map& mp);

public:

	virtual bool inRange(std::pair<int, int> poz) {
		return true;
	}
	
	virtual bool movePiece(std::pair<int, int> from, std::pair<int, int> to) {
		//TODO check collision
		if (!isValidPosition(to)) return false;
		if (board[to.first][to.second] != -1) return false;
		board[to.first][to.second] = board[from.first][from.second];
		board[from.first][from.second] = -1;
		return true;
	}
	virtual int getClosestPiece(std::pair<int, int> poz) const {
		return 1;
	}

	void executeRound() {
		for (auto it : res) {
			if (it->isDead) continue;
			for (int i = it->speed; i--;) {
				std::pair<int, int> nxt = it->nextPoz();
				if (movePiece(it->poz, nxt)) it->poz = nxt;
				else if (isValidPosition(nxt) && board[nxt.first][nxt.second] != -1) {
					Player& other = *res[board[nxt.first][nxt.second]];
					fight(*it, other);
					if (it->isDead) {
						std::cout << "Player " << it->identifier << " dead" << std::endl;
						board[it->poz.first][it->poz.second] = -1;
					}
					if (other.isDead) {
						std::cout << "Player " << other.identifier << " dead" << std::endl;
						board[other.poz.first][other.poz.second] = -1;
					}
				}
			}
			it->ability();

		}
	}



	Map(int nrLines = 15, int nrCols = 15, int numberOfPlayersEach = 5) {

		srand(time(NULL));
		this->nrLines = nrLines;
		this->nrCols = nrCols;
		initializeMatrix();
		generatePlayers(numberOfPlayersEach);
	}
	~Map() {
		for (int i = 0; i < nrLines; i++) delete board[i];
		delete board;
	}
};

