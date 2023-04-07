#include <iostream>
#include "Guarana.h"
#include "World.h"
#include "Organism.h"

using namespace std;

Guarana::Guarana(int x, int y, World* world, int birthTurn)
{
	this->strength = 0;
	this->initiative = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}
void Guarana::printing() const
{
	cout << "G";
}

string Guarana::getSpecies() const
{
	return "Guarana";
}

void Guarana::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms)
{
	cout << attacker->getSpecies() << " zjada " << this->getSpecies() << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
	if (attacker->getStrength() < this->strength)
	{
		int xo = this->getX();
		int yo = this->getY();
		// napastnik ginie
		cout << this->getSpecies() << " zabija(zatrucie) " << attacker->getSpecies() << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganisms.size(); i++)
		{
			if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = nullptr;
		}
		attacker->getWorld()->removeOrganism(attacker->getX(), attacker->getY());
		return;
	}
	else // jesli organizm zje guarane, to stale zwieksza swoja sile o 3
	{
		int xo = this->getX();
		int yo = this->getY();
		attacker->setStrength(attacker->getStrength() + 3);
		cout << attacker->getSpecies() << "zwiekszyl sile do:" << attacker->getStrength() << endl;
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganisms.size(); i++)
		{
			if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = nullptr;
		}
	}
}