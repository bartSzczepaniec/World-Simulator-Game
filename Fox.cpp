#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Fox.h"
#include "World.h"

Fox::Fox(int x, int y, World* world, int birthTurn)
{
	this->strength = 3;
	this->initiative = 7;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

void Fox::printing() const
{
	cout << "L";
}

string Fox::getSpecies() const
{
	return "Lis";
}

void Fox::action()
{
	int directions[4] = { 0 }; // sprawdzenie sasiadow, w poszukiwaniu wolnego miejsca lub takiego na ktorym stoi slabszy organizm
	int allowed_directions = 0;
	Organism* neighbour=nullptr;
	if (this->getY() > 0)
	{
		// góra TAK
		neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() - 1);
		if (neighbour == nullptr)
			directions[allowed_directions++] = 0;
		else if(neighbour->getStrength()<=this->strength)
			directions[allowed_directions++] = 0;
	}
	if (this->getY() < this->world->getN() - 1)
	{
		// dó³ TAK
		neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() + 1);
		if (neighbour == nullptr)
			directions[allowed_directions++] = 1;
		else if (neighbour->getStrength() <= this->strength)
			directions[allowed_directions++] = 1;
	}
	if (this->getX() > 0)
	{
		//lewo TAK
		neighbour = this->getWorld()->getOrganism(this->getX() - 1, this->getY());
		if (neighbour == nullptr)
			directions[allowed_directions++] = 2;
		else if (neighbour->getStrength() <= this->strength)
			directions[allowed_directions++] = 2;
	}
	if (this->getX() < this->world->getM() - 1)
	{
		//prawo TAK
		neighbour = this->getWorld()->getOrganism(this->getX() + 1, this->getY());
		if (neighbour == nullptr)
			directions[allowed_directions++] = 3;
		else if (neighbour->getStrength() <= this->strength)
			directions[allowed_directions++] = 3;
	}
	if (allowed_directions == 0)
		return;

	//losowanie z dostêpnych kierunków
	int direction_index = rand() % allowed_directions;
	if (directions[direction_index] == 0)
		this->setY(this->getY() - 1);
	if (directions[direction_index] == 1)
		this->setY(this->getY() + 1);
	if (directions[direction_index] == 2)
		this->setX(this->getX() - 1);
	if (directions[direction_index] == 3)
		this->setX(this->getX() + 1);
}