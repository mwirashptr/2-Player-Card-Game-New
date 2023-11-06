#include "BasePlayer.h"

BasePlayer::BasePlayer()
{
	health = 0;
}
void BasePlayer::setHealth(int input)
{
	health = input;
}
void BasePlayer::modifHealth(int input)
{
	health += input;
}
int BasePlayer::getHealth()
{
	return health;
}