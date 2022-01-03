#include<bits/stdc++.h>
using namespace std;
struct ListNodeDouble{
	float data;
	ListNodeDouble* next;
};

void add(ListNodeDouble *& linklist,float value){
	if(linklist==nullptr){
		ListNodeDouble* n=new ListNodeDouble;
		n->data=value;
		n->next=linklist;
		linklist=n;
	
	}
	else{
		ListNodeDouble*current =linklist;
		while(current->next!=nullptr){
			current =current->next;
		}
		ListNodeDouble *a=new ListNodeDouble;
		a->data=value;
		a->next=current->next;
		current->next=a;
	}
}

void removeAllThreshold  (ListNodeDouble *&a, float x,float  y) 
{ 
	float m=x+y;
	float n=x-y;
	ListNodeDouble *temp = a;
	ListNodeDouble *prev=nullptr; 
	while ((temp != nullptr) &&((temp->data==n||temp->data==m)||( temp->data > n&&temp->data<m)) )
	{ 
		a = temp->next; 
		delete temp;	
		temp = a;
	} 
	while (temp != nullptr) 
	{
		while ((temp != nullptr) && (temp->data < n||temp->data> m) )
		{ 
			prev = temp; 
			temp = temp->next; 
		} 
		if (temp == nullptr)
return; 
		prev->next = temp->next; 
		delete temp; 
		temp = prev->next; 
	} 
} 
void print(ListNodeDouble* x){
	while(x!=nullptr){
		cout<<x->data<<" ";
		x=x->next;
	}
	cout<<endl;
}
int main(){
	ListNodeDouble* a=nullptr;
	int n;
	float num;
	cout<<"how many :";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter number :";
		cin>>num;
		add(a,num);
	}
	ListNodeDouble*x=a;
	while(x!=nullptr){
		x=x->next;
	}
	removeAllThreshold (a,3.0,0.3);

	print(a);
	
}