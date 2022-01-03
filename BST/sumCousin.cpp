/*
#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void insert(BinaryTreeNode*& node, int value) {
	if (node == nullptr) {
		node = new BinaryTreeNode;
		node->data = value;
		node->right = nullptr;
		node->left = nullptr;
	}
	else if (value > node->data) {
		insert(node->right, value);
	}
	else if (value < node->data) {
		insert(node->left, value);
	}
}

void printbst(BinaryTreeNode* bst) {
	if (bst == nullptr)
		return;

	printbst(bst->left);
	cout << bst->data << " ";
	printbst(bst->right);

}
bool bstContains(BinaryTreeNode* node, int value) {
	if (node == nullptr)
		return false;
	if (node->data == value)
		return true;
	bool flag = bstContains(node->right, value);
	if (flag == true)
		return true;
	bool flag1 =  bstContains(node->left, value);
	return flag1;
}

int hightHelper(BinaryTreeNode*& node, int n, int x) {
	if (node == nullptr)
		return 0;

	if (node->data == n)
		return x;

	int h = hightHelper(node->left, n, x + 1);
	if (h != 0)
		return h;
	return hightHelper(node->right, n, x + 1);
}


int hight(BinaryTreeNode *node, int n) {
	if (bstContains(node, n))
		return hightHelper(node, n, 0);
	else
		return -100;
}


void getALL(BinaryTreeNode *node,	queue<int> &q, int level, int current)
{

	if (node)
	{
		if (level == current)
			q.push(node->data);
		else
		{
			getALL(node->right, q, level, current + 1);
			getALL(node->left, q, level, current + 1);
		}
	}
}
void findParent(BinaryTreeNode* node, int val, int parent, queue<int>& s, int n)
{
	if (node == NULL)
		return;

	if (node->data == val) {
		s.push(parent);

	}
	else { 
		findParent(node->left, val, node->data, s, n);
		findParent(node->right, val, node->data, s, n);
	}
}

int sumCousin(BinaryTreeNode *node, int n) {
	queue<int>q;
	queue<int>q1;
	int z = 0;
	int sum = 0;
	z = hight(node, n);
	getALL(node, q, z, 0);
	int sz = q.size();
	for (int i = 0; i < sz; i++) {
		int a = q.front();
		findParent(node, a, -1, q1, n);
		q.pop();
		q.push(a);
	}
	int m = q1.size();
	for (int i = 0; i < m; i++) {
		int o = q1.front();
		q1.pop();
		q1.push(o);
		int p = q.front();
		q.pop();
		q.push(p);
		if (p == n) {
			int r = o;
			while (!q1.empty()) {
				int f = q1.front();
				q1.pop();
				int u = q.front();
				if (u == n || f == r) {
					q.pop();
				} else {
					q.pop();
					q.push(u);
				}

			}
			break;
		}
	}

	while (!q.empty()) {
		int ss = q.front();
		q.pop();
		cout << ss << " + ";
		sum = sum + ss;
	}
	cout << "\b\b\b" << " = ";
	return sum;
}


int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 10);
	insert(a, 4);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 20);
	insert(a, 7);
	insert(a, 25);
	insert(a, 5);
	insert(a, 8);
	insert(a, 22);
	insert(a, 26);

	cout << "BST is: "; printbst(a); cout << endl;
	cout << "sumCousin : " ;
	cout << sumCousin(a, 22) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;
}

*/
#include <iostream>
#include<queue>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
};
void insert(node*& n, int i) {
	if (n == nullptr) {
		n = new node;
		n->data = i;
		n->right = nullptr;
		n->left = nullptr;
	}
	else if (i > n->data) {
		insert(n->right, i);
	}
	else if (i < n->data) {
		insert(n->left, i);
	}
}
void insertinQ(node* a, queue<int>& q) {
	if (a == nullptr) {
		return;
	}
	insertinQ(a->left, q);
	q.push(a->data);
	insertinQ(a->right, q);
}
void printData(node* a) {
	if (a == nullptr) {
		return;
	}
	printData(a->left);
	cout << a->data << " ";
	printData(a->right);
}
void heightHelper(node* n, int d, int& h) {
	if (n == nullptr) {
		if (d > h) {
			h = d;
		}
		return;
	}
	d = d + 1;
	heightHelper(n->left, d, h);
	heightHelper(n->right, d, h);
}
int height(node* n) {
	int d = -1; int h = -1;
	heightHelper(n, d, h);
	return h;
}
void Levels(node* n) {
	int f = n->data;
	queue<node*> q;
	q.push(n);
	int numNodesEachLevel = 1;
	int sum = 0;
	int c = 2; int final = 0;
	while (!q.empty()) {
		node* p = q.front();
		q.pop();
		numNodesEachLevel -= 1;
		cout << p->data << " ";
		if (p->left != nullptr) {
			q.push(p->left);
		}
		if (p->right != nullptr) {
			q.push(p->right);
		}
		if (numNodesEachLevel == 0) {	
			numNodesEachLevel = q.size();
			cout << endl;
	  	}}}
  int cousin(node* a, int&par, int val, int height) {
	if (a == nullptr) {
		return 0;
	}
	if (a->data == val) {
		return height;
	}
	par = a->data;
	int leftH = cousin(a->left, par, val, height + 1);
	if (leftH != 0) {
	return leftH;
	}
	else {
		par = a->data;
		int rightH = cousin(a->right, par, val, height + 1);
		return rightH;
	}
	return 0;
}
  int sumCousin(node* a, int b) {
	int FinalSum = 0;
	int height = 0;
	int parB = -1;
	int m= cousin(a, parB, b, height);
	queue<int>q;
	insertinQ(a,q);
	while (!q.empty()) {
	int height = 0;
	int parX = -1;
	int k = q.front();
	q.pop();
	int h = cousin(a, parX, k, height);
	if (m == h && parB != parX) {
			FinalSum = FinalSum + k;
		}}
	return FinalSum;
}
int main() {
	node* a = nullptr;
	insert(a, 10);
	insert(a, 4);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 20);
	insert(a  ,7);
	insert(a, 25);
	insert(a, 5);
	insert(a, -8);
	insert(a, 22);
	insert(a, 26);
	cout << "BST: ";
	printData(a);
  cout<<endl;cout<<endl;Levels(a);
	 cout << endl;
	cout<<"Sum of cousins is: "<<sumCousin(a, 8);
	return 0;
}