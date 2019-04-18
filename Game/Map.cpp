#include "Map.h"
#include <iomanip>




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