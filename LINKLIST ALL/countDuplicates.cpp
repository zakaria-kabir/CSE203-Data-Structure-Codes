
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
int countDuplicates  (ListNode* head){ 
    int count = 0; 
    if(head==0)
      return count;
  
    while (head->next != nullptr) { 
  
        ListNode *last = head->next; 
        while (last != nullptr) { 
 
            if (head->data == last->data) { 
                count++; 
                break; 
            } 
            last = last->next; 
        } 
  
        head = head->next; 
    } 
  
    return count; 
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
	cout<<countDuplicates (a);
}