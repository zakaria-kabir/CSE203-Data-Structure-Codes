#include<bits/stdc++.h>
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
//by recursion
int findMindepth(node* n){

	if(n==nullptr){
		return 0;
	}
	if(n->left==nullptr&& n->right==nullptr){
		return 0;
	}
	if(n->left==nullptr){
		return findMindepth(n->right)+1;
	}
	if(n->right==nullptr){
		return findMindepth(n->left)+1;
	}
	return min(findMindepth(n->left),findMindepth(n->right))+1;
}

void printLevel(node* n,int &count,int min) {
	queue<node*> q;
	q.push(n);
	int numNodesEachLevel = 1;

	while (!q.empty()) {
		node* p = q.front();
		q.pop(); 
		//cout<<p->data<<" ";
		numNodesEachLevel -= 1;
		if(p->left==nullptr&&p->right==nullptr){
			return;
		}
		if (p->left != nullptr) 
			{ q.push(p->left); }
		if (p->right != nullptr) 
			{ q.push(p->right); }

		if (numNodesEachLevel == 0) {
			count++;
			numNodesEachLevel = q.size();
			//cout<<endl;
		}
	}

}
//by level
int MinDepthFind(node* n){
	if(n==nullptr){
		return 0;
	}
	int count=0;
	int min=0;
	printLevel(n,count,min);
	return count;
}

int main(){
node* a = nullptr;
	insert(a, 6);
	//insert(a, 2);
	insert(a, 9);
	//insert(a, 1);
	insert(a, 8);
	insert(a, 15);
	insert(a ,13);
	insert(a, 18);
	insert(a, 11);
	cout<<findMindepth(a)<<endl;
	//or
	cout<<MinDepthFind(a);
}

