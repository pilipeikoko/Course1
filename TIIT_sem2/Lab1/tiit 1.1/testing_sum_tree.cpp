#include <iostream>
#include <vector>
#include "sum_tree.h"
using namespace std;


//Дерево сумм. Поиск суммы чисел на отрезке массива. Изменение всех
//чисел на отрезке массива на какое - то значение.

int main() {
	setlocale(LC_ALL, "rus");
	int l = 0, r = 0, result = 0, val = 0, amount_of_elements=0,sum;
	Tree* root=nullptr;
	int switcc;
	int array[1000];
	while (1) {
		mainmenu();
		cin >> switcc;
		switch (switcc)
		{
		//case 0:
		//	input_array(array,&amount_of_elements);
		//	cout << amount_of_elements;
		//	break;
		case 1:
			cout << "введите количество элементов\n";
			cin >> amount_of_elements;
			root=createtree(0, --amount_of_elements, array);
			break;
		case 2:
			viewtree(root, 0);
			break;
		case 3:
			cout << "введите границы\n";
			cin >> l >> r;
			sum=findsum(root, --l, --r, result);
			cout << sum<<endl;
			break;
		case 4:
			cout << "введите отрезок\n";
			cin >> l >> r;
			cout << "введите число, на которое меняем\n";
			cin >> val;
			change(root, --l, --r, val);
			break;
		case 5:
			viewarray(root);
			break;
		default:
			break;
		}
	}
} 