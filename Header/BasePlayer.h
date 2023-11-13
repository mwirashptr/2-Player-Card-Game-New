#pragma once

#include <iostream>
#include <array>

class Player;

class BasePlayer
{
protected:
	int health = 0;
public:
	BasePlayer();
	void setHealth(int input);
	void modifHealth(int input);
	int getHealth();
};