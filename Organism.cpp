#include "Organism.h"
#include "World.h"

int Organism::getX() const
{
	return this->x;
}

int Organism::getY() const
{
	return this->y;
}

int Organism::getStrength() const
{
	return this->strength;
}

int Organism::getInitiative() const
{
	return this->initiative;
}

World* Organism::getWorld() const
{
	return this->world;
}

int Organism::getBirth() const
{
	return this->birthTurn;
}

void Organism::setX(int x)
{
	this->x = x;
}

void Organism::setY(int y)
{
	this->y = y;
}

void Organism::setStrength(int strength)
{
	this->strength = strength;
}

void Organism::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**> &actionOrganisms)
{
	if (attacker->getStrength() < this->strength) // w przypadku, gdy organizm ma wieksza sile niz atakujacy, to go zabija
	{
		// napastnik ginie
		cout << this->getSpecies() << " w obronie zabija " << attacker->getSpecies() << "na polu x = " << this->getX() << " y = " << this->getY() << endl;
		this->getWorld()->removeOrganism(prevAttackerX, prevAttackerY);
		return;
	}
	else 
	{
		cout << attacker->getSpecies() << " zabija " << this->getSpecies() << "na polu x = " << this->getX() << " y = " << this->getY() << endl;
		int xo = this->getX();
		int yo = this->getY();
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganisms.size(); i++)
		{
			if (actionOrganisms[i]!=nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = nullptr;
		}
	}
}