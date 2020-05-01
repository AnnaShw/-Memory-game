#include"Card.h"

Card::Card() {
	let = 0;
	this->Open_Close = true;
}
//------------------------------------------------------------------------------------------------------------
Card::Card(const Card& other){
	this->let = other.let;
	this->Open_Close = other.Open_Close;
}
bool Card::GetOpen_Close()const {
	return Open_Close;
}
//-------------------------------------------------------------------------------------------------
char Card::Getchar()const {
	return let;
}
//-------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Card& other) {
	if (other.Open_Close)
		out << "[" << other.let << "]";
	else 
		out << "[?]";
	return out;
}
//---------------------------------------------------------------------------------------------------------
void Card::ChangeOpenClose() {
	Open_Close=!Open_Close;
}
//--------------------------------------------------------------------------------------------------------------------
bool Card::operator==(const Card& obj)const {
	return this->let == obj.let;
}
//----------------------------------------------------------------------------------------------------------------
void Card::Input(char var) {
	this->let = var;
}