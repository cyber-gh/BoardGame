#pragma once
#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <conio.h>

const unsigned DEFAULT_WAIT_TIME = 1;

class Engine
{
	Map* map;

public:
	Engine(int nrLines = 20, int nrCols = 20, int nrPlayersEach = 20) {
		this->map = new Map(nrLines, nrCols, nrPlayersEach);
	}

	void play();

	~Engine() {};
};

