#include "Plant.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Organism.h"
#include "World.h"

#define PLANTCHANCE 100

using namespace std;

void Plant::action()
{
	if (randomisePlanting()) // najpierw nastepuje losowanie, czy roslina sie rozmno¿y
	{
		int directions[4] = { 0 };
		int allowed_directions = 0;
		Organism* neighbour = nullptr; // sprawdzenie mozliwych kierunkow
		if (this->getY() > 0)
		{
			// góra TAK
			neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() - 1);
			if (neighbour == nullptr)
				directions[allowed_directions++] = 0;
		}
		if (this->getY() < this->world->getN() - 1)
		{
			// dó³ TAK
			neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() + 1);
			if (neighbour == nullptr)
				directions[allowed_directions++] = 1;
		}
		if (this->getX() > 0)
		{
			//lewo TAK
			neighbour = this->getWorld()->getOrganism(this->getX() - 1, this->getY());
			if (neighbour == nullptr)
				directions[allowed_directions++] = 2;
		}
		if (this->getX() < this->world->getM() - 1)
		{
			//prawo TAK
			neighbour = this->getWorld()->getOrganism(this->getX() + 1, this->getY());
			if (neighbour == nullptr)
				directions[allowed_directions++] = 3;
		}
		if (allowed_directions == 0)
			return;
		cout << this->getSpecies() << " zasiedlil nowe pole";
		//losowanie z dostêpnych kierunków
		int direction_index = rand() % allowed_directions;
		if (directions[direction_index] == 0) // w zaleznosci od gatunku i kierunku, tworzona jest nowa roslina
		{
			if (this->getSpecies() == "Mlecz")
			{
				Sonchus* plant = new Sonchus(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
			}
			if (this->getSpecies() == "Guarana")
			{
				Guarana* plant = new Guarana(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
			}
			if (this->getSpecies() == "BarszczSosnowskiego")
			{
				SosnowskyHogweed* plant = new SosnowskyHogweed(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
			}
			if (this->getSpecies() == "WilczeJagody")
			{
				Nightshade* plant = new Nightshade(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
			}
			if (this->getSpecies() == "Trawa")
			{
				Grass* plant = new Grass(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
			}
			cout << " x = " << this->getX() << " y = " << this->getY() - 1 << endl;
		}
		if (directions[direction_index] == 1)
		{
			if (this->getSpecies() == "Mlecz")
			{
				Sonchus* plant = new Sonchus(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
			}
			if (this->getSpecies() == "Guarana")
			{
				Guarana* plant = new Guarana(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
			}
			if (this->getSpecies() == "BarszczSosnowskiego")
			{
				SosnowskyHogweed* plant = new SosnowskyHogweed(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
			}
			if (this->getSpecies() == "WilczeJagody")
			{
				Nightshade* plant = new Nightshade(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
			}
			if (this->getSpecies() == "Trawa")
			{
				Grass* plant = new Grass(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
			}
			cout << " x = " << this->getX() << " y = " << this->getY() + 1 << endl;
		}
		if (directions[direction_index] == 2)
		{
			if (this->getSpecies() == "Mlecz")
			{
				Sonchus* plant = new Sonchus(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());
			}
			if (this->getSpecies() == "Guarana")
			{
				Guarana* plant = new Guarana(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());;
			}
			if (this->getSpecies() == "BarszczSosnowskiego")
			{
				SosnowskyHogweed* plant = new SosnowskyHogweed(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());
			}
			if (this->getSpecies() == "WilczeJagody")
			{
				Nightshade* plant = new Nightshade(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());
			}
			if (this->getSpecies() == "Trawa")
			{
				Grass* plant = new Grass(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());
			}
			cout << " x = " << this->getX() - 1 << " y = " << this->getY() << endl;
		}
		if (directions[direction_index] == 3)
		{
			if (this->getSpecies() == "Mlecz")
			{
				Sonchus* plant = new Sonchus(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());
			}
			if (this->getSpecies() == "Guarana")
			{
				Guarana* plant = new Guarana(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());;
			}
			if (this->getSpecies() == "BarszczSosnowskiego")
			{
				SosnowskyHogweed* plant = new SosnowskyHogweed(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());
			}
			if (this->getSpecies() == "WilczeJagody")
			{
				Nightshade* plant = new Nightshade(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());
			}
			if (this->getSpecies() == "Trawa")
			{
				Grass* plant = new Grass(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());
			}
			cout << " x = " << this->getX() + 1 << " y = " << this->getY() << endl;
		}
	}
}

void Plant::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms)
{
	cout << attacker->getSpecies() << " zjada " << this->getSpecies() <<" na polu x = " << this->getX()<< " y = " << this->getY() << endl;
	if (attacker->getStrength() < this->strength)
	{
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
	else
	{
		int xo = this->getX();
		int yo = this->getY();
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganisms.size(); i++)
		{
			if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = nullptr;
		}
	}
}

bool Plant::randomisePlanting() // losowanie czy zasiac rosline
{
	int randomisedPlace = rand() % PLANTCHANCE;
	for (int i = 0; i < this->getX()*4; i++)
	{
		for(int j=0;j<this->getY()*3;j++)
			randomisedPlace = rand() % PLANTCHANCE;
	}
	if (randomisedPlace % 10 == 0)
		return true;
	else
		return false;
}