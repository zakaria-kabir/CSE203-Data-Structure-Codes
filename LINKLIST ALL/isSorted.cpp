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
bool isSorted(ListNode* x) 
{ 
	if (x == nullptr) 
		return true; 

	for (ListNode *z=x; z->next != nullptr; z=z->next) {
	if (z->data > z->next->data) 
			return false; 
	}
	return true; 
} 
/*
bool isSorted(ListNode* a)
{
	if (a == nullptr)
	{
		return true;
	}
	else if(a->next==nullptr){
		return true;
	}
    
	ListNode* current = a;
	while(current->next!=nullptr)
	{
		if (current->data > current->next->data)
			return false;	     	    
    current=current->next;
        

	}
    return true;
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
	cout<<isSorted (a);
}