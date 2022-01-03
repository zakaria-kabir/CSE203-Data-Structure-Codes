#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void insert(BinaryTreeNode*& bst, int n) {
	if (bst == nullptr) {
		bst = new BinaryTreeNode;
		bst->data = n;
		bst->right = nullptr;
		bst->left = nullptr;
	}
	else if (n > bst->data) {
		insert(bst->right, n);
	}
	else if (n < bst->data) {
		insert(bst->left, n);
	}
}

void printbst(BinaryTreeNode* bst) {
	if (bst == nullptr)
		return;
	printbst(bst->left);
	cout << bst->data << " ";
	printbst(bst->right);

}

BinaryTreeNode* rangeHelper(BinaryTreeNode*& node, int min, int max , int &count) {
	if (node == nullptr)
		return nullptr;
	node->left = rangeHelper(node->left, min, max, count);
	node->right = rangeHelper(node->right, min, max, count);
	BinaryTreeNode *current = node;
	if (node->data < min)
	{
		node = node->right;
		delete current;
		count++;
	}
	else if (node->data > max)
	{
		node = node->left;
		delete current;
		count++;

	}
	return node;
}
int range(BinaryTreeNode*& node, int min, int max) {
	if (min > max)
		throw - 404;
	int count = 0;
	rangeHelper(node, min, max, count);
	return count;
}

int main() {
	BinaryTreeNode* a = nullptr;
	int count = 0;
	insert(a, 50);
	insert(a, 38);
	insert(a, 90);
	insert(a, 14);
	insert(a, 42);
	insert(a, 54);
	insert(a, 8);
	insert(a, 20);
	insert(a, 72);
	insert(a, 26);
	insert(a, 61);
	insert(a, 83);

	cout << "BST is: "; printbst(a); cout << endl;
	cout << "number of removed elements :" << range (a, 99, 100) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;

}

