/*Assigment:3
Campus:Beer Sheva,Author: Anna Rabynovych, ID: 336249628*/
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