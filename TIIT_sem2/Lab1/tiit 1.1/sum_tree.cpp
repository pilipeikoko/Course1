#include "sum_tree.h"
using namespace std;


int Max(int a, int b) {
	if (a >= b) return a;
	return b;
}

int Min(int a, int b) {
	if (a >= b) return b;
	return a;
}

void mainmenu() {
	cout << "\n1:создать дерево\n2:показ дерева\n3:найти сумму на отрезке\n4:заменить числа на отрезке\n5:показать массивом\n";
}

Tree* createtree (int l, int r,int *array) {
	srand(l+r);
	Tree* root = new Tree;
	root->l = l;
	root->r = r;
	root->sum = 0;
	if (l == r)
		root->num = rand() % 50;
	else root->num = 0;

	if(l < r) {
		root->left = createtree(l, (l + r) / 2, array);
		root->right = createtree((l + r) / 2 + 1, r, array);
		root->sum = root->left->sum + root->left->num + root->right->sum + root->right->num;
	}
	else {
		root->left = nullptr;
		root->right = nullptr;
	}
	return root;
}

int findsum(Tree* root, int l, int r, int sumadd) {

	if (l <= root->l && root->r <= r) {
		return sumadd + root->num+root->sum;
	}
	if (root->r < l || r < root->l) {
		return 0;
	}
	return findsum(root->right, l, r, sumadd) +	findsum(root->left,l,r,sumadd);
}


void change(Tree* root, int l, int r, int val) {
	if (root) {
		change(root->right, l, r, val);
		if (root->r == root->l && root->l >= l && root->l <= r) {
			root->num = val;
		}
		change(root->left, l, r, val);
		if (root->left && root->right) {
			root->sum = root->left->num + root->left->sum + root->right->num + root->right->sum;
		}
	}
}




void viewtree(Tree* p, int level) {
	if (p) {
		viewtree(p->right, level + 1);
		for (int i = 0; i < level; i++)cout << "       ";
		cout <<"l-"<< p->l<<" r-"<<p->r<<" num-"<<p->num<<" sumprevs-"<<p->sum   << endl<<endl;
		viewtree(p->left, level + 1);
	}
 }

void viewarray(Tree* p) {
	if (p) {
		viewarray(p->left);
		if (!p->right && !p->left) {
			cout << p->num << " ";
		}
		viewarray(p->right);
	}
}