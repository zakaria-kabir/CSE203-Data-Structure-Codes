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


ListNode* merge (ListNode*& x, ListNode*& z) 
{ 
	ListNode* mrg = nullptr; 
	if(x==nullptr) 
		return(z); 
	else if(z==nullptr) 
		return(x); 
	if (x->data <= z->data) 
	{ 
		mrg = x; 
		mrg->next = merge (x->next, z); 
	} 
	else
	{ 
		mrg = z; 
		mrg->next = merge (x, z->next); 
	} 
	return(mrg); 
} 



void print(ListNode* x){
	while(x!=nullptr){
		cout<<x->data<<" ";
		x=x->next;
	}
	cout<<endl;
}
int main(){
	ListNode* a=nullptr;
	ListNode* b=nullptr;
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
	int m;
	int nu;
	cout<<"how many :";
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"enter number :";
		cin>>nu;
		add(b,nu);
	}
	ListNode*z=b;
	while(z!=nullptr){
		z=z->next;
	}
	merge (a,b);
	print(a);
	print(b);
}