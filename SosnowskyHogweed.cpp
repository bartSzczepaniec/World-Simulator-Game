#include <iostream>
#include <string.h>
#include "SosnowskyHogweed.h"
#include "World.h"

SosnowskyHogweed::SosnowskyHogweed(int x, int y, World* world, int birthTurn)
{
	strength = 10;
	initiative = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

void SosnowskyHogweed::printing() const
{
	cout << "B";
}

string SosnowskyHogweed::getSpecies() const
{
	return "BarszczSosnowskiego";
}

void SosnowskyHogweed::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms)
{
	cout << attacker->getSpecies() << " zjada " << this->getSpecies(); // jesli organizm zje Barszcz, to mimo, ¿e ma wiecej sily, ginie z zatrucia
	cout << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
	int xo = this->getX();
	int yo = this->getY();
	// napastnik ginie
	cout << this->getSpecies() << " zabija(zatrucie) " << attacker->getSpecies() << "na polu x = " << this->getX() << " y = " << this->getY() << endl;
	attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
	for (int i = 1; i < actionOrganisms.size(); i++)
	{
		if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
			actionOrganisms[i] = nullptr;
	}
	attacker->getWorld()->removeOrganism(attacker->getX(), attacker->getY());
	return;

}