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
void alternatingNode(ListNode * odd,  ListNode* even)
{
	if (odd == NULL || even == NULL) {
		return;
	}
	if (odd->next) {
		odd->next = odd->next->next;
	}
	if (even->next) {
		even->next = even->next->next;
	}
	alternatingNode(odd->next, even->next);
}
void split( ListNode* source,  ListNode** bRef, ListNode** aRef)
{
	*bRef = source;
	*aRef = source->next;
	alternatingNode(*bRef, *aRef);
}
ListNode* transferEvens (ListNode*& a){
	ListNode *b=NULL;
	if(a==NULL){
		b= NULL;
	}
	else{
		split(a,&b,&a);
	}
	return b;

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
	add(a,3);
	add(a,1);
	add(a,4);
	add(a,15);
	add(a,9);
	add(a,2);
	add(a,6);
	add(a,5);
	add(a,35);
	add(a,89);
	add(a,66);

	ListNode*b= transferEvens(a);
	print(a);
	print(b);
}