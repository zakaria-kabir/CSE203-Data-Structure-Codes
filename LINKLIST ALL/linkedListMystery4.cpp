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
void linkedListMystery(ListNode*& front) {

ListNode* curr = front;

while (curr->next != nullptr) {

ListNode* temp = curr->next;

if (curr->data >= curr->next->data) {

curr->next = temp->next;

if (curr->data == temp->data) {

curr->next = temp->next;

delete temp;

} else {

temp->next = front;

front = temp;

}

} else {

curr = curr->next;

}

}

}
void print(ListNode* a){
	while(a!=nullptr){
		cout<<a->data<<" ";
		a=a->next;
	}
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
	linkedListMystery(a);
	print(a);
	
	
}