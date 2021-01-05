#include <iostream>
using namespace std;



void translator(int number,int numeric_system)
{
	int number_to_print;
	if (number != 0) {
		number_to_print = number % numeric_system;
		number = number / numeric_system;
		translator(number, numeric_system);
		cout << number_to_print;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
		int numeric_system, number;
		cout << "в какую систему переводим?\n";
		cin >> numeric_system;
		cout << "какое число переводим?\n";
		cin >> number;
		translator(number, numeric_system);
}