#include "Animal.h"
#include "World.h"
#include <cstdlib>
#include <time.h>

void Animal::action()
{
	int directions[4] = { 0 };
	int allowed_directions = 0; // sprawdzenie wolnych kierunkow do przesuniecia sie
	if (this->getY() > 0)
	{
		// góra TAK
		directions[allowed_directions++] = 0;
	}
	if (this->getY() < this->world->getN()-1)
	{
		// dó³ TAK
		directions[allowed_directions++] = 1;
	}
	if (this->getX() > 0)
	{
		//lewo TAK
		directions[allowed_directions++] = 2;
	}
	if (this->getX() < this->world->getM()-1)
	{
		//prawo TAK
		directions[allowed_directions++] = 3;
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
}

void Animal::collision(Organism* attacker, int prevAttackerX, int prevAttackerY, vector<Organism**>& actionOrganims)
{
	if (attacker->getSpecies() == this->getSpecies()) // kiedy organizmy s¹ tego samego gatunku, nastepuje ich rozmno¿enie
	{
		attacker->setX(prevAttackerX);
		attacker->setY(prevAttackerY);
		if (this->getBirth() != this->getWorld()->getTurn()) // jesli organizm nie urodzil siê w tej samej turze
		{
			int directions[8] = { 0 }; // sprawdzenie dostepnosci pól na nowy organizm, czyli sasiêdnie pola obu zwierzat
			int allowed_directions = 0;
			Organism* neighbour = nullptr;
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
			if (attacker->getY() > 0)
			{
				// góra TAK
				neighbour = attacker->getWorld()->getOrganism(attacker->getX(), attacker->getY() - 1);
				if (neighbour == nullptr)
					directions[allowed_directions++] = 4;
			}
			if (attacker->getY() < attacker->getWorld()->getN() - 1)
			{
				// dó³ TAK
				neighbour = attacker->getWorld()->getOrganism(attacker->getX(), attacker->getY() + 1);
				if (neighbour == nullptr)
					directions[allowed_directions++] = 5;
			}
			if (attacker->getX() > 0)
			{
				//lewo TAK
				neighbour = attacker->getWorld()->getOrganism(attacker->getX() - 1, attacker->getY());
				if (neighbour == nullptr)
					directions[allowed_directions++] = 6;
			}
			if (attacker->getX() < attacker->getWorld()->getM() - 1)
			{
				//prawo TAK
				neighbour = attacker->getWorld()->getOrganism(attacker->getX() + 1, attacker->getY());
				if (neighbour == nullptr)
					directions[allowed_directions++] = 7;
			}
			if (allowed_directions == 0)
				return;
			else // jesli sa wolne pola, to na losowo wybranym tworzony jest nowy organizm tego gatunku
			{
				cout << this->getSpecies() << " rozmaza sie na pole ";
				int direction_index = rand() % allowed_directions;
				int newx, newy;
				if (directions[direction_index] == 0)
				{
					newx = this->getX();
					newy = this->getY() - 1;
				}
				if (directions[direction_index] == 1)
				{
					newx = this->getX();
					newy = this->getY() + 1;
				}
				if (directions[direction_index] == 2)
				{
					newx = this->getX() - 1;
					newy = this->getY();
				}
				if (directions[direction_index] == 3)
				{
					newx = this->getX() + 1;
					newy = this->getY();
				}
				if (directions[direction_index] == 4)
				{
					newx = attacker->getX();
					newy = attacker->getY() - 1;
				}
				if (directions[direction_index] == 5)
				{
					newx = attacker->getX();
					newy = attacker->getY() + 1;
				}
				if (directions[direction_index] == 6)
				{
					newx = attacker->getX() - 1;
					newy = attacker->getY();
				}
				if (directions[direction_index] == 7)
				{
					newx = attacker->getX() + 1;
					newy = attacker->getY();
				}
				if (this->getSpecies() == "Wilk")
				{
					Wolf* animal = new Wolf(newx, newy, this->getWorld(), this->getWorld()->getTurn());
					this->getWorld()->putOrganism(animal, newx, newy);
				}
				if (this->getSpecies() == "Owca")
				{
					Sheep* animal = new Sheep(newx,newy, this->getWorld(), this->getWorld()->getTurn());
					this->getWorld()->putOrganism(animal, newx, newy);
				}
				if (this->getSpecies() == "Zolw")
				{
					Turtle* animal = new Turtle(newx, newy, this->getWorld(), this->getWorld()->getTurn());
					this->getWorld()->putOrganism(animal, newx, newy);
				}
				if (this->getSpecies() == "Antylopa")
				{
					Antelope* animal = new Antelope(newx, newy, this->getWorld(), this->getWorld()->getTurn());
					this->getWorld()->putOrganism(animal, newx, newy);
				}
				if (this->getSpecies() == "Lis")
				{
					Fox* animal = new Fox(newx, newy, this->getWorld(), this->getWorld()->getTurn());
					this->getWorld()->putOrganism(animal, newx, newy);
				}
				cout << "x = " << this->getX() << " y = " << this->getY() << endl;
			}
		}
		return;
	}
	if (attacker->getStrength() < this->strength) // jesli s¹ z innego gatunku, to sprawdzana jest ich si³a, aby wy³oniæ zwyciêzce
	{
		// napastnik ginie
		cout << this->getSpecies() << " w obronie zabija " << attacker->getSpecies() << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
		this->getWorld()->removeOrganism(prevAttackerX, prevAttackerY);
		return;
	}
	else
	{
		cout << attacker->getSpecies() << " zabija " << this->getSpecies() << " na polu x = " << this->getX() << " y = " << this->getY() << endl;
		int xo = this->getX();
		int yo = this->getY();
		attacker->getWorld()->replaceOrganism(prevAttackerX, prevAttackerY, xo, yo);
		for (int i = 1; i < actionOrganims.size(); i++)
		{
			if (actionOrganims[i] != nullptr && *actionOrganims[i] == attacker)
				actionOrganims[i] = nullptr;
		}
	}
}