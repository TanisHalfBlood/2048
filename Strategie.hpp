#pragma once
#include "Plateau.hpp"

class Strategie
{
public:
	Strategie(const Plateau &initialState);
	Move computeBestMove();
	~Strategie();
private:
	Plateau m_initialState;
	Move naiveStrat();
};

