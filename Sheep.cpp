#include<iostream>
#include"Sheep.h"

void Sheep::printing() const
{
	cout << "O";
}

Sheep::Sheep(int x, int y, World* world, int birthTurn)
{
	this->strength = 4;
	this->initiative = 4;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

string Sheep::getSpecies() const
{
	return "Owca";
}

Sheep::~Sheep()
{
	cout << "X" << endl;
}