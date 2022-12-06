#include <iostream>
#include <string>
using namespace std;

class board
{
public:
	char boardChar[7][13];
	int moves = 0;
	board();
	void showBoard();
	void addMove(char player, int dimX, int dimY);
};

