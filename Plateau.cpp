#include "stdafx.h"
#include "Plateau.hpp"
#include <cstdlib>
#include<vector>
#include <iomanip>


Plateau::Plateau() :m_gameState()
{
}

bool Plateau::moveOneColUp(int column, int firstIndex)
{
	bool hasMoved = false;
	int firstEmpty = 4;
	for (int i = firstIndex; i < 4; ++i)
	{
		if (!m_gameState[i][column] && firstEmpty>i)
		{
			firstEmpty = i;
		}
		else if(m_gameState[i][column] && firstEmpty<4)
		{
			m_gameState[firstEmpty][column] = m_gameState[i][column];
			m_gameState[i][column] = 0;
			++firstEmpty;
			hasMoved = true;
		}
	}
	return hasMoved;
}

bool Plateau::moveAndMergeUp()
{
	bool hasMoved = false;
	for (int column = 0; column < 4; ++column)
	{
		hasMoved |= moveOneColUp(column, 0);
		for (int line = 0; line < 3; ++line)
		{
			if (m_gameState[line][column] && m_gameState[line][column] == m_gameState[line+1][column])
			{
				m_gameState[line][column] += m_gameState[line + 1][column];
				m_gameState[line + 1][column] = 0;
				moveOneColUp(column, line);
				hasMoved = true;
			}
		}
	}
	return hasMoved;
}


bool Plateau::moveOneColLeft(int line, int firstIndex)
{
	bool hasMoved = false;
	int firstEmpty = 4;
	for (int j = firstIndex; j < 4; ++j)
	{
		if (!m_gameState[line][j] && firstEmpty>j)
		{
			firstEmpty = j;
		}
		else if (m_gameState[line][j] && firstEmpty<4)
		{
			m_gameState[line][firstEmpty] = m_gameState[line][j];
			m_gameState[line][j] = 0;
			++firstEmpty;
			hasMoved = true;
		}
	}
	return hasMoved;
}

bool Plateau::moveAndMergeLeft()
{
	bool hasMoved = false;
	for (int line = 0; line < 4; ++line)
	{
		hasMoved |= moveOneColLeft(line, 0);
		for (int column = 0; column < 3; ++column)
		{
			if (m_gameState[line][column] && m_gameState[line][column] == m_gameState[line][column + 1])
			{
				m_gameState[line][column] += m_gameState[line][column + 1];
				m_gameState[line][column + 1] = 0;
				moveOneColLeft(line, column);
				hasMoved = true;
			}
		}
	}
	return hasMoved;
}

bool Plateau::moveOneColDown(int column, int firstIndex)
{
	bool hasMoved = false;
	int firstEmpty = -1;
	for (int i = firstIndex; i >= 0; --i)
	{
		if (!m_gameState[i][column] && firstEmpty<i)
		{
			firstEmpty = i;
		}
		else if (m_gameState[i][column] && firstEmpty >-1)
		{
			m_gameState[firstEmpty][column] = m_gameState[i][column];
			m_gameState[i][column] = 0;
			--firstEmpty;
			hasMoved = true;
		}
	}
	return hasMoved;
}

bool Plateau::moveAndMergeDown()
{
	bool hasMoved = false;
	for (int column = 0; column < 4; ++column)
	{
		hasMoved |= moveOneColDown(column, 3);
		for (int line = 3; line > 0; --line)
		{
			if (m_gameState[line][column] && m_gameState[line][column] == m_gameState[line - 1][column])
			{
				m_gameState[line][column] += m_gameState[line - 1][column];
				m_gameState[line - 1][column] = 0;
				moveOneColDown(column, line);
				hasMoved = true;
			}
		}
	}
	return hasMoved;
}

bool Plateau::moveOneColRight(int line, int firstIndex)
{
	bool hasMoved = false;
	int firstEmpty = -1;
	for (int j = firstIndex; j >= 0; --j)
	{
		if (!m_gameState[line][j] && firstEmpty<j)
		{
			firstEmpty = j;
		}
		else if (m_gameState[line][j] && firstEmpty >-1)
		{
			m_gameState[line][firstEmpty] = m_gameState[line][j];
			m_gameState[line][j] = 0;
			--firstEmpty;
			hasMoved = true;
		}
	}
	return hasMoved;
}

bool Plateau::moveAndMergeRight()
{
	bool hasMoved = false;
	for (int line = 0; line < 4; ++line)
	{
		hasMoved |= moveOneColRight(line, 3);
		for (int column = 3; column > 0; --column)
		{
			if (m_gameState[line][column] && m_gameState[line][column] == m_gameState[line][column - 1])
			{
				m_gameState[line][column] += m_gameState[line][column - 1];
				m_gameState[line][column - 1] = 0;
				moveOneColRight(line, column);
				hasMoved = true;
			}
		}
	}
	return hasMoved;
}

void Plateau::print()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << std::setw(5) <<m_gameState[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Plateau::fill1()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_gameState[i][j] = i;
		}
	}
}

void Plateau::fill2()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_gameState[i][j] = 2*j;
		}
	}
}

void Plateau::fill3()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_gameState[i][j] = 2 * i;
		}
	}
}

bool Plateau::fill()
{
	int probaValue = std::rand() % 10;
	int caseAjoutee = (probaValue == 0) ? 4 : 2;
	std::vector<std::pair<int, int> > casesVides;
	for (int line = 0; line < 4; ++line)
	{
		for (int column = 0; column < 4; ++column)
		{
			if (!m_gameState[line][column])
			{
				casesVides.push_back(std::make_pair(line, column));
			}
		}

	}
	if (casesVides.empty())
	{
		return true;
	}
	int caseToChange = std::rand() % casesVides.size();
	m_gameState[casesVides[caseToChange].first][casesVides[caseToChange].second] = caseAjoutee;
	return false;
}

Plateau::~Plateau()
{
}
