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

// Iterative Function to delete 
// 'key' from the BST. 
BinaryTreeNode* deleteIterative(BinaryTreeNode* root, int key) 
{ 
    BinaryTreeNode* curr = root; 
    BinaryTreeNode* prev = NULL; 
  
    // Check if the key is actually 
    // present in the BST. 
    // the variable prev points to 
    // the parent of the key to be deleted. 
    while (curr != NULL && curr->data != key) { 
        prev = curr; 
        if (key < curr->data) 
            curr = curr->left; 
        else
            curr = curr->right; 
    } 
  
    if (curr == NULL) { 
        cout << "Key " << key 
             << " not found in the"
             << " provided BST.\n"; 
        return root; 
    } 
  
    // Check if the node to be 
    // deleted has atmost one child. 
    if (curr->left == NULL 
        || curr->right == NULL) { 
  
        // newCurr will replace 
        // the node to be deleted. 
        BinaryTreeNode* newCurr; 
  
        // if the left child does not exist. 
        if (curr->left == NULL) 
            newCurr = curr->right; 
        else
            newCurr = curr->left; 
  
        // check if the node to 
        // be deleted is the root. 
        if (prev == NULL) 
            return newCurr; 
  
        // check if the node to be deleted 
        // is prev's left or right child 
        // and then replace this with newCurr 
        if (curr == prev->left) 
            prev->left = newCurr; 
        else
            prev->right = newCurr; 
  
        // free memory of the 
        // node to be deleted. 
        cout<<curr->data<<endl;
        free(curr); 
    } 
  
    // node to be deleted has 
    // two children. 
    else { 
        BinaryTreeNode* p = NULL; 
        BinaryTreeNode* temp; 
  
        // Compute the inorder successor 
        temp = curr->right; 
        while (temp->left != NULL) { 
            p = temp; 
            temp = temp->left; 
        } 
  
        // check if the parent of the inorder 
        // successor is the root or not. 
        // if it isn't, then make the 
        // left child of its parent equal to the 
        // inorder successor's right child. 
        if (p != NULL) 
            p->left = temp->right; 
  
        // if the inorder successor was the 
        // root, then make the right child 
        // of the node to be deleted equal 
        // to the right child of the inorder 
        // successor. 
        else
            curr->right = temp->right; 
  
        curr->data = temp->data; 
           cout<<temp->data<<endl;
     
        free(temp); 
    } 

    return root; 
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

	printbst(a); cout << endl;
deleteIterative (a,8) ;
	printbst(a); cout << endl;

}