#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct spisok {
	int data;
	spisok* prev;
	spisok* next;
};

void AddToSpisokFromRight(int tempdata, spisok** begin, spisok** end) {
	if (!*end) {
		cout << "сперва создайте список\n";
		return;
	}
	spisok* add = new spisok;
	add->data = tempdata;
	add->next = nullptr;
	add->prev = *end;
	(*end)->next = add;
	*end = add;
}

void AddToSpisokFromLeft(int tempdata, spisok** begin, spisok** end) {
	if (!*begin) {
		cout << "сперва создайте список\n";
		return;
	}
	spisok* add = new spisok;
	add->data = tempdata;
	add->next = *begin;
	add->prev = nullptr;
	(*begin)->prev = add;
	*begin = add;
}

void CreateSpisok(spisok** begin, spisok** end) {
	int amount;
	int tempdata;
	cout << "сколько чисел добавим\n";
	cin >> amount;
	srand(time(NULL));
	if (*begin) {
		cout << "Очистите память!" << endl;
		return;
	}
	else {
		spisok* firstelement = new spisok;
		firstelement->next = *begin;
		firstelement->prev = *end;
		firstelement->data = rand() % 21 - 10;
		*begin = firstelement;
		*end = firstelement;
		for (int i = 1; i < amount; i++) {
			tempdata = rand() % 21 - 10;
			AddToSpisokFromRight(tempdata, begin, end);
		}
	}
}

void ViewFromBegin(spisok *begin) {
	if (!begin) {
		cout << "сперва создайте список\n";
		return;
	}
	spisok* top;
	top = begin;
	while (top) {
		cout<<top->data<<" ";
		top = top->next;
	}
	cout << endl;
}

void ViewFromEnd(spisok* end) {
	if (!end) {
		cout << "сперва создайте список\n";
		return;
	}
	spisok* top;
	top = end;
	while (top) {
		cout << top->data <<" ";
		top = top->prev;
	}
	cout << endl;
}

void SelfTask(spisok** begin,vector<int>& positive,vector<int>&negative) {
	spisok* top;
	top = *begin;
	if (!top) {
		cout << "сперва создайте список\n";
		return;
	}
	while (top) {
		if (top->data >= 0) {
			positive.push_back(top->data);
		}
		else {
			negative.push_back(top->data);
		}
		top = top->next;
	}
}

int main()
{
	vector <int> positive;
	vector<int> negative;
	setlocale(LC_ALL, "russian");
	spisok* begin = nullptr;
	spisok* end = nullptr;
	int switcc;
	int temp;
	while (1) {
		cout << "выберите\n1)создать список\n2)добавить в конец\n3)добавить а начало\n";
		cout<<"4)просмотреть с начала\n5)просмотреть с конца\n6)разделить список на положительные и отрицательные\n";
		cin >> switcc;
		switch (switcc) {
		case 1:
			CreateSpisok(&begin, &end);
			break;
		case 2:
			cout << "что добавим?\n";
			cin >> temp;
			AddToSpisokFromRight(temp, &begin, &end);
			break;
		case 3:
			cout << "что добавим\n";
			cin >> temp;
			AddToSpisokFromLeft(temp, &begin, &end);
			break;
		case 4:
			ViewFromBegin(begin);
			break;
		case 5:
			ViewFromEnd(end);
			break;
		case 6:
			SelfTask(&begin,positive,negative);
			for (auto a : positive) {
				cout << a << " ";
			}
			cout << endl;
			for (auto b : negative) {
				cout << b << " ";
			}
			cout << endl;
			break;
		}
	}
}