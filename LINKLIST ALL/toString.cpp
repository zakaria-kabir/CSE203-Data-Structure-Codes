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


string toString(ListNode* a){
	string s="";
	if(a==NULL){
		s="{}";
	}
	else{
		s="{";
		ListNode* c=a;
		while(c->next!=nullptr){
			s+=to_string(c->data)+", ";		
			c=c->next;
		}
		s+=to_string(c->data)+"}";
	}
	return s;
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
	add(a,4);
	add(a,7);
	add(a,3);
	add(a,9);
	add(a,1);
	

	string s=toString(a);
	print(a);
	cout<<s;
}