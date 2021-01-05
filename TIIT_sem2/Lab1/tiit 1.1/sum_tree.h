#pragma once
#include <math.h>
#include <iostream>
#include <ctime>
struct Tree {
	int sum,num,l,r;
	Tree* left, * right;
};
Tree* createtree (int l, int r,int* array);
int Min(int a, int b);
int Max(int a, int b);
int findsum(Tree* root, int l, int r, int sumadd);
void change(Tree* root, int l, int r, int val);
void viewtree(Tree* p, int level);
void mainmenu();
void viewarray(Tree* root);
//void modify(Tree* root, int l, int r, int val);
//void input_array(int* array,int *i);
//int tree_size(int* a);