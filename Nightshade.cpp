#include<iostream>
#include"Nightshade.h"

void Nightshade::printing() const
{
	cout << "J";
}

Nightshade::Nightshade(int x, int y, World* world, int birthTurn)
{
	this->strength = 99;
	this->initiative = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

string Nightshade::getSpecies() const
{
	return "WilczeJagody";
}