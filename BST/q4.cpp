
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
	return hightHelper(node, n, 1);
}

void removeKthLeaf1(BinaryTreeNode*& node, BinaryTreeNode* n, int k) {
	if (node == nullptr)
		return;
	removeKthLeaf1(node->left, n, k);
	removeKthLeaf1(node->right, n, k);
	int h = hight(n, node->data);
	if ((node->left == nullptr && node->right == nullptr) && (h - 2) == k) {
		BinaryTreeNode* temp = node;
		node = nullptr;
		delete temp;
	}
}
void removeKthLeaf(BinaryTreeNode*&a,int n){
	if (a == nullptr)
	{
		return;
	}
	if(n<=0){
		throw -1010;
	}
	removeKthLeaf1(a,a,n);
}

int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 70);
	insert(a, 20);
	insert(a, 81);
	insert(a, 13);
	insert(a, 21);
	insert(a, 75);
	insert(a, 87);
	insert(a, 72);
	insert(a, 79);
	insert(a, 98);
	insert(a, 93);
	insert(a, 113);

	cout << "BST is: "; printbst(a); cout << endl;
	removeKthLeaf(a,3);
	printbst(a);
}
