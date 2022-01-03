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
bool bstContains(BinaryTreeNode*& node, int value) {
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

BinaryTreeNode* hasPathHelper(BinaryTreeNode *&node, int x, int z, int& flag){
	if (node == nullptr)
		return nullptr;
	if (node->data == z && node->data == x) {
		flag = 1;
	}
	else if (z > node->data) {
		if (node->data == x) {
			flag = 1;
		}
		return hasPathHelper(node->right, x, z, flag);

	}
	else if (z < node->data) {
		if (node->data == x) {
			flag = 1;
		}
		return hasPathHelper(node->left, x, z, flag);

	}
}
bool hasPath(BinaryTreeNode*& node, int start, int end) {
	if (bstContains(node, start) && bstContains(node, end)) {
		int flag = 0;
		hasPathHelper(node, start, end, flag);
		if (flag == 1) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 67);
	insert(a, 38);
	insert(a, 152);
	insert(a, 16);
	insert(a, 42);
	insert(a, 99);
	insert(a, 40);
	cout << "BST is: "; printbst(a); cout << endl;
	if (hasPath(a, 38, 99)) {
		cout << " true ";
	}
	else {
		cout << " 	false ";
	}
	cout << "\nafter BST is: "; printbst(a); cout << endl;
}

