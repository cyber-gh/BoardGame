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
#include <iomanip>

class Map :
	public IMap
{
	int** board;
	int nrLines, nrCols;
	std::vector<Player*> res;

	int nrPlayers;

	virtual std::pair<int, int> randomValidPosition();

	bool isValidPosition(std::pair<int, int> poz);

	void initializeMatrix();

	void generatePlayers(int numberOfPlayersOfEachType);

	friend std::ostream& operator<<(std::ostream& os, const Map& mp);

public:

	virtual bool inRange(std::pair<int, int> poz) {
		return true;
	}
	
	virtual bool movePiece(std::pair<int, int> from, std::pair<int, int> to) {}
	virtual int getClosestPiece(std::pair<int, int> poz) const {
		return 1;
	}


	int getNrPlayers() {
		return nrPlayers;
	}

	Map(int nrLines = 15, int nrCols = 15, int numberOfPlayersEach = 5);
	~Map();

	void playRound();
};

