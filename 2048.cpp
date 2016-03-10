// 2048.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Plateau.hpp"
#include "Strategie.hpp"
#include<cstdlib>
#include <ctime>
#include<conio.h>

static void vider_buffer()
{
	std::cin.clear();
	std::cin.seekg(0, std::ios::end);
	if (!std::cin.fail())
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	else
	{
		std::cin.clear();
	}
}

//TODO list : 
/* 
	brancher la fonction naive de stratégie pour que l'IA puisse jouer.
	écrire une fonction d'évaluation :
		classique (somme des nombres présents)
		importance accrue aux coins
		importance accrue aux coins et aux bords
		importance accrue aux séries (nombres consécutifs pouvant contribuer à augmenter le plus élevé d'un rang).



	ecrire une classe PlateauTheorique qui prenne en compte la probabilité qu'une case soit apparue ou pas (
		Adapter les fonctions de move en conséquence
		adapter la fonction d'évaluation
		faire une stratégie qui puisse évaluer n coups.


	Optimiser les stratégies.
*/

int main()
{
	
	std::srand(std::time(0));
	Plateau p;
	char direction;
	bool isOver = false;
	while (!isOver)
	{
		isOver = p.fill();
		p.print();
		std::cout << "Choisissez une direction : z, q, s ou d" << std::endl;
		bool isCoupValid = false;
		while (!isCoupValid && !isOver)
		{
			char direction = getchar();
			if (direction == 'p')
			{
				Strategie s(p);
				Move computerMove = s.computeBestMove();
				switch (computerMove)
				{
				case up:
					isCoupValid = p.moveAndMergeUp();
					break;
				case down:
					isCoupValid = p.moveAndMergeDown();
					break;
				case left:
					isCoupValid = p.moveAndMergeLeft();
					break;
				case right:
					isCoupValid = p.moveAndMergeRight();
					break;
				case none:
					isOver = true;
				}
				continue;
			}
			switch (direction)
			{
			case'z':
				isCoupValid = p.moveAndMergeUp();
				break;
			case's':
				isCoupValid = p.moveAndMergeDown();
				break;
			case'q':
				isCoupValid = p.moveAndMergeLeft();
				break;
			case'd':
				isCoupValid = p.moveAndMergeRight();
				break; 
			}
		}
	}
	std::cout << "Tu as perdu !!!" << std::endl;
    return 0;
}

