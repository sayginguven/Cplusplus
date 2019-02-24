#include "Player.h"
#include <iostream>


Player::Player()
{
	health = 0;
	xp = 0.0;
}

Player::Player(std::string name, int health, double xp) 
	: name{ name }, health{ health }, xp{xp}
{
}

Player::Player(const Player &source) {
	
	this->name = source.name;
	this->health = source.health;
	this->xp = source.xp;

}

Player::~Player()
{
}


bool Player::operator>(const Player &obj) const{

	return this->getXP() > obj.getXP() ?  true : false;
	//return this->getXP() > obj.getXP();

}

std::string Player::getName() const
{
	return name;
}


int Player::getHealth() const
{
	return health;
}


double Player::getXP() const
{
	return xp;
}
