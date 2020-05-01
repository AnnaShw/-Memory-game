#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include"Card.h"
#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Game;
class Pile {
	Card* ar;
	int size;
public:
	Pile(int n); //Ctor
	~Pile();//Dctor
	bool CheckSize(int)const;//check if size is legal
	int GetSize();//Just return size
	Card& operator[](int);//check index+return what in this index
	friend ostream& operator<<(ostream&, const Pile&);//print operator overloading
	void MixAll();//mix the pile
	void SetPile();//set val into pile arr
	friend class Game;
};
