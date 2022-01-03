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
void concatenate(ListNode *& a,ListNode *&b)
{
    if (a->next == NULL)
        a->next = b;
    else
        concatenate(a->next,b);
}
void doubleList (ListNode* &x){
  if(x ==nullptr){
    
    return ;
  }
  else{
    ListNode *curr=x;
    ListNode* copy=nullptr;
  while(curr!=nullptr){
        add(copy,curr->data);
        curr=curr->next;
    }
       
    concatenate(x,copy);
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
     doubleList (a);

   print(a);

    
}