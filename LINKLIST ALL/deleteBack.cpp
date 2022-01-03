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
int deleteBack(ListNode*& front) {
int n=0;
ListNode*t=front;
        if(front == nullptr) {throw "error";}
        else if (front->next==NULL){ n=front->data;front=NULL;delete front; }
         else { while(t->next->next!=NULL){
         	    t=t->next;
} 
	n=t->next->data;
  t->next=nullptr;
  delete t->next;
 
 }
         return n;}
 
/*
int deleteBack(ListNode*& Nfront) {
    int back = 0;
	if(Nfront == nullptr){
        throw ("Empty");
    }
    else if(Nfront->next == nullptr){
        ListNode* front = Nfront;
        back = Nfront->data;
        Nfront = nullptr;
        
        delete (front);
    }
    else{
        ListNode* current = Nfront;
        ListNode* previous;
        while (current->next != nullptr){
        	previous=current;
            current = current->next;
            if(current->next == nullptr){
                previous->next=nullptr;
            delete(current->next);
            back=current->data;
               
            }
        }
    
    }
    return back;
}
*/
/*
int deleteBack (ListNode*& x){
	ListNode* curr = x;
		 ListNode *pre; 
	if(x==nullptr){
		throw (" error! ");
	}
	if(x->next==nullptr){
		curr=x;
		x=nullptr;	
		return (curr->data);
		delete (curr);
		
	}
	else{
		 
    while (curr->next != nullptr){ 
        pre = curr;  
        curr=curr->next;
    }

    pre->next=nullptr;

    delete (curr->next); 

  return (curr->data);
     
}
}
 	*/

void print (ListNode* a){
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
	cout<<deleteBack (a)<<"."<<endl;
	print(a);
}