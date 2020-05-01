#include"Pile.h"

bool Pile::CheckSize(int n)const {
	if (n > 52)
		return false;
	else if (n < 2)
		return false;
	return true;
}
//--------------------------------------------------------------
Pile::Pile(int n ) {
	if (this->CheckSize(n)==false) {
		cout << "Size insn't valid so it will be 20." << endl;
		this->size = 20;
	}
	else {
		this->size = n;
		if (n % 2 != 0) {
			this->size = n - 1;
		}
	}
	this->ar = new Card[size];
	SetPile();
	MixAll();
}
//----------------------------------------------------------------
Pile::~Pile() {
	delete[] ar;
}
//-----------------------------------------------------------------
int Pile::GetSize() {
	return this->size;
}
//-----------------------------------------------------------------
Card& Pile:: operator[](int index) {
	if (index >= size || index < 0) {
		cout << "Ivalid index." << endl;
		delete[] ar;
		exit(1);
	}
	return this->ar[index];
}
//----------------------------------------------------------------
ostream& operator<<(ostream& out, const Pile& obj) {
	int k{0};
	out << endl << "    1    2    3    4    " << endl;
	for (int i = 0, j = 1; k < obj.size;i++) {
		if (i % 5 == 0) {
			out << endl<<j++ << " ";
		}
		else {
			out << "  " << obj.ar[k];
			k++;
		}
	}
	return out;
}
//-------------------------------------------------------------------
void Pile::MixAll() {
	srand(time(0));//initialize random seed
	int i{ 0 };//initialize variable for the while loop
	while (i != this->size) {
		int positon{ rand() % this->size  };//generate secrete number between 2 and size
		Card help_var{ this->ar[i] };//making helping var 
		this->ar[i] = this->ar[positon];//swap between card object in [i] index and card object in [position] index
		this->ar[positon] = help_var;// another swap between card object in [positon] index and hel[ing var
		i++;
	}
	//now code that make temporary appearence of cards
	int sec{30 };
	cout << "Let's the game begin.You jave 30 seconds.Good luck!" << endl;
	cout << *this;
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
	system("cls");
	for (int i = 0; i < this->size; i++)
		this->ar[i].ChangeOpenClose();
}
//----------------------------------------------------------------
void Pile::SetPile() {
	char let = 'A';
	for (int i = 0; i < this->size; i+=2, let++) {
		this->ar[i].Input(let);
		this->ar[i + 1].Input(let);
	}
}
//----------------------------------------------------------------