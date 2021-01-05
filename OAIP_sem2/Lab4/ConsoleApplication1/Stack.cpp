// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct Stack {
	int data;
	Stack* next;
};

void AddToStack(Stack** top, int data) {
	Stack* new_element = new Stack;
	new_element->data = data;
	new_element->next = *top;
	*top = new_element;
}

void create(Stack** top) {
	int amount;
	int temp_data;
	srand(time(NULL));
	if (*top) {
		cout << "Очистите память!" << endl;
		return;
	}
	cout << "Введите количество чисел в Stack" << endl;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		temp_data = rand() % 41 - 20;
		AddToStack(top, temp_data);
	}
	cout << endl << "Stack успешно создан";
}

void view(Stack** top) {
	if (*top == nullptr) {
		cout << "Сперва создайте Stack";
		return;
	}
	Stack* temp = *top;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void SortInfo(Stack* top) {
	Stack* end_element = nullptr, * curr_element;
	int buffer;
	do {
		for (curr_element = top; curr_element->next != end_element; curr_element = curr_element->next)
			if (curr_element->data > curr_element->next->data) {
				buffer = curr_element->data;
				curr_element->data = curr_element->next->data;
				curr_element->next->data = buffer;
			}
		end_element = curr_element;
	} while (top->next != end_element);
}


void SortPtr(Stack** top) {
	Stack* end_element = nullptr, * curr_element, * buffer;
	AddToStack(top, -100);
	if ((*top)->next->next == NULL)
		return;
	do {
		for (curr_element = *top; curr_element->next->next != end_element; curr_element = curr_element->next)
			if (curr_element->next->data > curr_element->next->next->data) {
				buffer = curr_element->next->next;
				curr_element->next->next = buffer->next;
				buffer->next = curr_element->next;
				curr_element->next = buffer;
			}
		end_element = curr_element->next;
	} while ((*top)->next->next != end_element);

	Stack* del_top = *top;
	*top = (*top)->next;
	delete del_top;
}

void self_task(Stack** top, vector<int>& C, vector<int>& B) {
	Stack temp_head;
	temp_head.next = *top;
	Stack* curr_el = &temp_head;
	while (curr_el->next) {
		if ((curr_el->next->data) >= 0) {
			C.push_back((curr_el->next->data));
			curr_el = curr_el->next;
		}
		else {
			B.push_back((curr_el->next->data));
			curr_el = curr_el->next;
		}
	}
}

void Del_All(Stack** top) {
	Stack* t;
	while (*top != nullptr) {
		t = *top;
		*top = (*top)->next;
		delete t;
	}
}


int main()
{
	setlocale(LC_ALL, ("rus"));
	int temp_data;
	Stack* top = nullptr;
	int switcc;
	vector <int> C;
	vector <int> B;
	while (1) {
		cout << "\nвыберите оперцию:\n0)очистить память\n1)создание\n2)добавление\n3)просмотр\n4)сортировка перестановкой";
		cout << "адресов двух соседних элементов, следующих за элементом с известным указателем\n5)";
		cout << "обмен информацией между текущим и следующим элементами\n6)Разделить созданный список на два: в первом – положительные числа, во втором – отрицательные. " << endl;
		cin >> switcc;
		switch (switcc) {
		case 0:
			Del_All(&top);
			break;
		case 1:
			create(&top);
			break;
		case 2:
			cout << "введите число,которое добавляем\n";
			cin >> temp_data;
			AddToStack(&top, temp_data);
			break;
		case 3:
			view(&top);
			break;
		case 4:
			SortPtr(&top);
			break;
		case 5:
			SortInfo(top);
			break;
		case 6:
			self_task(&top, C, B);
			for (auto b : B) {
				cout << b << " ";
			}
			cout << endl;
			for (int a : C) {
				cout << a << " ";
			}
			break;
		}
	}
}
