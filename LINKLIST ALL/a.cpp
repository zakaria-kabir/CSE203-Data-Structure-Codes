#include<bits/stdc++.h>
using namespace std;
struct ListNode{
  int data;
  ListNode* next;
};
void add(ListNode *& linklist,int value){
  if(linklist==nullptr){
  
    ListNode* n=new ListNode;
      cout<<"address of linklist "<<linklist<<endl;
      cout<<"address of n "<<n<<endl;
    n->data=value;
    n->next=linklist;
    cout<<"address of linklist "<<linklist<<endl;
    cout<<"address of n "<<n<<endl;
    linklist=n;
    //n=linklist;
    cout<<"address of linklist "<<linklist<<endl;
    cout<<"address of n "<<n<<endl;
  
  }
}
  void print(ListNode* a){
    cout<<"list is now ";
  while(a!=nullptr){
    cout<<a->data<<" ";
    a=a->next;
  }
}
int main(){
ListNode* a=nullptr;
	add(a,2);
	print (a);
}