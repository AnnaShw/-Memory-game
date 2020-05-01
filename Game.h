#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Pile.h"

class Game {
	int score;
	Pile cards;
public:
	Game(int); //Ctor
	void Run();//function run game
};
