#include "Creature.h"

Creature::Creature() 
{
	name = "Default";
	healthpoint = 100;
	attackPower = 50;
	isFlying = false;
}

Creature::Creature(string n,int hp,int ap,bool fly) 
{
	setName(n);
	setHealthPoint(hp);
	setattackPower(ap);
	setIsFlying(fly);

}

Creature::Creature(string n, int hp, int ap, bool fly, bool blood, bool fusion,bool alive)
{
	setName(n);
	setHealthPoint(hp);
	setattackPower(ap);
	setIsFlying(fly);
	setIsBloody(blood);
	setIsFusion(fusion);
}


string Creature::getName()
{
	return name;
}

void Creature::setName(string n)
{
	if (n == "") {
		cout << "No name set up ! " << endl;
		name = "Default";
	}
	else name = n;
}

int Creature::getHealthPoint()
{
	return healthpoint;
}

void Creature::setHealthPoint(int hp)
{
	healthpoint = maxHealthPoint;
	if (hp <= 0)
	{
		cout << "You see the creature dying instantly" << endl;
	}
	else if (hp > 100)
	{
		cout << "The creature is too powerfull and start to melt" << endl;
	}
}

int Creature::getMaxHealthPoint()
{
	return maxHealthPoint;
}

void Creature::setMaxHealthPoint(int mhp)
{

}

int Creature::getattackPower()
{
	return attackPower;
}

void Creature::setattackPower(int ap)
{
	if (ap <= 0)
	{
		cout << "The creature is too weak to fight" << endl;
	}
	else if (ap > 50)
	{
		cout << "The creature is too powerfull and start to melt" << endl;
	}
	else 
	{
		attackPower = ap;
	}
}

bool Creature::getIsFlying()
{
	return isFlying;
}

void Creature::setIsFlying(bool fly)
{
	if (fly)
		attackPower * 2;
}

bool Creature::getIsBloody()
{
	return isBloody;
}

void Creature::setIsBloody(bool blood)
{
	if (blood) 
	{
		healthpoint / 2;
		attackPower / 2;
	}
}

bool Creature::getIsFusion()
{
	return isFusion;
}

void Creature::setIsFusion(bool fusion)
{
	
}

void Creature::attack(Creature& c)
{
	// Checking the case when the creature is a flying creature
	if (isFlying)
	{
		cout << name << " attack " << c.name << " for " << attackPower  << " damage points !" << endl;
		c.healthpoint = c.healthpoint - attackPower;
		cout << c.name << " have " << c.healthpoint << " HP left! " << endl;
		healthpoint - 10;
		cout << name << " have " << healthpoint << " HP left! " << endl;
	}
	// Checking the case when the creature is a bloody creature
	else if(isBloody){
		cout << name << " attack " << c.name << " for " << attackPower << " damage points !" << endl;
		c.healthpoint = c.healthpoint - attackPower ;
		cout << c.name << " have " << c.healthpoint << " HP left! " << endl;
		// Avoiding the case when the regeneration goes over the max health set
		if (healthpoint <= maxHealthPoint)
			healthpoint = healthpoint + attackPower;
		else if (attackPower + healthpoint > maxHealthPoint)
			healthpoint = maxHealthPoint;
	}
	// Checking the case when the creature is a fusion creature
	else if (isFusion) {
		cout << name << " absorb " << c.name << " life essence !" << endl;
		if (c.maxHealthPoint <= healthpoint && c.attackPower <= attackPower)
		{
			// Absorb life essence and warning before the end of the game
			healthpoint = c.healthpoint + healthpoint;
			attackPower = attackPower + c.attackPower;
			cout << name << " have now " << attackPower << " power and " << healthpoint << " health. " << endl; 
			cout << name << " needs " << 200 - attackPower << " power and " << 500 - healthpoint << " health before being a perfect creature." << endl;
		}
		else {
			cout << "The creature is too powerfull to be absorbed !" << endl;
		}
		if (attackPower >= 200  && healthpoint >= 500 )
		{
			//End of the game
			cout << name << " is now a perfect creature. It's the end of the world !" << endl;
			exit(0);
		}

		cout << c.name << " have " << c.healthpoint << " HP left! " << endl;
	}
	// Checking the case when the creature is a normal creature
	else {
		cout << name << " attack " << c.name << " for " << attackPower << " damage points !" << endl;
		c.healthpoint = c.healthpoint - attackPower;
		cout << c.name << " have " << c.healthpoint << " HP left! " << endl;
	}

}

/*
std :: ostream& operator<<(ostream& out, const Creature& c)
{
	out << (Creature)c;
	out << " The name of the creature is :" << c.name << endl;
	out << " It have " << c.healthpoint << " healthpoint !" << endl;
	out << " It's power level is : " << c.attackPower << endl;

	out << (c.isFlying ? "It's a flying creature" : "It's not a flying creature") << endl;
	out << (c.isBloody ? "It's a bloody creature" : "It's not a bloody creature") << endl;
	out << (c.isFusion ? "It's a fusionning creature" : "It's not a fusionning creature") << endl;

	return out;
}*/