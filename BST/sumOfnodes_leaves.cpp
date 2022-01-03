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
int sumofnodeswithoutleaves(BinaryTreeNode *a)

{

	int rightsubtree, leftsubtree, sum = 0;

	if(a != NULL)

	{
		if(a->left!=nullptr|| a->right!=nullptr){
			leftsubtree = sumofnodeswithoutleaves(a->left);

			rightsubtree = sumofnodeswithoutleaves(a->right);

			sum = (a->data) + leftsubtree + rightsubtree;

			
		}

	}
	return sum;
}

int sumofnodesAll(BinaryTreeNode *a)

{

	int rightsubtree, leftsubtree, sum = 0;

	if(a != NULL)

	{
		
		leftsubtree = sumofnodesAll(a->left);

		rightsubtree = sumofnodesAll(a->right);

		sum = (a->data) + leftsubtree + rightsubtree;

		
		

	}
	return sum;
}
int sumLeaves(BinaryTreeNode*a){
	return sumofnodesAll(a)-sumofnodeswithoutleaves(a);
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
	cout<<sumofnodeswithoutleaves(a)<<endl;
	cout<<sumofnodesAll(a)<<endl;
	cout<<sumLeaves(a)<<endl;
}

