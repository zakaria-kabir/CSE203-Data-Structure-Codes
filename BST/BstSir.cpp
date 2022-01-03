#include <iostream>
using namespace std;

struct node {
	int data = 0;
	node* right = nullptr;
	node* left = nullptr;
};

void insert(node*& n, int i) {
	if (n == nullptr) {
		n = new node;
		n->data = i;
		n->right = nullptr;
		n->left = nullptr;
	}
	else if (i > n->data) {
		insert(n->right, i);
	}
	else if (i < n->data) {
		insert(n->left, i);
	}
}

bool find(node* n, int i) {
	if (n == nullptr) {
		return false;
	}
	if (n->data == i) {
		return true;
	}
	else if (i > n->data) {
		return find(n->right, i);
	}
	else if (i < n->data) {
		return find(n->left, i);
	}
}

void printData(node* a) {
	if (a == nullptr) {
		return;
	}
	printData(a->left);
	cout << a->data << " ";
	printData(a->right);
}

int minValue(node* a) {
	if (a == nullptr) {
		return NULL;
	}
	if (a->left == nullptr) {
		return a->data;
	}
	else {
		return minValue(a->left);
	}
}

int maxValue(node* a) {
	if (a == nullptr) {
		return NULL;
	}
	if (a->right == nullptr) {
		return a->data;
	}
	else {
		return maxValue(a->right);
	}
}

void remove(node*& n, int i) {
	if (n == nullptr) { return; }
	else if (i > n->data) {
		remove(n->right, i);
	}
	else if (i < n->data) {
		remove(n->left, i);
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
			remove(n->right, min);
		}

	}
}

int numLeaves(node* a) {
	if (a == nullptr) {
		return NULL;
	}
	else if (a->left == nullptr && a->right == nullptr) {
		return 1;
	}
	return (numLeaves(a->right) + numLeaves(a->left));
}
int numNodes(node* a) {
	if (a == nullptr) {
		return NULL;
	}
	return 1 + numNodes(a->left) + numNodes(a->right);
}
void findPosition(node* a, int i, int &count) {
	if (a == nullptr) {
		return;
	}
	count = count + 1;
	if (a->data == i) {
		return ;
	}
	findPosition(a->left, i, count);
	findPosition(a->right, i, count);
}

int depthHelper(node* a, int i) {
	if (a == nullptr) {
		return -100000;
	}
	else if (a->data == i) {
		return 0;
	}
	else if (i > a->data) {
		return depthHelper(a->right, i) + 1;
	}
	else if (i < a->data) {
		return depthHelper(a->left, i) + 1;
	}
}

int depth(node* a, int i) {
	if (depthHelper(a, i) < 0) {
		return -1;
	}
	else {
		return depthHelper(a, i);
	}
}
void heightHelper(node* n, int d, int& h) {
	if (n == nullptr) {
		if (d > h) {
			h = d;
		}
		return;
	}
	d = d + 1;
	heightHelper(n->left, d, h);
	heightHelper(n->right, d, h);
}
int height(node* n) {
	int d = -1; int h = -1 ;
	heightHelper(n, d, h);
	return h;
}

void printArr(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printPathHelper(node* n, int* arr, int index) {
	if (n == nullptr) {
		return;
	}
	// Arr -> number of nodes - 5, arr size 5 
	// index = 0;
	// 0 -> 9
	//1->6
	arr[index] = n->data;
	index = index + 1;
	if (n->left == nullptr && n->right == nullptr) {
		printArr(arr, index);
	}
	printPathHelper(n->left, arr, index);
	printPathHelper(n->right, arr, index);
}
void printPath(node* n) {
	int* arr = new int[numNodes(n)];
	int index = 0;
	printPathHelper(n, arr, index);
}
#include <queue>
void printLevel(node* n) {
	queue<node*> q;
	q.push(n);
	int numNodesEachLevel = 1;

	while (!q.empty()) {
		node* p = q.front();
		q.pop(); 
		numNodesEachLevel -= 1;
		cout << p->data << " ";

		//Push the children of the ousted parent 
		//into the queue
		if (p->left != nullptr) { q.push(p->left); }
		if (p->right != nullptr) { q.push(p->right); }

		if (numNodesEachLevel == 0) {
			numNodesEachLevel = q.size();
			cout << endl;
		}
	}

}


int main() {
	node* a = nullptr;
	insert(a, 10);
	insert(a, 4);
	insert(a, 16);
	insert(a, 3);
	insert(a, 9);
	insert(a, 20);
	insert(a  ,7);
	insert(a, 25);
	insert(a, 5);
	insert(a, 8);
	insert(a, 22);
	insert(a, 26);
	//printData(a);
	//cout << "Height of a tree: " << height(a) << endl;
	//cout << "Depth of a node: " << depth(a, 9) << endl;
	//printPath(a);
	printLevel(a);
	return 0;
}