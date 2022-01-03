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
void removeAll (ListNode*& a, int val) {
	ListNode* current = nullptr;
	ListNode* prev =nullptr;
	ListNode*temp =nullptr;
	if (a == nullptr) {
		return;
	}
	while (a->data == val) {	
	temp=a; 
      a=a->next;
      delete temp;
      if(a==nullptr)
      	return;
	}
	
		
		pre=a;
		current=
		while (current->next!= nullptr) 
		{
			if (current->data == current->next->data) {
				temp=current->next;
				current->next=current->next->next;
				delete temp;
			}
			else
			current = current->next;

		}
			
		

	}
	*/
void removeAll (ListNode *&a, int n) 
{ 
	ListNode *temp = a;
	ListNode *prev=nullptr; 
	while (temp != nullptr && temp->data == n) 
	{ 
		a = temp->next; 
		delete temp;	
		temp = a;
	} 
	while (temp != nullptr) 
	{
		while (temp != nullptr && temp->data != n) 
		{ 
			prev = temp; 
			temp = temp->next; 
		} 
		if (temp == nullptr)
return; 
		prev->next = temp->next; 
		delete temp; 
		temp = prev->next; 
	} 
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
	removeAll(a,12);

	print(a);
	
}