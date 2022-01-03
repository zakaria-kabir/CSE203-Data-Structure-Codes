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

ListNode* next = curr->next;

while (next != nullptr) {

if (curr->data % 5 == 0) {

front = front->next;

} else if (curr->data % 2 == 0 && next->data % 2 == 0) {

curr->next = next->next;

} else if (curr->data % 3 == 0) {

next->data++;

curr->data--;

curr = next;

}

curr = next;

next = next->next;

}

}
void print(ListNode* x){
	while(x!=nullptr){
		cout<<x->data<<" ";
		x=x->next;
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