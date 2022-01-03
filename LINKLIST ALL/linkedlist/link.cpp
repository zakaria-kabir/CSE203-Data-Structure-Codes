#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data=0;
	node*next=nullptr;
	
};
int main(){
	node*a =new node;
	a->data=3;
	cout<<"a "<<a<<endl;
	node*b=new node;
	b->data=4;

	node*c=new node;
	c->data=5;

	a->next=b;
	b->next=c;
	cout<<"a "<<a<<endl;
	node*x=a;
	while(x!=nullptr){
		cout<<x->data<<endl;
		x=x->next;
	}
	cout<<"a "<<a<<endl;
	cout<<"x "<<x<<endl;
	x=a;
	cout<<x<<endl;
	while(x!=nullptr){
		cout<<x->data<<endl;
		x=x->next;
	}
	cout<<"x "<<x<<endl;
}