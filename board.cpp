#include "board.h"

board::board()
{
	for (int i = 0; i < 7; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			if(i % 2 == 0)
			{
				if(j % 4 == 0)
					this->boardChar[i][j] = ' ';
				else 
					this->boardChar[i][j] = '-';
			}
			else
			{
				if (j % 4 == 0)
					this->boardChar[i][j] = '|';
				else
					this->boardChar[i][j] = ' ';
			}
		}
	}
		
}

void board::showBoard()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << this->boardChar[i][j];
		}
		cout << endl;
	}
}

void board::addMove(char player, int dimY, int dimX)
{
	this->boardChar[dimX][dimY] = player;
}
