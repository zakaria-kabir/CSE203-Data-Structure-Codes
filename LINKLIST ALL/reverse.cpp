#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode* next;
};
void add(ListNode *& linklist,int value){
	if(linklist==nullptr){
		ListNode* n=new ListNode;
		n->data=value;
		n->next=linklist;
		linklist=n;
	
	}
	else{
		ListNode*current =linklist;
		while(current->next!=nullptr){
			current =current->next;
		}
		ListNode *a=new ListNode;
		a->data=value;
		a->next=current->next;
		current->next=a;
	}
}
/*
void reverse(ListNode* a) {
	if (a == nullptr) {
		return;
	}
	else{
		reverse(a->next);
		cout<<a->data<<" ";
	}
}
*/
int reverse (ListNode*& x){
	ListNode *p;
	ListNode *c;
	ListNode *n;
	p=nullptr;
	c=x;
	n=nullptr;
	while(c!=nullptr){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	x=p;
}
void print(ListNode* x){
	while(x!=nullptr){
		cout<<x->data<<" ";
		x=x->next;
	}
	cout<<endl;
}
/*
ListNode* reverse(ListNode* a){
	ListNode* rev=nullptr;
	while(a!=nullptr){
		ListNode*n=new ListNode;
		n->data=a->data;
		n->next=rev;
		rev=n;
		a=a->next;
	}
	print(rev);
}
*/

int main(){
	ListNode* a=nullptr;
	int n;
	int num;
	cout<<"how many :";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter number :";
		cin>>num;
		add(a,num);
	}
	ListNode*x=a;
	while(x!=nullptr){
		x=x->next;
	}
	reverse (a);
	print(a);
	
}