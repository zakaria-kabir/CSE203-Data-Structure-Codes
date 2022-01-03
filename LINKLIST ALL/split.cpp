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
void split(ListNode*& head){
    if(head==nullptr){
        return;
    }
    else{
        ListNode *curr=head;
        if (curr!=nullptr) {
            while (curr->next!=nullptr) {
                if (curr->next->data<0) {
                    ListNode *temp=curr->next->next;
                    curr->next->next=head;
                    head=curr->next;
                    curr->next=temp;
                } 
                else {
                    curr=curr->next;
                }
            }
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
    split (a);

    print(a);

    
}