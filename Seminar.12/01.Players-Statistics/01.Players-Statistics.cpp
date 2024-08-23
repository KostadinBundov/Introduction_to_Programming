#include <iostream>

int** createBoard(int rows)
{
	int** board = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		std::cout << "Team " << i + 1 << " players count: " << std::endl;
		int cols;
		std::cin >> cols;

		board[i] = new int[cols + 2] {0};
		board[i][1] = cols;
	}

	return board;
}

void free(int** board, size_t rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}

	delete[] board;
}

void print(int** board, size_t rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < board[i][1]; j++)
		{
			std::cout << board[i][j + 2] << " ";
		}

		std::cout << std::endl;
	}
}

void swap(int*& first, int*& second)
{
	int* temp = first;
	first = second;
	second = temp;
}

void reorderTeams(int** board, int currentTeam)
{
	while (currentTeam > 0)
	{
		if (board[currentTeam][0] > board[currentTeam - 1][0])
		{
			swap(board[currentTeam], board[currentTeam - 1]);
		}

		currentTeam--;
	}
}

void addPoints(int** board, int row, int col, int points)
{
	board[row][col + 2] += points;
	board[row][0] += points;

	reorderTeams(board, row);
}

int main()
{
	std::cout << "Teams Count:" << std::endl;
	int rows;
	std::cin >> rows;

	int** board = createBoard(rows);

	print(board, rows);

	std::cout << "Commands Count:" << std::endl;
	int commandsCount;
	std::cin >> commandsCount;

	for (int i = 0; i < commandsCount; i++)
	{
		int row, col, points;
		std::cin >> row >> col >> points;

		addPoints(board, row, col, points);
		print(board, rows);
	}
}

//#include <iostream>
//using namespace std;
//
////each rows have two "system" variables.
////[0] is the count of the elements in the row
////[1] is the sum of the elements of the row 
//int** createMatrix(int rows)
//{
//	int** mtx = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		int colls;
//		cin >> colls;
//
//		mtx[i] = new int[colls + 2] {0};
//		mtx[i][0] = colls;
//	}
//	return mtx;
//}
//
//void freeMatrix(int** matrix, int rows)
//{
//	for (int i = 0; i < rows; i++)
//		delete[] matrix[i];
//	delete[] matrix;
//}
//
//void print(int** mtx, int rows)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		int sizeOfRow = mtx[i][0];
//		for (int j = 2; j < sizeOfRow + 2; j++)
//			cout << mtx[i][j] << ' ';
//		cout << endl;
//	}
//}
//
//void swap(int*& first, int*& second)
//{
//	int* temp = first;
//	first = second;
//	second = temp;
//}
//
//void moveTheRowToTheCorrectPosition(int** mtx, int lastModifedRow)
//{
//	int current = lastModifedRow;
//
//	while (current > 0 && mtx[current][1] > mtx[current - 1][1])
//	{
//		swap(mtx[current], mtx[current - 1]);
//		current--;
//	}
//}
//
//void addPoints(int** mtx, int row, int coll, int point)
//{
//	mtx[row][coll + 2] += point;
//	mtx[row][1] += point;
//	moveTheRowToTheCorrectPosition(mtx, row);
//}
//
//int main()
//{
//	int rows;
//	cin >> rows;
//
//	int** mtx = createMatrix(rows);
//
//	print(mtx, rows);
//
//	int queriesCount;
//	cin >> queriesCount;
//
//	for (int i = 0; i < queriesCount; i++)
//	{
//		int row, coll, points;
//		cin >> row >> coll >> points;
//		addPoints(mtx, row, coll, points);
//		print(mtx, rows);
//	}
//
//	print(mtx, rows);
//
//	freeMatrix(mtx, rows);
//}