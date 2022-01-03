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

void print(ListNode* a){
  while(a!=nullptr){
    cout<<a->data<<" ";
    a=a->next;
  }
}

void evenodd(ListNode* a,ListNode*& e,ListNode*& o){
  while(a!=nullptr){
    if(a->data%2==0){
      add(e,a->data);
    }
    else{
      add(o,a->data);
    }
    a=a->next;
  }
}
void printevenodd(ListNode* a){
   ListNode* e=nullptr;
  ListNode* o=nullptr;
  evenodd(a,e,o);
  print(e);
  cout<<endl;
  print(o);
}
int main(){
  ListNode* a=nullptr;

   for(int i=0;i<13;i++){
      
    add(a,i);
  }
    print(a);cout<<endl;
 

  printevenodd(a);
  
}