#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <set>
#include <algorithm>
#include "stdio.h" 

using namespace std;
int root[100000];
bool is_used[100000];
pair <int, pair<int, int> > p[100000];
set<int> a[10000];
int sets;

int root_find(int x)
{
    while (root[x] != x)
    {
        root[x] = root[root[ x]];
        x = root[x];
    }
    return x;
}

int Minimal_way(int edges)
{
    int x, y,Rx,Ry;
    int cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i){
        cost = p[i].first;
        x = p[i].second.first;
        y = p[i].second.second;
        Rx = root_find(x);
        Ry = root_find(y);
        if (Rx != Ry) {
            minimumCost += cost;
            root[Rx] = root[Ry];
        }
    }
    return minimumCost;
}

int main()
{
    FILE* fp;
    unsigned int start_time = clock(); // начальное время
    fstream input("input.txt", ios_base::in | ios_base::binary);
    ofstream fout("output.txt");
    ifstream fin;
    int x, y, nodes, edges, weight, cost, minimumCost;
    input >> nodes >> edges;
    if (edges >= nodes) {
        for (int i = 0; i < edges; ++i)
        {
            root[i] = i;
            input >> x >> y >> weight;
            p[i] = make_pair(weight, make_pair(x, y));
        }
    }
    else {
        int j;
        for (j = 0; j < edges; ++j) {
            root[j] = j;
            input >> x >> y >> weight;
            p[j] = make_pair(weight, make_pair(x, y));
        }
        for (int i = j; i <= nodes; i++) {
            root[i] = i;
        }
    }
    unsigned int end_time = clock(); // конечное время
    cout << end_time - start_time << "after reading" << endl; // искомое время
    sort(p, p + edges);
    end_time = clock(); // конечное время
    cout << end_time - start_time << "after sort\n"; // искомое время
    minimumCost = Minimal_way(edges);
    end_time = clock(); // конечное время
    cout << end_time - start_time<<"after all"; // искомое время
    fout << minimumCost << endl;
    return 0;
}
