#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Antelope.h"
#include "Animal.h"
#include "World.h"

Antelope::Antelope(int x, int y, World* world, int birthTurn)
{
	this->strength = 4;
	this->initiative = 4;
	this->x = x;
	this->y = y;
	this->world = world;
	this->birthTurn = birthTurn;
}

void Antelope::printing() const
{
	cout << "A";
}

string Antelope::getSpecies() const
{
	return "Antylopa";
}

void Antelope::action()
{
	int directions[8] = { 0 };  // w przypadku antylopy, istnieje 8 mo¿liwych pol, na ktore moze sie udac
	int allowed_directions = 0; // w ka¿d¹ strone (gora/dol/lewo/prawo) i podwojny skok w te strony
	if (this->getY() > 0)
	{
		// góra TAK
		directions[allowed_directions++] = 0;
	}
	if (this->getY() < this->world->getN() - 1)
	{
		// dó³ TAK
		directions[allowed_directions++] = 1;
	}
	if (this->getX() > 0)
	{
		//lewo TAK
		directions[allowed_directions++] = 2;
	}
	if (this->getX() < this->world->getM() - 1)
	{
		//prawo TAK
		directions[allowed_directions++] = 3;
	}
	if (this->getY() - 1 > 0)
	{
		// górax2 TAK
		directions[allowed_directions++] = 4;
	}
	if (this->getY() < this->world->getN() - 2)
	{
		// dolx2 TAK
		directions[allowed_directions++] = 5;
	}
	if (this->getX() - 1 > 0)
	{
		// góra TAK
		directions[allowed_directions++] = 6;
	}
	if (this->getX() < this->world->getM() - 2)
	{
		// góra TAK
		directions[allowed_directions++] = 7;
	}
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
	if (directions[direction_index] == 4)
		this->setY(this->getY() - 2);
	if (directions[direction_index] == 5)
		this->setY(this->getY() + 2);
	if (directions[direction_index] == 6)
		this->setX(this->getX() - 2);
	if (directions[direction_index] == 7)
		this->setX(this->getX() + 2);
}

void Antelope::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganisms)
{
	if (attacker->getSpecies() == "Antylopa") // przypadek kiedy napastnikiem jest druga antylopa - rozmna¿aja sie
	{
		Animal::collision(attacker, prevAttackerX, prevAttackerY, actionOrganisms);
		return;
	}
	int randomisation = rand() % 100;
	if (randomisation % 2) // 50% szans na ucieczke przed walka (nawet jesli przeciwnik jest slabszy)
	{
		Organism::collision(attacker,prevAttackerX,prevAttackerY,actionOrganisms); // brak ucieczki (walka)
	}
	else
	{
		int directions[4] = { 0 }; // sprawdzenie dostepnosci na 4 s¹siednich polach
		int allowed_directions = 0;
		Organism* neighbour = nullptr;
		if (this->getY() > 0)
		{
			// góra TAK
			neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() - 1);
			if (neighbour == nullptr || neighbour==attacker)
				directions[allowed_directions++] = 0;
		}
		if (this->getY() < this->world->getN() - 1)
		{
			// dó³ TAK
			neighbour = this->getWorld()->getOrganism(this->getX(), this->getY() + 1);
			if (neighbour == nullptr || neighbour == attacker)
				directions[allowed_directions++] = 1;
		}
		if (this->getX() > 0)
		{
			//lewo TAK
			neighbour = this->getWorld()->getOrganism(this->getX() - 1, this->getY());
			if (neighbour == nullptr || neighbour == attacker)
				directions[allowed_directions++] = 2;
		}
		if (this->getX() < this->world->getM() - 1)
		{
			//prawo TAK
			neighbour = this->getWorld()->getOrganism(this->getX() + 1, this->getY());
			if (neighbour == nullptr || neighbour == attacker)
				directions[allowed_directions++] = 3;
		}
		cout << this->getSpecies() << " ucieka przed " << attacker->getSpecies();
		int index_kierunku = rand() % allowed_directions; // wylosowanie kierunku ucieczki i przemieszczenie sie
		if (directions[index_kierunku] == 0)
		{
			this->getWorld()->swapOrganism(prevAttackerX, prevAttackerY, this->getX(), this->getY(), this->getX(), this->getY() - 1);
			this->setY(this->getY() - 1);
			cout << " na pole x = " << this->getX() << " y = " << this->getY() - 1 << endl;
		}
		if (directions[index_kierunku] == 1)
		{
			this->getWorld()->swapOrganism(prevAttackerX, prevAttackerY, this->getX(), this->getY(), this->getX(), this->getY() + 1);
			this->setY(this->getY() + 1);
			cout << " na pole x = " << this->getX() << " y = " << this->getY() + 1 << endl;
		}
		if (directions[index_kierunku] == 2)
		{
			this->getWorld()->swapOrganism(prevAttackerX, prevAttackerY, this->getX(), this->getY(), this->getX() - 1, this->getY());
			this->setX(this->getX() - 1);
			cout << " na pole x = " << this->getX() - 1 << " y = " << this->getY() << endl;
		}
		if (directions[index_kierunku] == 3)
		{
			this->getWorld()->swapOrganism(prevAttackerX, prevAttackerY, this->getX(), this->getY(), this->getX() + 1, this->getY());
			this->setX(this->getX() + 1);
			cout << " na pole x = " << this->getX() + 1 << " y = " << this->getY() << endl;
		}
		for (int i = 1; i < actionOrganisms.size(); i++) // zamiana wskaznikow na organizmy (aby kolejka organizmow wykonuj¹cych akcje by³a poprawna)
		{
			if (actionOrganisms[i] != nullptr && *actionOrganisms[i] == attacker)
				actionOrganisms[i] = this->getWorld()->getPointerOnOrganism(this->getX(), this->getY());
		}
	}
}