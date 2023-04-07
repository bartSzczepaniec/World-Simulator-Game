#include<iostream>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include "Sonchus.h"
#include "Plant.h"
#include "World.h"

using namespace std;

Sonchus::Sonchus(int x, int y, World* world, int birthTurn)
{
	this->strength = 0;
	this->initiative = 0;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

void Sonchus::printing() const
{
	cout << "M";
}

string Sonchus::getSpecies() const
{
	return "Mlecz";
}

void Sonchus::action()
{
	for (int i = 0; i < 3; i++)
	{
		if (this->randomisePlanting())
		{
			int directions[4] = { 0 };
			int allowed_directions = 0;
			Organism* neighbour = nullptr; // sprawdzenie czy sa wolne pola do rozsiania
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
			int direction_index = rand() % allowed_directions; // zasiedlenie losowo wybranego wolnego pola
			if (directions[direction_index] == 0)
			{
				Sonchus* plant = new Sonchus(this->getX(), this->getY() - 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() - 1);
				cout << " x = " << this->getX() << " y = " << this->getY() - 1 << endl;
			}
			if (directions[direction_index] == 1)
			{
				Sonchus* plant = new Sonchus(this->getX(), this->getY() + 1, this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX(), this->getY() + 1);
				cout << " x = " << this->getX() << " y = " << this->getY() + 1 << endl;
			}
			if (directions[direction_index] == 2)
			{
				Sonchus* plant = new Sonchus(this->getX() - 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() - 1, this->getY());
				cout << " x = " << this->getX() - 1 << " y = " << this->getY() << endl;
			}
			if (directions[direction_index] == 3)
			{
				Sonchus* plant = new Sonchus(this->getX() + 1, this->getY(), this->getWorld(), this->getWorld()->getTurn());
				this->getWorld()->putOrganism(plant, this->getX() + 1, this->getY());
				cout << " x = " << this->getX() + 1 << " y = " << this->getY() << endl;
			}
		}
	}
}