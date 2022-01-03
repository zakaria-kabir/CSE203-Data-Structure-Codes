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

void remove (ListNode*& a,int n){
	ListNode* current = a;
	ListNode * temp=NULL;
	if(a==NULL){
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
void combineDuplicates (ListNode*& head){
	if(head==NULL){
		return;
	}
	ListNode *c=head;
	int count=0;
	int pos=0;
	while(c->next!=NULL){
	
		
		while(c->data==c->next->data){
			count++;
			if(c->next!=NULL){
			
				c=c->next;pos++;
			}
			if(c->next==NULL){
				break;
			}

		}
		if((c->next!=NULL)||(count>0)){
		if((count>0)){
			for(int i=0;i<count;i++){
				remove(head,pos-1);
				pos--;
			}
			c->data=c->data*(count+1);
			count=0;
		}
	if(c->next!=NULL){
	
				c=c->next;	pos++;
			}
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
	add(a,3);
add(a,3);
add(a,2);
add(a,4);
add(a,4);
add(a,4);
add(a,-1);
add(a,-1);
add(a,4);
add(a,12);
add(a,12);
add(a,12);
add(a,3);
add(a,48);
add(a,-5);

add(a,-5);
	print(a);
	combineDuplicates(a);
	print(a);
	
}