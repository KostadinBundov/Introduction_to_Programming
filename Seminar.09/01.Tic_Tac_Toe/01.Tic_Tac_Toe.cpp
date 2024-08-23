#include <iostream>

constexpr char FIRST_PLAYER = 'X';
constexpr char SECOND_PLAYER = 'O';
char currentPlayer = SECOND_PLAYER;

constexpr size_t BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void printBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == '\0')
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << board[i][j] << " ";
			}
		}

		std::cout << std::endl;
	}
}

bool isValidPosition(int x, int y)
{
	return (0 <= x && x <= 2) && (0 <= y && y <= 2) && board[x][y] == '\0';
}

void takeInput(int& x, int& y)
{
	do
	{
		std::cout << "Enter position: " << std::endl;
		std::cin >> x >> y;
	} while (!isValidPosition(x, y));

	board[x][y] = currentPlayer;
}

void changePlayer()
{
	currentPlayer = (currentPlayer == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
}

bool checkRows()
{
	bool winner;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		winner = true;

		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] != currentPlayer)
			{
				winner = false;
				break;
			}
		}

		if (winner)
		{
			break;
		}
	}

	return winner;
}

bool checkColumns()
{
	bool winner;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		winner = true;

		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[j][i] != currentPlayer)
			{
				winner = false;
				break;
			}
		}

		if (winner)
		{
			break;
		}
	}

	return winner;
}

bool checkSecondDiagonal()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (i + j == BOARD_SIZE - 1 && board[i][j] != currentPlayer)
			{
				return false;
			}
		}
	}

	return true;
}

bool checkMainDiagonal()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (i == j && board[i][j] != currentPlayer)
			{
				return false;
			}
		}
	}

	return true;
}

bool checkDiagonals()
{
	return checkMainDiagonal() || checkSecondDiagonal();
}

bool checkForWinner()
{
	return checkRows() || checkColumns() || checkDiagonals();
}

void play()
{
	bool gameOver = false;
	unsigned turns = 0;

	int x, y;

	while (!gameOver && turns <= 9)
	{
		changePlayer();
		std::cout << "Player " << currentPlayer << " turn:" << std::endl;

		takeInput(x, y);
		printBoard();

		if (turns >= 3)
		{
			gameOver = checkForWinner();
		}

		turns++;
	}

	if (gameOver)
	{
		std::cout << currentPlayer << " win!" << std::endl;
	}
	else
	{
		std::cout << "Draw!" << std::endl;
	}
}

int main()
{
	play();
}