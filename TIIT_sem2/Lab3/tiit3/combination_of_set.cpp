// tiit3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int GlobalM[100];
vector <int> vect;

bool switcc( int *a, int n, int m)
{
    int j;
    do  
    {
        j = n - 1;
        while (j != -1 && a[j] >= a[j + 1]) {
            j--;
        }
        if (j == -1) {
            return false;
        }
        int k = n - 1;
        while (a[j] >= a[k]) {
            k--;
        }
        swap(a[j],a[k]);
        int l = j + 1, r = n - 1; 
        while (l < r){
            swap(a[l],a[r]); 
            l++;
            r--;
        }
    } while (j > m - 1);
    return true;
}

int fact(int n)
{
    if (n < 0)
        return 0; 
    if (n == 0) 
        return 1;
    else
        return n * fact(n - 1); 
}
//
//{1,2,3,{},{1,2,{2}},<1,2>,<1,2,<3,4>>}
//{ o,{},A }
//{ o,<1,2>,A2,c3,B,b3_A,{},{o,{},A} }
//{ o,A2,b3,A,<1,2>,{} }


/*
Реализовать программу, формирующую без повторений всевозможные ориентированные
множества из элементов исходного неориентированного множества, количество элементов в
сформированных множествах должно быть равно исходному натуральному n.*/
int main()
{
    setlocale(LC_ALL, ("RUS"));
    vector <char> vec[1000];
    int vec_count = 0, count1 = 0, count2 = 0;
    string line, line1 = "", line2 = "";
    cout << "введите множество\n";
    cin >> line;
    //for (int i = 0; i < line.size(); i++) {
    //    vec[vec_count].push_back(line[i]);
    //}//добавление самого множества
    //vec_count++;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '<') {
            int j = i + 1;
            count1++;
            vec[vec_count].push_back(line[i]);
            while (count1 != count2) {
                char a = line[j];
                if (a == '<') {
                    count1++;
                }
                else if (a == '>') {
                    count2++;
                }
                vec[vec_count].push_back(a);
                j++;
                i++;
            }
            vec_count++;
        }
        else {
            line1 += line[i];
        }
    }//добавление кортежей
    line = line1;
    line1 = "";
    for (int i = 1; i < line.size(); i++) {
        if (line[i] == '{') {
            int j = i + 1;
            count1++;
            vec[vec_count].push_back(line[i]);
            while (count1 != count2) {
                char a = line[j];
                if (a == '{') {
                    count1++;
                }
                else if (a == '}') {
                    count2++;
                }
                vec[vec_count].push_back(a);
                j++;
                i++;
            }
            vec_count++;
        }
        else {
            line1 += line[i];
        }
    }//добавление подмножеств
    line2 = "{";
    line = line2 + line1;
    line1 = "";
    for (int i = 0; i < line.size(); i++) {
        if (i == line.size() - 2 && line[i] == ',' && line[i + 1] == '}') {

        }
        else if (line[i] == ',' && line[i + 1] == ',') {

        }
        else {
            line1 += line[i];
        }
    }//удаление лишних запятых
    line = line1;
    line[0] = ',';
    line[line.size() - 1] = ',';
    for (int i = 0; i < line.size() - 1; i++) {
        if (line[i] == ',') {
            i++;
            while (line[i] != ',') {
                vec[vec_count].push_back(line[i]);
                i++;
            }
            vec_count++;
            i--;
        }
    }
    cout << "какой мощности формируем множества?\n";
    int P;
    int c = 0;
    cin >> P;
    int amount_of_combinations;
    amount_of_combinations = (fact(vec_count)) / (fact(vec_count - P));
   // cout << amount_of_combinations;
    int* a = new int[vec_count];
    for (int i = 0; i < vec_count; i++) {
        a[i] = i;
    }
    for (int i = 0; i < P; i++) {
        int top = a[i];
        if (i == 0) {
            cout << "{";
        }
        for (auto ch : vec[top]) {
            cout << ch;
        }
        if (i == P - 1) {
            cout << "}";
        }
        else {
            cout << ",";
        }

    }
    cout << endl;

    while (switcc(a, vec_count, P) == true) {
        for (int i = 0; i < P; i++) {
            int top = a[i];
            if (i == 0) {
                cout << "{";
            }
            for (auto ch : vec[top]) {
                cout << ch;
            }
            if (i == P - 1) {
                cout << "}";
            }
            else {
                cout << ",";
            }

        }
        cout << endl;
    }
}








//do {
//    cout << endl<<"{";
//    for (int i = 0; i < P;i++) {
//        for (auto t : vec[(a[i])]) {
//            cout << t;
//        }
//        if (i != P - 1) {
//            cout << ",";
//        }
//    }
//    cout << "}";
//} while (next_permutation(a, a + vec_count));*/







  ////  cout << amount_of_combinations;
  //  int **matrix = new int* [amount_of_combinations];
  //  for (int i = 0; i < amount_of_combinations; i++)
  //      matrix[i] = new int[P];
  //  for (int i = 0; i < amount_of_combinations; i++) {
  //      for (int j = 0; j < P; j++) {
  //          matrix[i][j] = -100;
  //      }
  //  }
  //  int startlines = amount_of_combinations / (vec_count);
  //  int temp=-1;
  //  int m = 0,t=0;
  //  for (int i = 0; i < amount_of_combinations; i++) {
  //      if (i %startlines  == 0) {
  //          temp++;
  //      }
  //      matrix[i][0] = temp;
  //  }
  //  for (int j = 1; j < P; j++) {
  //      int mi = per(m, vec_count);
  //      for (int i = 0; i < amount_of_combinations; i++) {
  //          for (int t = 0; t < P; t++) {
  //              if (matrix[i][t] == mi) {
  //                  m++;
  //                  mi = per(m, vec_count);
  //                  t = 0;
  //              }
  //              if (t == P - 1) {
  //                 
  //                  matrix[i][j] = mi;
  //                  m++;
  //                  mi = per(m, vec_count);
  //              }
  //          
  //          }
  //      }
  //  }

  //  for (int i = 0; i < amount_of_combinations; i++) {
  //      for (int j = 0; j < P; j++) {
  //          cout << matrix[i][j];
  //      }
  //      cout << endl;
  //  }
//}
