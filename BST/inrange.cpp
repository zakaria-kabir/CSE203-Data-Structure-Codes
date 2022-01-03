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

int minValue(BinaryTreeNode* a){
	if(a==nullptr){
		return -332313;
	}
	if(a->left == nullptr){
		return a->data;
	}
	return minValue(a->left);
}
void removedata(BinaryTreeNode*& n, int i) {
	
	if (n == nullptr) { return; }
	else if (i > n->data) {
		removedata(n->right, i);
	}
	else if (i < n->data) {
		removedata(n->left, i);
	}
	else if (i == n->data) {
		if (n->right == nullptr && n->left == nullptr) {
			n = nullptr;
		}
		else if (n->right == nullptr) {
			n = n->left;
		}
		else if (n->left == nullptr) {
			n = n->right;
		}
		else {
			int min = minValue(n->right);
			n->data = min;
			removedata(n->right, min);
		}
	}
}
void rangehelper(BinaryTreeNode*& node, int min, int max,int &count) {
	if (node==nullptr)
		return;
	rangehelper(node->left, min, max, count);
	
	rangehelper(node->right, min, max, count);
	if (node->data >= min && node->data <= max)
	{
		count++;
		removedata(node,node->data);
	}

}

int range(BinaryTreeNode*& node, int min, int max) {
	if (min > max)
		throw - 404;
	int count = 0;
	rangehelper(node, min, max, count);
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
	cout << "number of removed elements :" << range (a,87,90) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;

}

/*
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
BinaryTreeNode* deletenode(BinaryTreeNode*& node,  int &count)
{
	BinaryTreeNode* curr = node;
	BinaryTreeNode* prev = nullptr;
	BinaryTreeNode* temp=nullptr;

	count++;
	if (curr->left == nullptr || curr->right == nullptr) {
		
		if (curr->left == nullptr){
			temp = curr->right;
		}
		else{
			temp = curr->left;
		}

		if (prev == nullptr){
			return temp;
			prev->left = temp;
		}
		else{
			prev->right = temp;
		}


		delete(temp);
	}
	else {
		BinaryTreeNode* curr1 = nullptr;

		temp = curr->right;
		while (temp->left != nullptr) {
			curr1 = temp;
			temp = temp->left;
		}
		if (curr1 != nullptr){
			curr1->left = temp->right;
		}

		else{
			curr->right = temp->right;
		}

		curr->data = temp->data;
		
		delete(temp);
	}

	return node;
}
BinaryTreeNode* rangeHelper(BinaryTreeNode*& node, int min, int max , int &count) {
	if (node == nullptr)
		return nullptr;
	node->left = rangeHelper(node->left, min, max, count);
	node->right = rangeHelper(node->right, min, max, count);
	BinaryTreeNode *current = node;
	if (node->data >= min && node->data <= max)
	{
		node= deletenode(node,  count);
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
	cout << "number of removed elements :" << range (a, 52, 72) << endl;
	cout << "after BST is: "; printbst(a); cout << endl;

}
*/
