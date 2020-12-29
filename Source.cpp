#pragma once
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Hockeyist {
protected:
	string name;
	int age;
public:
	Hockeyist() {}
	Hockeyist(int age, string name);
	~Hockeyist() {}
	void set_age(int age);
	void set_name(string name);
	string get_name();
	int get_age();
	void view_info();
};

class Player : virtual public Hockeyist
{
protected:
	int weight;
	int height;
public:
	Player() {}
	~Player() {}
	Player(int weight, int height, int age, string name);
	void set_weight(int weight);
	void set_height(int height);
	int get_weight();
	int get_height();
	void view_info();
};


class Game :virtual public Hockeyist
{
protected:
	int number_of_games;
	int number_of_wins;
public:
	Game() {

	}
	~Game() {

	}
	void set_number_of_games(int number_of_games);
	void set_number_of_wins(int number_of_wins);
	Game(int number_of_games, int number_of_wins, string name, int age);
	int get_number_of_games();
	int get_number_of_wins();
	void view_info();
};


class Trainer : public Game, public Player
{
protected:
	int price;
	string surname;
public:
	Trainer() {}
	~Trainer() {}
	void set_price(int price);
	void set_surname(string surname);
	Trainer(int price, string surname, int age, string name, int number_of_games, int number_of_wins, int weight, int height);
	int get_price();
	string get_surname();
};

void menu_choise() {
	cout << "_______________MENU______________" << endl;
	cout << "\t 1 - Work with main info " << endl;
	cout << "\t 2 - Work with player's info " << endl;
	cout << "\t 3 - Work with game info " << endl;
	cout << "\t 4 - Work with trainer's info " << endl;
	cout << "\t 0 - Exit " << endl;
}
void protect(int& number) {
	while (true) {
		cin >> number;
		if (cin.get() == '\n') {
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Input error \n Try again \n";
		}
	}
}
void enter_mi(int& age, string& name) {
	system("cls");
	cout << "Enter age : ";
	protect(age);
	cout << "Enter name : ";
	cin >> name;
}
void enter_pi(int& age, string& name, int& weight, int& height) {
	system("cls");
	cout << "Enter age : ";
	protect(age);
	cout << "Enter name : ";
	cin >> name;
	cout << "Enter weight : ";
	protect(weight);
	cout << "Enter height : ";
	protect(height);
}
void enter_gi(int& age, string& name, int& number_of_games, int& number_of_wins) {
	system("cls");
	cout << "Enter age : ";
	protect(age);
	cout << "Enter name : ";
	cin >> name;
	cout << "Enter weight : ";
	cout << "Enter numeber of games : ";
	protect(number_of_games);
	cout << "Enter numeber of wins : ";
	protect(number_of_wins);
}
void enter_ti(int& age, string& name, int& weight, int& height, int& number_of_games, int& number_of_wins, int& price, string& surname) {
	system("cls");
	cout << "Enter age : ";
	protect(age);
	cout << "Enter name : ";
	cin >> name;
	cout << "Enter weight : ";
	protect(weight);
	cout << "Enter height : ";
	protect(height);
	cout << "Enter numeber of games : ";
	protect(number_of_games);
	cout << "Enter numeber of wins : ";
	protect(number_of_wins);
	cout << "Enter price : ";
	protect(price);
	cout << "Enter surname : ";
	cin >> surname;
}


int main() {
	setlocale(LC_ALL, "ru");
	bool flag = true;
	while (flag == true) {
		int age, number_of_games, number_of_wins, weight, height, price;
		string name, surname;
		menu_choise();
		int choise;
		protect(choise);
		switch (choise)
		{
		case 1: {
			enter_mi(age, name);
			Hockeyist mi(age, name);
			mi.view_info();
			break; }
		case 2: {
			enter_pi(age, name, weight, height);
			Player pi(weight, height, age, name);
			pi.view_info();
			break; }
		case 3: {
			enter_gi(age, name, number_of_games, number_of_wins);
			Game gi(number_of_games, number_of_wins, name, age);
			gi.view_info();
			break;
		}
		case 4:
		{	enter_ti(age, name, weight, height, number_of_games, number_of_wins, price, surname);
		Trainer ti(price, surname, age, name, number_of_games, number_of_wins, weight, height);
		cout << "��� ����� �������� ������ : " << endl;
		((Hockeyist)ti).view_info();
		cout << "��� ����� ������ Game : " << endl;
		((Game)ti).view_info();
		cout << "��� ����� ������ Player : " << endl;
		((Player)ti).view_info();
		cout << endl;
		break;
		}
		case 0:
		{
			flag = false;
			break;
		}
		default: {
			cout << "No such variant \n";
			break;
		}
		}
	}

}

Player::Player(int weight, int height, int age, string name) :Hockeyist(age, name) {
	this->set_weight(weight);
	this->set_height(height);
}
void Player::set_weight(int weight) {
	this->weight = weight;
}
void Player::set_height(int height) {
	this->height = height;
}
int Player::get_weight() {
	return weight;
}
int Player::get_height() {
	return height;
}
void Player::view_info() {
	Hockeyist::view_info();
	cout << "Player's weight : " << this->weight << endl << "Player's height : " << this->height << endl;
}

void Trainer::set_price(int price) {
	this->price = price;
}
void Trainer::set_surname(string surname) {
	this->surname = surname;
}
Trainer::Trainer(int price, string surname, int age, string name, int number_of_games, int number_of_wins, int weight, int height) :
	Player(weight, height, age, name), Game(number_of_games, number_of_wins, name, age), Hockeyist(age, name)
{
	this->set_price(price);
	this->set_surname(surname);
}
int  Trainer::get_price() {
	return price;
}
string  Trainer::get_surname() {
	return surname;
}

Hockeyist::Hockeyist(int age, string name) {
	this->set_age(age);
	this->set_name(name);
}
void Hockeyist::set_age(int age) {
	this->age = age;
}
void Hockeyist::set_name(string name) {
	this->name = name;
}
string Hockeyist::get_name() {
	return name;
}
int Hockeyist::get_age() {
	return age;
}
void Hockeyist::view_info() {
	cout << "Player's name : " << this->get_name() << endl << "Player's age : " << this->get_age() << endl;
}


void Game::set_number_of_games(int number_of_games) {
	this->number_of_games = number_of_games;
}
void Game::set_number_of_wins(int number_of_wins) {
	this->number_of_wins = number_of_wins;
}
Game::Game(int number_of_games, int number_of_wins, string name, int age) :Hockeyist(age, name) {
	this->set_number_of_games(number_of_games);
	this->set_number_of_wins(number_of_wins);
}
int Game::get_number_of_games() {
	return number_of_games;
}
int Game::get_number_of_wins() {
	return number_of_wins;
}
void Game::view_info() {
	Hockeyist::view_info();
	cout << "Player's number of wins : " << this->get_number_of_wins() << endl << "Player's number of games : " << this->get_number_of_games() << endl;
}
