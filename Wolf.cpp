#include <iostream>
#include "Wolf.h"

void Wolf::printing() const
{
	cout << "W";
}

Wolf::Wolf(int x, int y, World* world, int birthTurn)
{
	this->strength = 9;
	this->initiative = 5;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

string Wolf::getSpecies() const
{
	return "Wilk";
}