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

	return hightHelper(node, n, 0);
}
int getDistance(BinaryTreeNode* node, int a, int b) {
	if (a > b) {
		int n = a;
		a = b;
		b = n;
	}
	if (bstContains(node, a) && bstContains(node, b)) {
		if (node == nullptr)
			return 0;
		else if (node->data > a && node->data > b)
			return getDistance(node->left, a, b);
		else if (node->data < a && node->data < b)
			return getDistance(node->right, a, b);
		else if (node->data >= a && node->data <= b)
			return hight(node, a) +  hight(node, b);
	}
	else {
		return -1;
	}
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
	insert(a, 18);
	insert(a, 25);
	insert(a, 5);
	insert(a, 8);
	insert(a, 22);
	insert(a, 26);

	cout << "BST is: "; printbst(a); cout << endl;
	cout << "getDistance :" << getDistance (a, 18, 26) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;
}

