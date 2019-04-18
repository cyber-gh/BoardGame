#pragma once
#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <conio.h>

const unsigned DEFAULT_WAIT_TIME = 6;

class Engine
{
	Map* map;

public:
	Engine() {
		this->map = new Map(20,20,20);
	}

	void play() {

		std::cout << *map;
		std::this_thread::sleep_for(std::chrono::seconds(DEFAULT_WAIT_TIME));
		while (1) {
			system("CLS");
			std::cout << *map;
			map->executeRound();
			std::this_thread::sleep_for(std::chrono::seconds(DEFAULT_WAIT_TIME));
			

			if (_kbhit()) break;

		}
	}


	~Engine() {};
};

