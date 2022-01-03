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
ListNode* switchEvens  (ListNode*& x, ListNode*& z) {
	int temp=0;
	if(x==nullptr && z==nullptr) {
		return nullptr;
	}
	else{
		ListNode* currentx=x;
		ListNode* currentz=z;
		while(currentx!=nullptr&&currentz!=nullptr){
			if(currentx->data%2==0 && currentz->data%2==0){
		temp=currentx->data;
		currentx->data=currentz->data;
		currentz->data=temp;
			}
			currentx=currentx->next;
			currentz=currentz->next;
	}

}
return 0;
}*/


ListNode* switchEvens  (ListNode* x, ListNode* z) 
{ 
	int temp=0;
	//ListNode* mrg = nullptr; 
	if(x==nullptr) {
		return nullptr;
	}
	else if(z==nullptr) {
		return nullptr;
	}
//if (x->data <= z->data) 
	//while(x!=nullptr&&z!=nullptr){
	if(x->data%2==0 && z->data%2==0)
	{ 
		//mrg = x; 
		temp=x->data;
		x->data=z->data;
		z->data=temp;


		
	}
	switchEvens  (x->next, z->next); // x=x->next;
		//z=z->next;
	return 0;
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
	switchEvens  (a,b);
	print(a);

	print(b);
}