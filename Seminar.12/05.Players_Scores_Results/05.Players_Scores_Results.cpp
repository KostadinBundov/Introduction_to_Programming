#include <iostream>

constexpr size_t MAX_PLAYERS_COUNT = 10;
constexpr size_t MAX_PLAYER_NAME_LENGTH = 1024;

void swap(char*& first, char*& second)
{
	char* temp = first;
	first = second;
	second = temp;
}

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return length;
}

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return 0;
	}

	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	return *first - *second;
}

void copyName(const char* str, char* name, size_t index)
{
	for (int i = 0; i < index; i++)
	{
		name[i] = str[i];
	}
}

void input(char** players, size_t index)
{
	char name[MAX_PLAYER_NAME_LENGTH];
	std::cin.getline(name, MAX_PLAYER_NAME_LENGTH);

	size_t nameLength = myStrlen(name);
	players[index] = new char[nameLength + 1];
	players[index][nameLength] = '\0';
	copyName(name, players[index], nameLength);
}

int getPlayerIndeex(char** players, const char* player)
{
	if (!player)
	{
		return - 1;
	}

	int index = 0;

	while (*players)
	{
		if (myStrcmp(*players, player) == 0)
		{
			return index;
		}

		index++;
		players++;
	}

	return -1;
}

void reorderPlayers(char** players, int* scores, int lastChangedPlayerIndex)
{
	while (lastChangedPlayerIndex > 0)
	{
		if (scores[lastChangedPlayerIndex] > scores[lastChangedPlayerIndex - 1])
		{
			swap(players[lastChangedPlayerIndex], players[lastChangedPlayerIndex - 1]);
			swap(scores[lastChangedPlayerIndex], scores[lastChangedPlayerIndex - 1]);
		}

		lastChangedPlayerIndex--;
	}
}

void addPoints(char** players, const char* player, int points, int* scores)
{
	if (!player)
	{
		return;
	}

	int playerIndex = getPlayerIndeex(players, player);

	if (playerIndex == -1)
	{
		return;
	}

	scores[playerIndex] += points;

	reorderPlayers(players, scores, playerIndex);
}

void print(char** players, const int* scores, size_t playersCount)
{
	for (int i = 0; i < playersCount; i++)
	{
		std::cout << players[i] << " " << scores[i] << std::endl;
	}
}

void free(char** players)
{
	size_t index = 0;

	while (*players)
	{
		delete[] players[index++];
		players++;
	}
}

int main()
{
	char* players[MAX_PLAYERS_COUNT]{ nullptr };
	int scores[MAX_PLAYERS_COUNT]{ 0 };

	size_t playersCount;
	std::cin >> playersCount;

	std::cin.ignore();

	for (int i = 0; i < playersCount; i++)
	{
		input(players, i);
	}

	int scoresCount;
	std::cin >> scoresCount;

	std::cin.ignore();

	for (int i = 0; i < scoresCount; i++)
	{
		char name[MAX_PLAYER_NAME_LENGTH];
		std::cin.getline(name, MAX_PLAYER_NAME_LENGTH);

		int points;
		std::cin >> points;
		std::cin.ignore();

		addPoints(players, name, points, scores);
		print(players, scores, playersCount);
	}

	free(players);
}