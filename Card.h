
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <iomanip>
#include<ctime>
using namespace std;

class Card {
	char let;
	bool Open_Close;//true if open,false if close
public:
	Card();//default+parametr Ctor
	Card(const Card&);
	char Getchar()const;//just return char
	bool GetOpen_Close()const;//just return statis(open/close)
	friend ostream& operator<<(ostream&, const Card&);//print operator overloading
	bool operator==(const Card&)const;//will check if 2 cards the same
	void ChangeOpenClose();//change open->close or close->open
	void Input(char);//input char var
};
