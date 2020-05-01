#include"Game.h"

Game::Game(int n):cards(n){
	this->score = 0;
}
//-------------------------------------------------------
void Game::Run() {
	char flag{ 'y' };
	bool first, second;
	int total{ 0 };//count couples of cards that are the same
	int row1{ 0 }, column1{ 0 }, row2{ 0}, column2{ 0};
	while (flag != 'n') {
	//first card
		do {
			cout << cards;
			cout << endl << "Enter row of your first choice:" << endl;
			cin >> row1;
			cout << "Enter column of your first choice:" << endl;
			cin >> column1;
			cout << endl;
				while (column1 > 4) {
					cout << "Invalid column number,it's can't be greater than 4.Please enter again:" << endl;
					cout << "Enter column of your first choice:" << endl;
					cin >> column1;
					cout << endl;
				}
			first = cards.ar[(row1 - 1) * 4 + (column1 - 1)].GetOpen_Close();
			if (first == true) {
				cout << "You already open it.Try again:" << endl;
			}
			else
				cards.ar[(row1- 1) * 4 + (column1 - 1)].ChangeOpenClose();
		} while (first);
	//second card
		do {
			cout << cards;
			cout << endl << "Enter row of your second choice:" << endl;
			cin >> row2;
			cout << "Enter column of your second choice:" << endl;
			cin >> column2;
			cout << endl;
			while (column2 > 4) {
				cout << "Invalid column number,it's can't be greater than 4.Please enter again:" << endl;
				cout << "Enter column of your second choice:" << endl;
				cin >> column2;
				cout << endl;
			}
			second = cards.ar[(row2 - 1) * 4 + (column2 - 1)].GetOpen_Close();
			if (second == true) {
				cout << "You already open it.Try again:" << endl;
			}
			else cards.ar[(row2 - 1) * 4 + (column2 - 1) ].ChangeOpenClose();//reveal the card
		} while (second);
		cout << cards;
		if (cards.ar[(row1 - 1) * 4 + (column1 - 1)] == cards.ar[(row2 - 1) * 4 + (column2 - 1)]){
			cout <<endl<< "Congratulation!It's the same." << endl;
			total++;
		}
		else {
			cout << endl << "No the same." << endl;
			cards.ar[(row2 - 1) * 4 + (column2 - 1)].ChangeOpenClose();
			cards.ar[(row1 - 1) * 4 + (column1 - 1)].ChangeOpenClose();
		}
		if (total * 2 == this->cards.GetSize()) {
			cout << "You found all couples!This is the end of the game." << endl;
			exit(1);
		}
		else {
			cout << "You already found " << total << " couples from " << this->cards.GetSize()/2 << endl;
			cout << "Do you want try to discover one more couple?(y/n)" << endl;
			cin >> flag;
		}
	}
	this->score = total;
}
//-----------------------------------------------------------------