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

int countLeftNodes(BinaryTreeNode* node) {
	if (node == nullptr) {
		return 0;
	}
	else if (node->left == nullptr) {
		return countLeftNodes(node->right);//return 0;
	}
	else {
		return 1 + countLeftNodes (node->left) + countLeftNodes (node->right);
	}
}

int main() {
	BinaryTreeNode* a = nullptr;
	int count = 0;
	insert(a, 11);
	insert(a, 2);
	insert(a, 20);
	insert(a, 15);
	insert(a, 28);
	insert(a, 14);
	insert(a, 1);
	insert(a, 4);
	insert(a, 3);

	cout << "BST is: "; printbst(a); cout << endl;
	cout << "countLeftNodes :" << countLeftNodes (a) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;

}

