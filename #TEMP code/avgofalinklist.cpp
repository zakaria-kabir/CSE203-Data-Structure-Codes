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
int avg(ListNode*a){
	int count=0;
	int sum=0;
	if(a==nullptr){
		return 0;
	}
	else if(a->next==nullptr){
		return a->data;
	}
	else{
		while(a->next!=nullptr){
			sum=sum+a->data;
			count++;
			a=a->next;
		}
		return (sum/count);
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
	cout<<avg(a)<<endl;
	
}