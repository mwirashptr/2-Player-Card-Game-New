#include "Game.h"

void Game::randomCardStack()
{
	for (int i = 1; i <= 50; i++)
	{
		cout << " Tes tes " << i;
		int random = rand() % 50 + 1;
		Card* temp = getCardStack(random);
		setCardStack(getCardStack(i), random);
		setCardStack(temp, i);
		std::cout << getCardStack(i)->getNickname() << "\n";
	}
}

void Game::give5Card()
{
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 1) Player_1.setDeck(takeFrontCard(), i / 2 + 1);
		else Player_2.setDeck(takeFrontCard(), i / 2);

		std::cout << " Loop " << i;
	}
}

void Game::giveAnotherCard()
{
	Player_1.setDeck(takeFrontCard(), 5);
	Player_2.setDeck(takeFrontCard(), 5);
}

void Game::initPlayer()
{
	std::cout << "InitPlayer Before";
	Player_1.setHealth(50);
	Player_2.setHealth(50);
	std::cout << "Before GIVE5CARD";
	give5Card();
	std::cout << "InitPlayer After";
}

void Game::abilityTurn(int input) //input = comparing damage
{
	int temp;
	if (input == 1) temp = 1;
	else if (input == 2) temp = -1;
	else
	{
		if (comparingCardType() == 1) { input = PLAYER2; temp = -1; }
		else if (comparingCardType() == 2) { input = PLAYER1; temp = 1; }
		else return;
	}

	while (input == 1 || input == 2)
	{
		if (input == 1)
		{
			getChosenCard(input)->ability(&Player_1, &Player_2);
		}
		else if (input == 2)
		{
			getChosenCard(input)->ability(&Player_2, &Player_1);
		}
		input += temp;
	}
}

void Game::damageTurn(int input) // input = comparing type
{
	if (input == 1) // jika attack lebih kecil dari defense, maka selisih akan dipantulkan
	{
		int damage;
		damage = getChosenCard(PLAYER1)->getNumber() - getChosenCard(PLAYER2)->getNumber();
		if (damage < 0) Player_1.modifHealth(damage);
		else if (damage > getChosenCard(PLAYER2)->getNumber()) Player_2.modifHealth(-damage);
	}
	else if (input == 2) // jika attack lebih kecil dari defense, maka selisih akan dipantulkan
	{
		int damage;
		damage = getChosenCard(PLAYER2)->getNumber() - getChosenCard(PLAYER1)->getNumber();
		if (damage < 0) Player_2.modifHealth(damage);
		else if (damage > getChosenCard(PLAYER1)->getNumber()) Player_1.modifHealth(-damage);
	}
	else if (input == 3)
	{
		Player_1.modifHealth(-getChosenCard(PLAYER2)->getNumber());
		Player_2.modifHealth(-getChosenCard(PLAYER1)->getNumber());
	}
	else
	{
		if (comparingCardDamage() == 1) Player_1.modifHealth(getChosenCard(PLAYER1)->getNumber());
		else if (comparingCardDamage() == 2) Player_2.modifHealth(getChosenCard(PLAYER2)->getNumber());
		else return;
	}
}

Card* Game::playerTurn(Player& input, int index)
{
	using namespace std;
	cout << "\n\t\t\t\t\t\tPlayer " << index << "'s Turn";
	cout << "\n\n\n\n\t\t   ";
	for (int i = 1; i <= 5; i++)
	{
		cout << "[ " <<
			input.getCard(i)->getNickname()[0] << " " <<
			input.getCard(i)->getNickname()[1] <<
			input.getCard(i)->getNickname()[2] << " ](" << i << ")     ";
	}
	return input.chooseCard();
}

void Game::boardTurn()
{
	abilityTurn(comparingCardDamage());
	damageTurn(comparingCardType());
}

int Game::checkWinner()
{
	if (Player_1.getHealth() <= 0 && Player_2.getHealth() > 0)			return PLAYER2;
	else if (Player_2.getHealth() <= 0 && Player_1.getHealth() > 0)		return PLAYER1;
	else if (Player_2.getHealth() <= 0 && Player_1.getHealth() <= 0)	return 3;
	else return 0;
}

void Game::mainMenu()
{
	cout << "\n================================================= 2 Player Card Game ===================================================";
	cout << "\n\n\n\t Peraturan : ";
	cout << "\n\t - Diawal permainan, Pemain akan diberikan 5 kartu acak";
	cout << "\n\t - Kedua pemain akan diharuskan memilih satu kartu untuk diadu dipapan";
	cout << "\n\t - Kedua kartu yang sudah ada dipapan akan diadu dari jenis kartu juga angkanya";
	cout << "\n\t - Jika kedua kartu berjenis ATTACK, maka kartu akan menyerang lawan";
	cout << "\n\t - Jika kedua kartu berbeda jenis, maka kartu ATTACK akan menyerang dan kartu DEFENSE akan menghadang";
	cout << "\n\t - Jika kedua kartu berjenis DEFENSE, maka kartu dengan angka tertinggi akan memulihkan darah pemiliknya";
	cout << "\n\t - Pemain yang kehabisan darah akan dinyatakan kalah dan lawannya adalah pemenangnya";
	std::cin.get();
}

void Game::theGame()
{
	system("CLS");
	//render both health (always on top)
	cout << "\n\t\t Player 1's Health : " << Player_1.getHealth()
		<< "\t\t\t\t\t Player 2's Health : " << Player_2.getHealth();
	setChosenCard(playerTurn(Player_1, PLAYER1), PLAYER1);
	system("CLS");

	cout << "\n\t\t Player 1's Health : " << Player_1.getHealth()
		<< "\t\t\t\t\t Player 2's Health : " << Player_2.getHealth();
	setChosenCard(playerTurn(Player_2, PLAYER2), PLAYER2);
	system("CLS");

	//render card battle,
	boardTurn();
}

void Game::Play()
{
	mainMenu();
	cout << "Main Menu Tuntas";
	initCardStack();
	cout << "InitCard Tuntas";
	randomCardStack();
	cout << "randomCard Tuntas";
	initPlayer();
	cout << "InitPlayer Tuntas";

	int run = 0;
	while (!run)
	{
		theGame();
		giveAnotherCard();
		run = checkWinner();
	}

	cout << "\n\t\t\tPemenangnya : " << run;
}