#include "Engine.h"

void Engine::play() {

	std::cout << *map;
	std::this_thread::sleep_for(std::chrono::seconds(DEFAULT_WAIT_TIME));
	int roundNr = 1;
	while (1) {
		system("CLS");
		
		std::cout << "------------------  ROUND " << roundNr++ << "  ---------------------" << std::endl;
		map->playRound();
		std::cout << *map;
		std::this_thread::sleep_for(std::chrono::seconds(DEFAULT_WAIT_TIME));
		if (map->getNrPlayers() <= 0) {
			std::cout << "-------------Game finished---------------";
			return;
		}
		if (_kbhit()) break;

	}
}
