#pragma once
#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <iostream>       
#include <thread>         
#include <chrono>
#include <conio.h>

const unsigned DEFAULT_WAIT_TIME = 4;

class Engine
{
	Map* map;

public:
	Engine(int nrLines = 20, int nrCols = 20, int nrPlayersEach = 20) {
		this->map = new Map(nrLines, nrCols, nrPlayersEach);
	}

	void play();

	~Engine() { delete map; };
};

