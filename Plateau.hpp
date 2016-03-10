#pragma once

#include<iostream>
#include<cstdlib>

enum Move
{
	up,
	down,
	left,
	right,
	none
};


class Plateau
{
public:
	Plateau();
	bool moveOneColUp(int column, int firstIndex);
	bool moveAndMergeUp();

	bool moveOneColDown(int column, int firstIndex);//mettre template à la place.
	bool moveAndMergeDown();

	bool moveOneColLeft(int line, int firstIndex);
	bool moveAndMergeLeft();

	bool moveOneColRight(int line, int firstIndex);
	bool moveAndMergeRight();
	void print();
	//TODO put in a test file
	void fill1();

	void fill2();

	void fill3();

	bool fill();
	
	~Plateau();
private:
	// column, line
	int m_gameState[4][4];
};

