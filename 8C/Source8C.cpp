#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;


struct Node {
	int key;
	Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k) {
	Node *y = NIL;
	Node *x = root;
	Node *z;


	z = (Node *)malloc(sizeof(Node));

	z->key = k;
	z->left = NIL;
	z->right = NIL;

	while (x != NIL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NIL) {
		root = z;
	}
	else {
		if (z->key < y->key) {
			y->left = z;

		}
		else {
			y->right = z;
		}
	}
}

Node* find(Node *x, int k) {

	while (x != NIL && k != x->key) {
		if (k < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

Node * treeMinimum(Node *x) {
	while (x->left != NIL)x = x->left;
	return x;
}
Node * treeSuccessor(Node *x) {
	if (x->right != NIL) return treeMinimum(x->right);
	Node *y = x->parent;
	while (y != NIL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}
void treeDelete(Node *z) {
	Node *y;//íœ‚·‚é‘ÎÛ
	Node *x;//y‚ÌŽq

	if (z->left == NIL || z->right == NIL)y = z;
	else y = treeSuccessor(z);

	if (y->left != NIL) {
		x = y->left;
	}
	else {
		x = y->right;
	}

	if (x != NIL) {
		x->parent = y->parent;
	}

	if (y->parent == NIL) {
		root = y;
	}
	else {
		if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}

	if (y != z) {
		z->key = y->key;
	}

	free(y);
}

void inorder(Node *u) {
	if (u == NIL)return;
	inorder(u->left);
	printf(" %d", u->key);
	inorder(u->right);
}

void preorder(Node *u) {
	if (u == NIL)return;
	printf(" %d", u->key);
	preorder(u->left);
	preorder(u->right);

}

int main() {
	int n, i, x;
	string com;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> com;
		if (com == "insert") {
			scanf("%d", &x);
			insert(x);
		}
		else if (com == "print") {
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");

		}
		else if (com == "find") {
			scanf("%d", &x);
			Node* no = find(root, x);
			if (no == NIL) {
				printf("no\n");
			}
			else {
				printf("yes\n");
			}

		}
		else if (com == "delete") {
			scanf("%d", &x);
			treeDelete(find(root, x));
		}
	}

	return 0;

}