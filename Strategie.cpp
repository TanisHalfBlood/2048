#include "stdafx.h"
#include "Strategie.hpp"


Strategie::Strategie(const Plateau &p) : m_initialState(p)
{
}

Move Strategie::naiveStrat()
{
	Plateau temp(m_initialState);
	if (temp.moveAndMergeDown())
	{
		return Move::down;
	}
	else if (temp.moveAndMergeRight())
	{
		return Move::right;
	}
	else if (temp.moveAndMergeLeft())
	{
		return Move::left;
	}
	else if (temp.moveAndMergeUp())
	{
		return Move::up;
	}
	else
		return Move::none;
}

Move Strategie::computeBestMove()
{
	return naiveStrat();
}


Strategie::~Strategie()
{
}
