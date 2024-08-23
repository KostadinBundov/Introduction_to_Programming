#include <iostream>

constexpr size_t rows = 6;
constexpr size_t colls = 5;

bool areValidCoordinates(bool visitedCells[rows][colls], int x, int y)
{
    if (x < 0 || x >= rows || y < 0 || y >= colls)
    {
        return false;
    }

    if (visitedCells[x][y])
    {
        return false;
    }

    return true;
}

void printTrace(const char field[rows][colls], const bool visited[rows][colls])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colls; j++)
        {
            if (visited[i][j])
                std::cout << "| 1 |";
            else
                std::cout << "| " << field[i][j] << " |";
        }
        std::cout << std::endl;
    }
}


bool findTrace(const char maze[rows][colls], bool visitedCells[rows][colls], int x, int y, int endX, int endY)
{
    if (!areValidCoordinates(visitedCells, x, y) || maze[x][y] == 'X')
    {
        return false;
    }

    visitedCells[x][y] = true;

    if (x == endX && y == endY)
    {
        return true;
    }

    bool foundTrace = findTrace(maze, visitedCells, x + 1, y, endX, endY) ||
        findTrace(maze, visitedCells, x, y + 1, endX, endY) ||
        findTrace(maze, visitedCells, x - 1, y, endX, endY) ||
        findTrace(maze, visitedCells, x, y - 1, endX, endY);

    if (!foundTrace)
    {
        visitedCells[x][y] = false;
    }

    return foundTrace;
}

int main()
{
    char field[rows][colls] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X'},
        {'X', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' '}
    };

    bool visitedCells[rows][colls] = { false };

    bool result = findTrace(field, visitedCells, 3, 0, 5, 4);

    if (result)
    {
        printTrace(field, visitedCells);
    }
    else
    {
        std::cout << "No path found!";
    }

    return 0;
}
