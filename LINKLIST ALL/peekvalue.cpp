
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

void peek(ListNode*& a){
  while(a->next->next!=nullptr){
    if((a->next->data)>(a->data) && (a->next->data)>(a->next->next->data)){
      cout<<a->next->data<<" ";
    }
    a=a->next;
  }

}
int main(){
  ListNode* a=nullptr;

   for(int i=0;i<13;i++){
      
    add(a,rand()%1000);
  }  print(a);
  
  cout<<endl;
  peek(a);
}

