#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode* next;
};
ListNode* head=nullptr;
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


void addFront(ListNode*& x,int n){
	ListNode* temp=new ListNode;//-->temp node crt krtesi jar majhe junk data ache
	//ListNode* temp=new ListNode(n);-->eta mane temp node crt krtesi with data =n;
	cout<<temp->data<<endl;
	if(temp==nullptr){
		return;
	}
	else if(x==nullptr){
		temp->data=n;//ei line lagbe na jokhon ListNode* temp=new ListNode(n); likhbo
		temp->next=nullptr;
		x=temp;

	}
		
	else{
		temp->data=n;//-->then eikhan e junk re replace kore n bosaitesi (ei line lagbe na jokhon ListNode* temp=new ListNode(n); likhbo)
		temp->next=x;
		x=temp;
	}
}

/*
void addFront(ListNode*& front, int value) {

    ListNode* new_node = new ListNode(value);  
    //new_node->data = value; 
   new_node->next =front;  
    front = new_node; 
    }

*/

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
	print(a);
	cout<<endl;
	addFront(a,42);
	print(a);
}