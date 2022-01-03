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
ListNode* reverse (ListNode* x){
	ListNode *rev=nullptr;
	while(x!=nullptr){
		ListNode *n=new ListNode;
		n->data=x->data;
		n->next=rev;
		rev=n;
		x=x->next;		
	}
	return rev;

}


void braid(ListNode*& x){
	ListNode*b=new ListNode;
	b=reverse(x);

		ListNode*current1=x;
		ListNode*currentb=b;	

       while(current1!=nullptr&&currentb!=nullptr){
              
        ListNode *a=new ListNode;
        a->data=currentb->data;
        a->next=current1->next;
        current1->next=a;
        current1=current1->next->next;
        currentb=currentb->next;
}
  


}


/*int reverse (ListNode*& x){
	ListNode *p;
	ListNode *c;
	ListNode *n;
	p=nullptr;
	c=x;
	n=nullptr;
	while(c!=nullptr){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	x=p;
}*/
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
	print(a);
	cout<<endl;
	reverse(a);
	cout<<endl;
	braid(a);
	cout<<endl;
	print(a);
}