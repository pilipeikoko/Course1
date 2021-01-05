// raschetka tiit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// sorri for shitcoding xc

#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int min(int a, int b) {
    if (a >= b) {
        return b;
    }
    return a;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int nodes;
    int edges;
    string path;
    cout << "введите номер теста\n";
    cin >> path;
    path = path + ".txt";
    ifstream fin(path);
    fin >> nodes >> edges;
    int** matrix = new int* [nodes + 1];
    for (int i = 0; i <= nodes; i++) {
        matrix[i] = new int[nodes * nodes + 1];
    }//создание матрицы


    bool** is_used = new bool* [nodes + 1];
    for (int i = 0; i <= nodes; i++) {
        is_used[i] = new bool[nodes + 1];
    }//создание матрицы


    matrix[0][0] = 0;
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes * nodes + 1; j++) {
            matrix[i][j] = 100000;
        }
    }//заполнение большими числами(соглсно алгоритму Флойда — Уоршелла)
    for (int i = 1; i <= nodes; i++) {
        matrix[i][0] = i;
    }//заполнение первого столбца номерами узлов
    for (int i = 1; i <= nodes * nodes + 1; i++) {
        matrix[0][i] = i;
    }//заполнение первой строки номерами связей
    int node1, node2, weight;
    for (int i = 1; i <= edges; i++) {
        fin >> node1 >> node2 >> weight;
        is_used[node1][node2] = true;
        //     is_used[node2][node1] = true;
        matrix[node1][i] = weight;
        matrix[node2][i] = -weight;
    }//заполнение матрицы инцедентности
   
    for (int k = 1; k <= nodes; k++) {
        for (int a = 0; a <= nodes; a++) {
            for (int s = 0; s <= nodes; s++) {
                is_used[a][s] = false;
            }
        }
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes * nodes + 1; j++) {
                if (matrix[i][j] >= 0) {
                    int temp = -matrix[i][j];
                    for (int t = 1; t <= nodes; t++) {
                        if (matrix[t][j] == temp) {
                            is_used[i][t] = true;

                            for (int o = 1; o <= nodes * nodes + 1; o++) {
                                if (matrix[i][o] == -matrix[k][o] && matrix[i][o] >= 0) {//eсть связь от i-того к k-тому
                                    for (int p = 1; p <= nodes * nodes + 1; p++) {
                                        if (matrix[k][p] == -matrix[t][p] && matrix[k][p] >= 0) {//есть связь от k-того k t-тому
                                            matrix[i][j] = min(matrix[i][j], matrix[i][o] + matrix[k][p]);
                                            matrix[t][j] = -matrix[i][j];
                                            is_used[i][t] = true;
                                            goto k;
                                        }
                                    }

                                }
                            }
                            goto k;
                        }
                    }//ot i-togo k t-tomu
                    for (int y = 1; y <= nodes; y++) {
                        if (matrix[y][j] != 100000) {
                            goto k;
                        }
                    }
                    //znachit v j-tom stolbe net svyazi
                    for (int u = 1; u <= nodes; u++) {
                        if (is_used[i][u] == false && i != u) {
                            is_used[i][u] = true;
                            //znachit nado stroit svyaz ot i-togo k u-tomu esli one budet
                            for (int o = 1; o <= nodes * nodes + 1; o++) {
                                if (matrix[i][o] == -matrix[k][o] && matrix[i][o] >= 0) {//est svyaz ot i-togo k k-tomu
                                    for (int p = 1; p <= nodes * nodes + 1; p++) {
                                        if (matrix[k][p] == -matrix[u][p] && matrix[k][p] >= 0) {//est svyaz to k-togo k u-tomu
                                            matrix[i][j] = min(matrix[i][j], matrix[i][o] + matrix[k][p]);
                                            matrix[u][j] = -matrix[i][j];
                                            goto k;
                                        }
                                    }
                                    
                                }
                            }                          
                            goto k;
                        }
                    }
                }
            k:
                int prosto;
            }
        }
    }
    int* maxes = new int[nodes + 1];
    int count = 0;
    for (int i = 1; i <= nodes; i++) {
        int max = -101;
        for (int j = 1; j <= nodes * nodes + 1; j++) {
            if (matrix[i][j] != 100000 && matrix[i][j] >= max && matrix[i][j] >= 0) {
                max = matrix[i][j];
            }
        }
        if (max != -101) {
            maxes[count] = max;
            count++;
        }
    }
    int min = maxes[0];
    for (int p = 1; p < count; p++) {
        if (maxes[p] < min) {
            min = maxes[p];
        }
    }

    cout << endl << "радиус графа равен " << min;
}