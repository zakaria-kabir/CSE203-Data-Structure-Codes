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
void remove (ListNode*& a,int n){
	ListNode* pre = a;
	if(a==nullptr){
		return;
	}
	if(n ==0){
		a=pre->next;
		delete pre;
		return;
	}
	
		for(int i=0;pre!=nullptr&&i<n-1;i++) {
			pre=pre->next;
		}
		if(pre==nullptr||pre->next==nullptr){
			return;
		}
			ListNode *aftr=pre->next->next;
			delete pre->next;
			pre->next=aftr;

}*/
void remove (ListNode*& a,int n){
	ListNode* current = a;
	ListNode * temp=nullptr;
	if(a==nullptr){
		return;
	}
	else if(n ==0){
		temp=a;
		a=a->next;
		delete temp;
	}
	
	else{
		for (int i = 0; i < n-1; ++i)
		{
			current=current->next;
		}
		temp=current->next;
		current->next=current->next->next;
		delete temp;
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
	remove(a,0);
	print(a);
	
}