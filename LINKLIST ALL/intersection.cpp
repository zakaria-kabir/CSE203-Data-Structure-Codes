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
ListNode* intersection (ListNode*& a,ListNode*& b){
	if(a==NULL||b==NULL){
		return NULL;
	}
	else{
		ListNode* ca=a;
		ListNode* cb=b;
		while(cb!=NULL){
			ca=a;
			while(ca!=NULL){
				if(ca->data==cb->data){
					return ca;
				}
				ca=ca->next;
			}
			cb=cb->next;
		}
	}
	return NULL;
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
	add(a,5);
	add(a,4);
	add(a,8);
	add(a,3);
	add(a,15);

	ListNode* b=NULL;
	add(b,2);
	add(b,6);
	add(b,8);
	add(b,3);
	add(b,15);

	ListNode* s=intersection (a,b);
	
	print(a);
	print(b);
	if(s){
		cout<<s->data;
	}
	else{
		cout<<"null";
	}
}