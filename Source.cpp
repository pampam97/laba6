#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class Appliances {
protected:
	string type;
	int serial_number;
public:
	Appliances() {}
	Appliances(int serial_number, string type);
	~Appliances() {}
	void set_serial_number(int serial_number);
	void set_type(string type);
	string get_type();
	int get_serial_number();
	void view_info();
};

class technik : virtual public Appliances
{
protected:
	int weight;
	int height;
public:
	technik() {}
	~technik() {}
	technik(int weight, int height, int serial_number, string type);
	void set_weight(int weight);
	void set_height(int height);
	int get_weight();
	int get_height();
	void view_info();
};


class technik_dopinfo :virtual public Appliances
{
protected:
	int voltage;
	int power;
public:
	technik_dopinfo() {

	}
	~technik_dopinfo() {

	}
	void set_voltage(int voltage);
	void set_power(int power);
	technik_dopinfo(int voltage, int power, string type, int serial_number);
	int get_voltage();
	int get_power();
	void view_info();
};


class technik_info : public technik_dopinfo, public technik
{
protected:
	int price;
	string brand;
public:
	technik_info() {}
	~technik_info() {}
	void set_price(int price);
	void set_brand(string brand);
	technik_info(int price, string brand, int serial_number, string type, int voltage, int power, int weight, int height);
	int get_price();
	string get_brand();
};

void menu_choise() {
	cout << "MENU" << endl;
	cout << "1 - Параметры техники для магазина " << endl;
	cout << "2 - Параметры техники" << endl;
	cout << "3 - Основные параметры о технике " << endl;
	cout << "4 - Дополнительные параметры о технике" << endl;
	cout << "0 - Exit " << endl;
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
			cout << "Ошибка ввода!";
		}
	}
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

/*int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}*/

void enter_mi(int& serial_number, string& type) {
	system("cls");
	cout << "Серийный номер: ";
	protect(serial_number);
	cout << "Тип техники: ";
	cin >> type;
}
void enter_pi(int& serial_number, string& type, int& weight, int& height) {
	system("cls");
	cout << "Серийный номер: ";
	protect(serial_number);
	cout << "Тип техники: ";
	cin >> type;
	cout << "Вес: ";
	protect(weight);
	cout << "Высота: ";
	protect(height);
}
void enter_gi(int& serial_number, string& type, int& voltage, int& power) {
	system("cls");
	cout << "Серийный номер: ";
	protect(serial_number);
	cout << "Тип техники: ";
	cin >> type;
	cout << "Вес: ";
	cout << "Напряжение: ";
	protect(voltage);
	cout << "Мощность: ";
	protect(power);
}
void enter_ti(int& serial_number, string& type, int& weight, int& height, int& voltage, int& power, int& price, string& brand) {
	system("cls");
	cout << "Серийный номер: ";
	protect(serial_number);
	cout << "Тип техники: ";
	cin >> type;
	cout << "Вес: ";
	protect(weight);
	cout << "Высота: ";
	protect(height);
	cout << "Напряжение: ";
	protect(voltage);
	cout << "Мощность: ";
	protect(power);
	cout << "Ценник: ";
	protect(price);
	cout << "Бренд: ";
	cin >> brand;
}


int main() {
	setlocale(0, " ");
	bool flag = true;
	while (flag == true) {
		int serial_number, voltage, power, weight, height, price;
		string type, brand;
		menu_choise();
		int choise;
		protect(choise);
		switch (choise)
		{
		case 1: {
			enter_mi(serial_number, type);
			Appliances mi(serial_number, type);
			mi.view_info();
			break; }
		case 2: {
			enter_pi(serial_number, type, weight, height);
			technik pi(weight, height, serial_number, type);
			pi.view_info();
			break; }
		case 3: {
			enter_gi(serial_number, type, voltage, power);
			technik_dopinfo gi(voltage, power, type, serial_number);
			gi.view_info();
			break;
		}
		case 4:
		{	enter_ti(serial_number, type, weight, height, voltage, power, price, brand);
		technik_info ti(price, brand, serial_number, type, voltage, power, weight, height);
		cout << "Данные о технике для магазина: " << endl;
		((Appliances)ti).view_info();
		cout << "Основные данные о технике: " << endl;
		((technik_dopinfo)ti).view_info();
		cout << "Дополнительные данные о технике: " << endl;
		((technik)ti).view_info();
		cout << endl;
		break;
		}
		case 0:
		{
			flag = false;
			break;
		}
		default: {
			cout << "Нет такого варианта!\n";
			break;
		}
		}
	}

}

technik::technik(int weight, int height, int serial_number, string type) :Appliances(serial_number, type) {
	this->weight = weight;
	this->height = height;
}
void technik::set_weight(int weight) {
	this->weight = weight;
}
void technik::set_height(int height) {
	this->height = height;
}
int technik::get_weight() {
	return weight;
}
int technik::get_height() {
	return height;
}
void technik::view_info() {
	Appliances::view_info();
	cout << "Вес техники: " << this->weight << endl << "Высота техники: " << this->height << endl;
}

void technik_info::set_price(int price) {
	this->price = price;
}
void technik_info::set_brand(string brand) {
	this->brand = brand;
}
technik_info::technik_info(int price, string brand, int serial_number, string type, int voltage, int power, int weight, int height) :
	technik(weight, height, serial_number, type), technik_dopinfo(voltage, power, type, serial_number), Appliances(serial_number, type)
{
	this->price = price;
	this->brand = brand;
}
int  technik_info::get_price() {
	return price;
}
string  technik_info::get_brand() {
	return brand;
}

Appliances::Appliances(int serial_number, string type) {
	this->serial_number = serial_number;
	this->type = type;
}
void Appliances::set_serial_number(int serial_number) {
	this->serial_number = serial_number;
}
void Appliances::set_type(string type) {
	this->type = type;
}
string Appliances::get_type() {
	return type;
}
int Appliances::get_serial_number() {
	return serial_number;
}
void Appliances::view_info() {
	cout << "Тип техники: " << this->get_type() << endl << "Серийный номер: " << this->get_serial_number() << endl;
}


void technik_dopinfo::set_voltage(int voltage) {
	this->voltage = voltage;
}
void technik_dopinfo::set_power(int power) {
	this->power = power;
}
technik_dopinfo::technik_dopinfo(int voltage, int power, string type, int serial_number) :Appliances(serial_number, type) {
	this->voltage = voltage;
	this->power = power;
}
int technik_dopinfo::get_voltage() {
	return voltage;
}
int technik_dopinfo::get_power() {
	return power;
}
void technik_dopinfo::view_info() {
	Appliances::view_info();
	cout << "Мощность: " << this->get_power() << endl << "Напряжение: " << this->get_voltage() << endl;
}

