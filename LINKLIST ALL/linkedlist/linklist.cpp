#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
void add(node *& linklist,int value){
	
		linklist=new node;
		linklist->data=value;
		linklist->next=nullptr;	
		cout<<linklist->data<<endl;	
	}
int main(){
	node* a=nullptr;
	add(a,6);
	cout<<a->data;
}