
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
ListNode* addBack  (ListNode*& a,int d)
{
  ListNode *ptr = new ListNode();
  ptr->data=d;
  ptr->next=NULL;

  //If list is empty
  if(a==NULL)
  a=ptr;
  //else list is not empty
  else
  {
   ListNode *temp = a;
   while(temp->next != NULL)
   {
    temp=temp->next;
   }
   temp->next=ptr;

  }
  return a;

}
void print(ListNode* a){
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
  addBack (a,3);
  print(a);
}