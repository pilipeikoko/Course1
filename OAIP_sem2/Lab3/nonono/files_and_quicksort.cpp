#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
struct spis {
    int num;
    string name;
    string surname;
    string street;
    int h_num;
    int day;
    int month;
    int year;
    long long int date_in_days() {
        return (year * 365) + (month * 30) + day;
    }
};

void create(string path) {
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        cout << "mistake\n";
    }
    else {
        cout << "file was created!\n";
    }
    fin.close();
}
void view(string path) {
    int i = 1;
    string a;
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        cout << "mistake\n";
    }
    else {
        while (!fin.eof()) {
            string a = "";
            getline(fin, a);
            cout << i << ")" << a << endl;
            i++;
        }
    }
    fin.close();
}
void quicksort(spis* spisok, int begin, int end, string path, int lines_amount) {
    int finish = 0;
    int i = end;
    ofstream fout;
    int left, right;
    long long int mid_date;
    spis temp;
    left = begin;
    right = end;
    mid_date = spisok[(left + right ) / 2].date_in_days();
    do {
        while (spisok[left].date_in_days() < mid_date) {
            left++;
        }
        while (mid_date < spisok[right].date_in_days()) {
            right--;
        }
        if (left <= right) {
            temp = spisok[left];
            spisok[left] = spisok[right];
            spisok[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);//do-while end

    if (begin < right) {
        quicksort(spisok, begin, right, path, lines_amount);
    }
    if (left < end) {
        quicksort(spisok, left, end, path, lines_amount);
    }
    else {
        fout.open(path);
        if (!fout.is_open()) {
            cout << "mistake\n";
        }
        else {
            for (int j = 1; j <= lines_amount; j++) {
                fout << spisok[j].num << " " << spisok[j].name << " " << spisok[j].surname << " " << spisok[j].street << " " << spisok[j].h_num << " ";
                if (spisok[j].day < 10) {
                    fout << 0 << spisok[j].day << ".";
                }
                else {
                    fout << spisok[j].day << ".";
                }
                if (spisok[j].month < 10) {
                    fout << 0 << spisok[j].month << ".";
                }
                else {
                    fout << spisok[j].month << ".";
                }
                fout << spisok[j].year;
                if (j != lines_amount) {
                    fout << endl;
                }
            }
        }
    }
}

void push_to_massive(spis* spisok, string path, int* i) {
    ifstream fin;
    fin.open(path);
    *i = 0;
    if (!fin.is_open()) {
        cout << "ошибка!";
    }
    else {
        string data;
        while (!fin.eof()) {
            (*i)++;
            fin >> spisok[*i].num >> spisok[*i].name >> spisok[*i].surname >> spisok[*i].street >> spisok[*i].h_num >> data;
            spisok[*i].day = stoi(data.substr(0, 2));
            spisok[*i].month = stoi(data.substr(3, 2));
            spisok[*i].year = stoi(data.substr(6, 4));
        }
    }
    fin.close();
}

void sort(spis* spisok, int size, string path)
{
    ofstream fout;
    spis temp;
    int min;
    for (int i = 1; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j <= size; j++)
        {
            if (spisok[j].date_in_days() < spisok[min].date_in_days())
                min = j;
        }
        temp = spisok[i];
        spisok[i] = spisok[min];
        spisok[min] = temp;
    }
    fout.open(path);
    if (!fout.is_open()) {
        cout << "mistake\n";
    }
    else {
        for (int j = 1; j <= size; j++) {
            fout << spisok[j].num << " " << spisok[j].name << " " << spisok[j].surname << " " << spisok[j].street << " " << spisok[j].h_num << " ";
            if (spisok[j].day < 10) {
                fout << 0 << spisok[j].day << ".";
            }
            else {
                fout << spisok[j].day << ".";
            }
            if (spisok[j].month < 10) {
                fout << 0 << spisok[j].month << ".";
            }
            else {
                fout << spisok[j].month << ".";
            }
            fout << spisok[j].year;
            if (size != j) {
                fout << endl;
            }
        }
    }
    fout.close();
}

void task(spis* spisok, string path, int size) {
    int m = 0;
    vector<int> a;
    ofstream fout;
    fout.open(path);
    for (int i = 1; i < size; i++) {
        for (int j = i + 1; j <= size; j++) {
            if (spisok[i].name == spisok[j].name && spisok[i].surname == spisok[j].surname && spisok[i].street == spisok[j].street
                && spisok[i].h_num == spisok[j].h_num) {
                for (int t = j,y=t+1; t < size; t++,y++) {
                        spisok[t] = spisok[y];

                }
                size--;
                j--;
            }
        }
    }
    if (!fout.is_open()) {
        cout << "mistake!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fout << spisok[i].num << " " << spisok[i].name << " " << spisok[i].surname << " " << spisok[i].street << " " << spisok[i].h_num << " ";
            if (spisok[i].day < 10) {
                fout << 0 << spisok[i].day << ".";
            }
            else {
                fout << spisok[i].day << ".";
            }
            if (spisok[i].month < 10) {
                fout << 0 << spisok[i].month << ".";
            }
            else {
                fout << spisok[i].month << ".";
            }
            fout << spisok[i].year;
            if (i != size) {
                fout << endl;
            }
        }
    }
}

void line_search(spis* spisok, int i) {
    cout << "введите дату для поиск \nпример 12.02.2002\n";
    int day, month, year;
    string data;
    cin >> data;
    day = stoi(data.substr(0, 2));
    month = stoi(data.substr(3, 2));
    year = stoi(data.substr(6, 4));
    for (int j = 1; j <= i; j++) {
        if (spisok[j].day == day && spisok[j].month == month && spisok[j].year == year) {
            cout << spisok[j].num << " " << spisok[j].name << " " << spisok[j].surname << " " << spisok[j].street << " " << spisok[j].h_num << " " << day << "." << month << "."<<year << endl;
        }
    }
}

void binary_search(spis* spisok, int begin, int end, int total_days) {
    if (spisok[(end + begin) / 2].date_in_days() == total_days) {
        cout << spisok[(end + begin ) / 2].num << " " << spisok[(end + begin ) / 2].name;
        cout << " " << spisok[(end + begin ) / 2].surname << " " << spisok[(end + begin) / 2].street;
        cout << " " << spisok[(end + begin ) / 2].h_num << " " << spisok[(end + begin) / 2].day << ".";
        cout << spisok[(end + begin) / 2].month << "." << spisok[(end + begin) / 2].year << endl;
    }
    else if (spisok[(end + begin) / 2].date_in_days() > total_days) {
        binary_search(spisok, begin, (end + begin) / 2, total_days);
    }
    else if (spisok[(end + begin ) / 2].date_in_days() < total_days) {
        binary_search(spisok, (end + begin) / 2, end, total_days);
    }
}
//
//1 name name adress 1 12.12.2001
//2 oi oi oi 2 12.11.2001
//3 ji ji ji 3 03.03.2002
//4 hu hu hu 4 02.02.2000
//5 hy hy hy 5 01.01.1999
//6 ty ty ty 6 06.08.2006
//7 ty ty ty 7 20.08.1995
//8 name name adress 1 31.05.1951

//В магазине формируется список лиц, записавшихся на покупку товара. Вид списка: номер, ФИО, домашний адрес,дата учета. 
//Удалить из списка все по-вторные записи, проверяя ФИО и адрес. Ключ: дата постановки на учет.
int main() {
    int lines_amount = 0;
    int day, month, year,total_days;
    string data;
    string path;
    ifstream fin;
    ofstream fout;
    spis spisok[100];
    int i;
    setlocale(LC_ALL, "RUS");
    while (1) {
        i = 0;
        cout << "что делаем?\n1)создание файла\n2)показа файла\n3)добавление в список\n4)сортировка массива quicksort\n5)сортировка методом прямого выбора \n";
        cout << "6)двоичный поиск в отсортированном\n7)линейный поиск в остартированном\n8)Удалить из списка все повторные записи, проверяя ФИО и адрес\n0)завершить программу\n";
        int key;
        cin >> key;
        switch (key) {
        case 0:
            return 0;
        case 1://creating file
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            create(path);
            break;
        case 2://viewing file
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            view(path);
            break;
        case 3://adding another buyer
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            push_to_massive(spisok, path, &i);
            i++;
            cout << "введите информацию нового покупателя:номер,имя,фамилию,улицу,№дома,день,месяц,год\n";
            cin >> spisok[i].num >> spisok[i].name >> spisok[i].surname >> spisok[i].street >> spisok[i].h_num >> spisok[i].day
                >> spisok[i].month >> spisok[i].year;
            fout.open(path);
            if (!fout.is_open()) {
                cout << "ошибка!";
            }
            else {
                for (int j = 1; j <= i; j++) {
                    fout << spisok[j].num << " " << spisok[j].name << " " << spisok[j].surname << " " << spisok[j].street << " " << spisok[j].h_num << " ";
                    if (spisok[j].day < 10) {
                        fout << 0 << spisok[j].day << ".";
                    }
                    else {
                        fout << spisok[j].day << ".";
                    }
                    if (spisok[j].month < 10) {
                        fout << 0 << spisok[j].month << ".";
                    }
                    else {
                        fout << spisok[j].month << ".";
                    }
                    fout << spisok[j].year;
                    if (j != i) {
                        fout << endl;
                    }
                }
            }
            fout.close();
            break;
        case 4://quicksort
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            push_to_massive(spisok, path, &i);
            lines_amount = i;
            quicksort(spisok, 1, i, path, lines_amount);
            break;
        case 5://sort by straigh choose
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            push_to_massive(spisok, path, &i);
            sort(spisok, i, path);
            break;
        case 6://binary search
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            cout << "введите дату для поиск \nпример 12.02.2002\n";
            cin >> data;
            day = stoi(data.substr(0, 2));
            month = stoi(data.substr(3, 2));
            year = stoi(data.substr(6, 4));
            push_to_massive(spisok, path, &i);
            total_days = year * 365 + month * 30 + day;
            binary_search(spisok, 1,i, total_days);
            break;
        case 7://line search
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            push_to_massive(spisok, path, &i);
            line_search(spisok, i);
            break;
        case 8://task
            cout << "введите название файла\n";
            cin >> path;
            path = path + ".txt";
            push_to_massive(spisok, path, &i);
            task(spisok, path, i);
            break;
        default:
            cout << "введено неверное число\n";
        }
    }
}