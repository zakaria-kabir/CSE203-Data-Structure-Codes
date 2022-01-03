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
ListNode* getNode(int data)
{
    // allocating space
    ListNode* newNode = new ListNode();
 
    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertPos(ListNode** current, int pos, int data)
{
 
        while (pos--) {
 
            if (pos == 0) {
 
                // adding Node at required position
                ListNode* temp = getNode(data);
 
                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;
 
                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the
              // pointer pointing to the address of next Node
              current = &(*current)->next;
        }
    
}
void expand(ListNode*& head,int k){
	if(head==nullptr){
		return;
	}
	else if(k==0){
		head=nullptr;
		return;
	}
	else if(k<0){
		throw(404);
	}
	else{
		int count=0;
		ListNode* curr=head;
		while(curr!=nullptr){
			count++;
			int x=curr->data/k;
			curr->data=x;
			//for(int i=0;i<k-1;i++){
				insertPos(&curr,count,x);
			//}
				curr=curr->next;
		}
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
    print(a);
     expand (a,2);

   print(a);

    
}