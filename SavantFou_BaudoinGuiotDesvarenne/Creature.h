#pragma once
#include <iostream>
#include <string>

using namespace std;

class Creature
{
protected:
	string name;
	int healthpoint;
	int maxHealthPoint;
	int attackPower;
	bool isFlying;
	bool isBloody;
	bool isFusion;

public: 
	Creature();
	Creature(string n, int mhp, int ap, bool fly);
	Creature(string n, int mhp, int ap, bool fly, bool blood,bool fusion, bool alive);

	string getName();
	void setName(string n);

	int getHealthPoint();
	void setHealthPoint(int hp);

	int getMaxHealthPoint();
	void setMaxHealthPoint(int mhp);

	int getattackPower();
	void setattackPower(int ap);

	bool getIsFlying();
	void setIsFlying(bool fly);

	bool getIsBloody();
	void setIsBloody(bool blood);

	bool getIsFusion();
	void setIsFusion(bool fusion);

	void attack(Creature& p);

	bool isAlive() const
	{
		return healthpoint > 0;
	}

	//friend ostream& operator<<(std :: ostream& out, const Creature& c);
};