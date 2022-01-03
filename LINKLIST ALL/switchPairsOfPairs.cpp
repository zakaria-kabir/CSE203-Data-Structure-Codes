#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode* next;
};
void add(ListNode *& linklist,int value){
	if(linklist==NULL){
		ListNode* n=new ListNode;
		n->data=value;
		n->next=linklist;
		linklist=n;

	}
	else{
		ListNode*current =linklist;
		while(current->next!=NULL){
			current =current->next;
		}
		ListNode *a=new ListNode;
		a->data=value;
		a->next=current->next;
		current->next=a;
	}
}
void switchPairsOfPairs(ListNode*& a){
	if(a!=nullptr&&a->next!=nullptr&&a->next->next!=nullptr&&a->next->next->next!=nullptr){
		ListNode *c=a->next->next;
		a->next->next=c->next->next;
		c->next->next=a;
		a=c;
		c=c->next->next->next;
		while(c->next!=nullptr&&c->next->next!=nullptr&&c->next->next->next!=nullptr&&c->next->next->next->next!=nullptr){
			ListNode *temp=c->next->next->next;
			c->next->next->next=temp->next->next;
			temp->next->next=c->next;
			c->next=temp;
			c=temp->next->next->next;
		}
	}
}
void print(ListNode* x){
	while(x!=NULL){
		cout<<x->data<<" ";
		x=x->next;
	}
	cout<<endl;
}
int main(){
	ListNode* a=NULL;
	add(a,1);
	add(a,2);
	add(a,3);
	add(a,4);
	add(a,5);
	add(a,6);
	add(a,7);
	add(a,8);
	
	print(a);
	switchPairsOfPairs(a);
	print(a);

}