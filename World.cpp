#include "World.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string.h>

#define NUMBEROFORGANISMSFROMSPECIES 4

using namespace std;

World::World(int n, int m)
{
	this->n = n;
	this->m = m;
	this->turn = 0;
	this->organismsMap = new Organism ** [n];
	for (int i = 0; i < n; i++)
	{
		this->organismsMap[i] = new Organism*[m];
		for (int j = 0; j < m; j++)
		{
			organismsMap[i][j] = nullptr;
		}
	}
	srand(time(NULL));
	int x = rand() % m;
	int y = rand() % n;
	organismsMap[y][x] = new Human(x, y, this,0);
	for (int i = 0; i < NUMBEROFORGANISMSFROMSPECIES; i++) // zgodnie z ustalona liczba organizmow z danego gatunku tworzy organizmy
	{												   // na losowo wybranych wolnych polach
		int x = rand() % m;
		int y = rand() % n;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Wolf(x, y, this,0);
		//cout << "wilk" << y <<" "<< x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Sheep(x, y, this,0);
		//cout << "owca" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Turtle(x, y, this,0);
		//cout << "zolw" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Antelope(x, y, this,0);
	//	cout << "Antylopa" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Fox(x, y, this,0);
		//cout << "Lis" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Grass(x, y, this,0);
		//cout << "Trawa" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Sonchus(x, y, this,0);
		//cout << "mlecz" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Guarana(x, y, this,0);
		//cout << "guarana" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new SosnowskyHogweed(x, y, this,0);
	//	cout << "barszcz" << y << " " << x << endl;
		while (organismsMap[y][x] != nullptr)
		{
			x = rand() % m;
			y = rand() % n;
		}
		organismsMap[y][x] = new Nightshade(x, y, this,0);
	//	cout << "wilczejagody" << y << " " << x << endl;
	}

}

int World::getN() const
{
	return this->n;
}

int World::getM() const
{
	return this->m;
}

int World::getTurn() const
{
	return this->turn;
}

Organism* World::getOrganism(int x, int y) const
{
	if (organismsMap[y][x] == nullptr)
		return nullptr;
	return organismsMap[y][x];
}

Organism** World::getPointerOnOrganism(int x, int y) const
{
	if (organismsMap[y][x] == nullptr)
		return nullptr;
	return &organismsMap[y][x];
}

void World::putOrganism(Organism* organism, int x, int y)
{
	organismsMap[y][x] = organism;
}

void World::printWorld() const
{
	for (int i = 0; i < m + 2; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "#";
		for (int j = 0; j < m; j++)
		{
			if (organismsMap[i][j] != nullptr) // jesli istnieje organizm to wypisuje przypisany mu znak
				organismsMap[i][j]->printing();
			else
				cout << ".";
		}
		cout << "#" << endl;
	}
	for (int i = 0; i < m + 2; i++)
		cout << "#";
	cout << endl;
}

void World::printInterface() const
{
	cout << "Autor: Bartlomiej Szczepaniec 184751" << endl;
	cout << "Kliknij enter, aby zaczac kolejna ture" << endl;
	cout << "Kliknij ESC, aby wyjsc" << endl;
}

void World::doTurn()
{
	vector<Organism**> actionOrganisms; // posortowany zbiór organizmów malej¹co wed³ug inicjatyw
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (organismsMap[i][j] != nullptr)
				actionOrganisms.push_back(&organismsMap[i][j]);
		}
	}
	for (int i = 0; i < actionOrganisms.size()-1; i++) // sortowanie organizmow malejaca wzgledem inicjatyw, a jesli s¹ równe to rosn¹c¹ wed³ug tury urodzenia(wieku)
	{
		for (int j = 0; j < actionOrganisms.size() - 1 - i; j++)
		{
			if ((*actionOrganisms[j])->getInitiative() < (*actionOrganisms[j+1])->getInitiative())
			{
				swap(actionOrganisms[j], actionOrganisms[j + 1]);
			}
			else if ((*actionOrganisms[j])->getInitiative() == (*actionOrganisms[j + 1])->getInitiative())
			{
				if ((*actionOrganisms[j])->getBirth() > (*actionOrganisms[j + 1])->getBirth())
				{
					swap(actionOrganisms[j], actionOrganisms[j + 1]);
				}
			}
		}
	}
	turn++;
	cout << "Wydarzenia w turze nr."<<turn<< ":" << endl;
	srand(time(NULL));
	while(!actionOrganisms.empty())
	{
		if (actionOrganisms[0] != nullptr)
		{
			if (*actionOrganisms[0] != nullptr)
			{
				if ((*actionOrganisms[0])->getInitiative() > 0)
				{
					int pX = (*actionOrganisms[0])->getX(); // zapamiêtanie wspó³rzêdnych organizmu przed wykonaniem akcji
					int pY = (*actionOrganisms[0])->getY(); // do usuwania wskaŸnika i przesuwania organizmu
					(*actionOrganisms[0])->action();
					if (pX != (*actionOrganisms[0])->getX() || pY != (*actionOrganisms[0])->getY())
					{
						if (organismsMap[(*actionOrganisms[0])->getY()][(*actionOrganisms[0])->getX()] == nullptr) // miejsce na które przemieœci³ siê organizm
						{
							Organism* pomocniczy;
							organismsMap[(*actionOrganisms[0])->getY()][(*actionOrganisms[0])->getX()] = *actionOrganisms[0];
							organismsMap[pY][pX] = nullptr;
						}
						else // jesli organizm przemieœci³ siê na pole, gdzie by³ ju¿ inny, to nastêpuje kolizja
						{
							organismsMap[(*actionOrganisms[0])->getY()][(*actionOrganisms[0])->getX()]->collision(*actionOrganisms[0], pX, pY, actionOrganisms);
						}
					}
				}
				else // akcje roslin
				{
					(*actionOrganisms[0])->action();
				}
			}
		
		}
		actionOrganisms.erase(actionOrganisms.begin());
	}
	// jesli czlowiek zyje, to obs³uga jego umiejetnosci

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (organismsMap[i][j] != nullptr && organismsMap[i][j]->getSpecies() == "Czlowiek")
			{
				Human* hmn = (Human*)organismsMap[i][j];
				if (hmn->isAbilityActivated())
				{
					hmn->setStrength(hmn->getStrength() - 1);
					if (hmn->getStrength() == hmn->getBaseStrength())
					{
						hmn->deactivate();
					}
				}
				else if (hmn->getWaitingTime() > 0 && hmn->isWaiting())
				{
					hmn->setWaitingTime(hmn->getWaitingTime() - 1);
					if (hmn->getWaitingTime() == 0)
						hmn->letUseAbility();
				}
			}
		}
	}


}

void World::removeOrganism(int x, int y)
{
	delete organismsMap[y][x];
	organismsMap[y][x] = nullptr;
}

void World::replaceOrganism(int x, int y, int replacedX, int replacedY)
{
	delete organismsMap[replacedY][replacedX];
	organismsMap[replacedY][replacedX] = organismsMap[y][x];
	organismsMap[y][x] = nullptr;
}

void World::swapOrganism(int attackerX, int attackerY, int escapingX, int escapingY, int targetX, int targetY)
{
	// w przypadku ucieczki zwierzecia na losowe s¹siednie pole
	if (attackerX == targetX && attackerY == targetY)
	{
		Organism* escaping = organismsMap[escapingY][escapingX];
		organismsMap[escapingY][escapingX] = organismsMap[attackerY][attackerX];
		organismsMap[attackerY][attackerX] = escaping;
		int test = 3;
	}
	else
	{
		organismsMap[targetY][targetX] = organismsMap[escapingY][escapingX];
		organismsMap[escapingY][escapingX] = organismsMap[attackerY][attackerX];
		organismsMap[attackerY][attackerX] = nullptr;
		int test = 3;
	}
}

void World::createAnimal(Organism* organism, int x, int y)
{
	if (organism->getSpecies() == "Wilk")
		organismsMap[y][x] = new Wolf(x, y, this, getTurn());
	if (organism->getSpecies() == "Zolw")
		organismsMap[y][x] = new Turtle(x, y, this, getTurn());
	if (organism->getSpecies() == "Lis")
		organismsMap[y][x] = new Fox(x, y, this, getTurn());
	if (organism->getSpecies() == "Antylopa")
		organismsMap[y][x] = new Antelope(x, y, this, getTurn());
	if (organism->getSpecies() == "Owca")
		organismsMap[y][x] = new Sheep(x, y, this, getTurn());
}

World::~World() // zwalnianie wczeœniej zaalokowanej pamiêci
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			delete organismsMap[i][j];
		}
		delete[] organismsMap[i];
	}
	delete[] organismsMap;
	cout << "Koniec gry" << endl;
}