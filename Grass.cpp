#include<iostream>
#include"Grass.h"

void Grass::printing() const
{
	cout << "T";
}

Grass::Grass(int x, int y, World* world, int birthTurn)
{
	this->strength = 0;
	this->initiative = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

string Grass::getSpecies() const
{
	return "Trawa";
}