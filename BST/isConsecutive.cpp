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

bool isConsecutiveHelper ( BinaryTreeNode* bst,int prev){
	if(bst==nullptr){
		return true;
	}
	
	isConsecutiveHelper(bst->left,bst->data-1);
	if(bst->data!=prev){
		return false;
	}
	isConsecutiveHelper(bst->right,bst->data+1);
	
}
bool isConsecutive(BinaryTreeNode* bst){
	if(bst==nullptr){
		return true;
	}
	return isConsecutiveHelper(bst,bst->data);
}

int main() {
	BinaryTreeNode* a = nullptr;
	insert(a, 5);
	insert(a, 4);
	insert(a, 3);
	insert(a, 2);
	insert(a, 1);
	insert(a, 6);
	insert(a, 7);
	insert(a, 8);

	cout << "BST is: "; printbst(a); cout << endl;
	cout<<isConsecutive(a);
	//cout << "after BST is: "; printbst(a); cout << endl;
}

