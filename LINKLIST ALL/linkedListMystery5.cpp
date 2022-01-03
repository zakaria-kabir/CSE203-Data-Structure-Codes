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
void linkedListMystery(ListNode*& front1, ListNode*& front2) {

while (front1->data < front2->data) {

ListNode* trash = front1;

front1 = front1->next;

delete trash;

}

ListNode* curr1 = front1;

ListNode* curr2 = front2;

while (curr1->next != nullptr && curr2->next != nullptr) {

if (curr1->next->data < curr2->next->data) {

ListNode* temp = curr1->next;

curr1->next = curr2->next;

curr2->next = temp;

} else {

curr2 = curr2->next;

}

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
	linkedListMystery(a,b);
	print(a);
	cout<<endl;
	print(b);
}