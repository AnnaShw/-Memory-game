#include"Game.h"
#include"Card.h"
#include"Pile.h"

int main() {
	int no{ 0};
	cout << "Hello player!" << endl;
	cout << "Enter number of cards you want to play with:" << endl;
	cin >> no;
	Game m(no);
	m.Run();
	return 0;
}