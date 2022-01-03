#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
void add(node *& linklist,int value){
	if(linklist==nullptr){
		node* n=new node;
		//cout<<n<<endl;
		n->data=value;
		//n->data++;
		n->next=linklist;
		linklist=n;
		//cout<<linklist;
		//cout<<link;
		//cout<<value;
	}
	else{
		node*current =linklist;
		while(current->next!=nullptr){
			current =current->next;
		}
		node *a=new node;
		a->data=value;
		//a->data++;
		a->next=current->next;
		current->next=a;
	}
}
void print(node* x){//jodi ei khan e node*&x likhi taile 2nd print func kaj krbe na r
	while(x!=nullptr){
		cout<<x->data<<endl;
		x=x->next;
	}
}
int main(){
	node* a=nullptr;
	int n;
	int num;
	cout<<"how many :";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter number :";
		cin>>num;
		add(a,num);
	}
	//add(a,2);
	//add(a,4);
	//add(a,6);
	//cout<<a<<endl;
	node*x=a;
	while(x!=nullptr){
		cout<<x->data<<endl;
		x=x->next;
	}
	print(a);
	//print(a);
}