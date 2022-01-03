#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

// Data structure to store a Binary Tree node
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 
void insert(Node*& node, int value) {
	if (node == nullptr) {
		node = new Node;
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
// Recursive function to check if given binary tree is height balanced or not
int isHeightBalanced(Node* root, bool& isBalanced)
{
    if (root == nullptr || !isBalanced)
        return 0;
    int left_height = isHeightBalanced(root->left, isBalanced);
    int right_height = isHeightBalanced(root->right, isBalanced);
    if (abs(left_height - right_height) > 1)
        isBalanced = false;
    return max(left_height, right_height) + 1;
}

bool isHeightBalanced(Node* root)
{
    bool isBalanced = true;
    isHeightBalanced(root, isBalanced);

    return isBalanced;
}

int main()
{
   Node* a=nullptr;
   insert(a, 1);
	insert(a, 2);
	insert(a, 3);
	insert(a, 4);
insert(a, 5);
insert(a, 6);
insert(a, 7);
    cout<<isHeightBalanced(a);

    return 0;
}