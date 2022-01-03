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
int getLen(ListNode* x){
	int count=0;
	while(x!=nullptr){
		x=x->next;
		count++;
	}
	return count;
}
void deleteBack(ListNode*& front) {

	ListNode*t=front;
	if(front == nullptr) {throw "error";}
	else if (front->next==NULL){ 
		front=NULL;delete front; }
		else { while(t->next->next!=NULL){
			t=t->next;
		} 
		
		t->next=nullptr;
		delete t->next;

	}
}
void deleteFront(ListNode*& front)
{
    
    ListNode* temp = front;
    front = front->next;
    delete temp;
}
void chopBothSides(ListNode*& a,int k){
	if(k<=0||a==nullptr){
		return;
	}
	int size=getLen(a);
	if(size<k*2){
		throw 404;
	}
	if(k==2*size){
		a=nullptr;
	}
	else{
		for(int i=0;i<k;i++){
			deleteFront(a);
			deleteBack(a);
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
	//add(a,66);
	print(a);
	chopBothSides(a,5);
	
	print(a);
}