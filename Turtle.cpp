#include <iostream>
#include "Turtle.h"
#include <cstdlib>
#include <time.h>
#include "World.h"

#define MOVE 3

void Turtle::printing() const
{
	cout << "Z";
}

Turtle::Turtle(int x, int y, World* world, int birthTurn)
{
	this->strength = 2;
	this->initiative = 1;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

string Turtle::getSpecies() const
{
	return "Zolw";
}

void Turtle::action()
{
	int randomisation = rand() % 100;
	if (randomisation % 4 == 0) // losowanie, czy ¿ó³w ma wykonaæ ruch (ma na to 25% szans)
	{
		Animal::action();
	}
}

void Turtle::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms)
{
	if (attacker->getSpecies() == "Zolw")
	{
		Animal::collision(attacker, prevAttackerX, prevAttackerY, actionOrganisms);
		return;
	}
	if(attacker->getStrength() >= 5)
	{
		cout << attacker->getSpecies() << " zabija " << this->getSpecies() << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
		int xo = this->getX();
		int yo = this->getY();
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganisms.size(); i++)
		{
			if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = nullptr;
		}
	}
	else // zgodnie z tabelka, jesli napastnik ma mniej ni¿ 5 sily to ¿ó³w go odgania
	{
		cout << this->getSpecies() << " odgania " << attacker->getSpecies() << " z pola x = " << this->getX() << " y = " << this->getY() << endl;
		attacker->setX(prevAttackerX);
		attacker->setY(prevAttackerY);
	}
}