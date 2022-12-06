#include "board.h"

void showMenu();
int checkDimX(int dimX);
int checkDimY(int dimY);
int checkRules(board gameBoard);
void humanVShuman (board gameBoard, int winCond);
void humanVSpc (board gameBoard, int winCond);

int main()
{
    board gameBoard;
    int winCond = 0;
    
    int mainController = 1;

    while (mainController)
    {

        showMenu();
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            winCond = 1;
            system("cls");
            gameBoard.showBoard();
            humanVShuman(gameBoard, winCond);
            break;
        case 2:
            winCond = 1;
            system("cls");
            gameBoard.showBoard();
            humanVSpc(gameBoard, winCond);
            break;
        case 3:
            system("cls");
            mainController = 0;
            cout << "Bye, bye!" << endl;
            break;
        default:
            system("cls");
            cout << "I don't get it, try again." << endl << endl;
        }    
    }
}


void showMenu()
{
    cout << "Welcome in Tic Tac Toe game!" << endl;
    cout << "What would you like to do?" << endl; 
    cout << "1. Start human vs human." << endl;
    cout << "2. Start human vs PC." << endl;
    cout << "3. Quit game." << endl;
}

int checkDimX(int dimX)
{
    if (dimX == 1)
        dimX = 2;
    else if (dimX == 2)
        dimX = 6;
    else if (dimX == 3)
        dimX = 10;
    return dimX;
}

int checkDimY(int dimY)
{
    if (dimY == 1)
        dimY = 1;
    else if (dimY == 2)
        dimY = 3;
    else if (dimY == 3)
        dimY = 5;
    return dimY;
}

int checkRules(board gameBoard)
{
    //horizontal wins
    if ((gameBoard.boardChar[1][2] == 'X' && gameBoard.boardChar[1][6] == 'X' && gameBoard.boardChar[1][10] == 'X')
        || (gameBoard.boardChar[3][2] == 'X' && gameBoard.boardChar[3][6] == 'X' && gameBoard.boardChar[3][10] == 'X')
        || (gameBoard.boardChar[5][2] == 'X' && gameBoard.boardChar[5][6] == 'X' && gameBoard.boardChar[5][10] == 'X'))
    {
        cout << "Player X won!" << endl << endl;
        return 0;
    }
    else if ((gameBoard.boardChar[1][2] == 'O' && gameBoard.boardChar[1][6] == 'O' && gameBoard.boardChar[1][10] == 'O')
            || (gameBoard.boardChar[3][2] == 'O' && gameBoard.boardChar[3][6] == 'O' && gameBoard.boardChar[3][10] == 'O')
            || (gameBoard.boardChar[5][2] == 'O' && gameBoard.boardChar[5][6] == 'O' && gameBoard.boardChar[5][10] == 'O'))
    {
        cout << "Player O won!" << endl << endl;
        return 0;
    }
    //vertical wins
    else if ((gameBoard.boardChar[1][2] == 'X' && gameBoard.boardChar[3][2] == 'X' && gameBoard.boardChar[5][2] == 'X') 
        || (gameBoard.boardChar[1][6] == 'X' && gameBoard.boardChar[3][6] == 'X' && gameBoard.boardChar[5][6] == 'X')
        || (gameBoard.boardChar[1][10] == 'X' && gameBoard.boardChar[3][10] == 'X' && gameBoard.boardChar[5][10] == 'X'))
    {
        cout << "Player X won!" << endl << endl;
        return 0;
    }
    else if ((gameBoard.boardChar[1][2] == 'O' && gameBoard.boardChar[3][2] == 'O' && gameBoard.boardChar[5][2] == 'O')
        || (gameBoard.boardChar[1][6] == 'O' && gameBoard.boardChar[3][6] == 'O' && gameBoard.boardChar[5][6] == 'O')
        || (gameBoard.boardChar[1][10] == 'O' && gameBoard.boardChar[3][10] == 'O' && gameBoard.boardChar[5][10] == 'O'))
    {
        cout << "Player O won!" << endl << endl;
        return 0;
    }
    //cross wins 
    else if ((gameBoard.boardChar[1][2] == 'X' && gameBoard.boardChar[3][6] == 'X' && gameBoard.boardChar[5][10] == 'X')
        || (gameBoard.boardChar[1][10] == 'X' && gameBoard.boardChar[3][6] == 'X' && gameBoard.boardChar[5][2] == 'X'))
    {
        cout << "Player X won!" << endl << endl;
        return 0;
    }
    else if ((gameBoard.boardChar[1][2] == 'O' && gameBoard.boardChar[3][6] == 'O' && gameBoard.boardChar[5][10] == 'O')
        || (gameBoard.boardChar[1][10] == 'O' && gameBoard.boardChar[3][6] == 'O' && gameBoard.boardChar[5][2] == 'O'))
    {
        cout << "Player O won!" << endl << endl;
        return 0;
    }
    //draw
    else if (gameBoard.moves == 9)
    {
        cout << "It's a draw!" << endl << endl;
        return 0;
    }
}

void humanVShuman(board gameBoard, int winCond)
{
    int dimX, dimY;

    while (winCond)
    {
        //Player X move
        while (1)
        {
            cout << "Provide X move:" << endl;
            cout << "X: ";
            cin >> dimX;
            cout << "Y: ";
            cin >> dimY;

            if ((dimX == 1 || dimX == 2 || dimX == 3) && (dimY == 1 || dimY == 2 || dimY == 3))
            {
                dimX = checkDimX(dimX);
                dimY = checkDimY(dimY);
                if (gameBoard.boardChar[dimY][dimX] != ' ')
                    cout << "This place is already taken! Do another move!" << endl;
                else
                    break;
            }
            else
                cout << "Wrong coordinates! You can use 1, 2 or 3 for both: X and Y. Try again..." << endl;
        }


        gameBoard.addMove('X', dimX, dimY);
        gameBoard.moves++;
        system("cls");
        winCond = checkRules(gameBoard);
        if (winCond == 0)
            break;
        gameBoard.showBoard();

        //Player O move
        while (1)
        {
            cout << "Provide O move:" << endl;
            cout << "X: ";
            cin >> dimX;
            cout << "Y: ";
            cin >> dimY;

            if ((dimX == 1 || dimX == 2 || dimX == 3) && (dimY == 1 || dimY == 2 || dimY == 3))
            {
                dimX = checkDimX(dimX);
                dimY = checkDimY(dimY);
                if (gameBoard.boardChar[dimY][dimX] != ' ')
                    cout << "This place is already taken! Do another move!" << endl;
                else
                    break;
            }
            else
                cout << "Wrong coordinates! You can use 1, 2 or 3 for both: X and Y. Try again..." << endl;
        }

        gameBoard.addMove('O', dimX, dimY);
        gameBoard.moves++;
        system("cls");
        winCond = checkRules(gameBoard);
        if (winCond == 0)
            break;
        gameBoard.showBoard();
    }
}

void humanVSpc(board gameBoard, int winCond)
{
    int dimX, dimY;

    while (winCond)
    {
        //Player X move - human
        while (1)
        {
            cout << "Provide X move:" << endl;
            cout << "X: ";
            cin >> dimX;
            cout << "Y: ";
            cin >> dimY;

            if ((dimX == 1 || dimX == 2 || dimX == 3) && (dimY == 1 || dimY == 2 || dimY == 3))
            {
                dimX = checkDimX(dimX);
                dimY = checkDimY(dimY);
                if (gameBoard.boardChar[dimY][dimX] != ' ')
                    cout << "This place is already taken! Do another move!" << endl;
                else
                    break;
            }
            else
                cout << "Wrong coordinates! You can use 1, 2 or 3 for both: X and Y. Try again..." << endl;
        }


        gameBoard.addMove('X', dimX, dimY);
        gameBoard.moves++;
        system("cls");
        winCond = checkRules(gameBoard);
        if (winCond == 0)
            break;
        gameBoard.showBoard();

        //Player O move - PC
        while (1)
        {
            srand(time(NULL));
            dimX = (rand() % 3) + 1;
            dimY = (rand() % 3) + 1;

            if ((dimX == 1 || dimX == 2 || dimX == 3) && (dimY == 1 || dimY == 2 || dimY == 3))
            {
                dimX = checkDimX(dimX);
                dimY = checkDimY(dimY);
                if (gameBoard.boardChar[dimY][dimX] == ' ')
                    break;
            }
        }

        gameBoard.addMove('O', dimX, dimY);
        gameBoard.moves++;
        system("cls");
        winCond = checkRules(gameBoard);
        if (winCond == 0)
            break;
        gameBoard.showBoard();
    }
}
