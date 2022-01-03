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
int depthSumHelper(BinaryTreeNode* node, int x) {
	if (node == nullptr) {
		return 0;
	}
return (x * node->data + depthSumHelper(node->left, x + 1) + depthSumHelper(node->right, x + 1));
}
int depthSum(BinaryTreeNode*& node) {
	int x = 1;
	return depthSumHelper(node, x);
}

int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 10);
	insert(a, 7);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 24);
	insert(a, 8);
	insert(a, 25);

	cout << "BST is: "; printbst(a); cout << endl;
	cout << "depthSum :" << depthSum (a) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;
}

