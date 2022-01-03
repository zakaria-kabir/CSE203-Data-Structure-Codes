#include<bits/stdc++.h>
using namespace std;
struct node{
	int data=0;
	node *next=nullptr;
	node(int value){
		data=value;
	}
};
int main(){
	node*a=new node(2);	
	node*b=new node(3);	
	node*c=new node(4);	
	node*d=new node(4);	
	node*e=new node(5);	
	node*f=new node(6);	
	node*g=new node(7);
cout<<a->data<<" ";
cout<<b->data<<" ";
cout<<c->data<<" ";
cout<<d->data<<" ";
cout<<e->data<<" ";
cout<<f->data<<" ";
cout<<g->data<<" ";
}