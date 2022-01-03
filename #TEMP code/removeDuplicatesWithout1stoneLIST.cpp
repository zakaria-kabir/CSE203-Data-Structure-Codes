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

void removeAll (ListNode*& a, int val) {
	ListNode* current = nullptr;
	ListNode*temp =nullptr;
	if (a == nullptr) {
		return;
	}
	ListNode* ptr1,*ptr2,*trash;
	ptr1=a;
	while(ptr1!=nullptr&&ptr1!=nullptr){
		ptr2=ptr1;
		if(ptr1->data==val){
		while(ptr2->next!=nullptr){	
				if(ptr1->data==ptr2->next->data){
					trash=ptr2->next;
					ptr2->next=ptr2->next->next;
					delete trash;
				}else
				ptr2=ptr2->next;
			}
			ptr1=ptr1->next;
		}
		else
			ptr1=ptr1->next;
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
	removeAll(a,100);

	print(a);
	
}