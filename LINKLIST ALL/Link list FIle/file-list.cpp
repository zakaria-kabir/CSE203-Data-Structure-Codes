#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode* next;
};
int readlife(string s,int*& arr,int& len){
	fstream file(s);
	len=0;
	int num=0;
	while(file>>num){
		len++;
	}
	file.close();
	file.open(s);
	arr=new int[len];
	num=0;
	int i=0;
	while(file>>num){
		arr[i]=num;
		i++;
	}
	file.close();
	
}
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

void writeInList(ListNode*&a ,int *arr,int& l){
	for(int i=0;i<l;i++){
			add(a,arr[i]);
		}

}

void writeinFile(ListNode* a,string s){
	fstream file(s);
	if(!file.is_open()){
		cout<<"output file not found! "<<endl;
	}
	else{
		if(a==nullptr){
			file<<"list was empty";
		}
		cout<<"check output file please ."<<endl;
	while(a!=nullptr){
	file<<a->data<<" ";
	a=a->next;
	}
}
	file.close();
}


void print(ListNode* a){
	if(a==nullptr){
			cout<<"list was empty";
		}
	while(a!=nullptr){
	cout<<a->data<<" ";
	a=a->next;
	}
}


int main(){
	ListNode* a=nullptr;
	int l=0;
	int *arr=nullptr;
	int n;
	string str="a.txt";
	string s="x.txt";
	fstream myfile(s);
	fstream file;
	file.open(str);
	if(!file.is_open()){
		cout<<"can not open !";
	}
	else{
		readlife(str,arr,l);
		writeInList(a,arr,l);
		writeinFile(a,s);
		cout<<"\nconsole output linked list is :"<<endl;
		print(a);
	}
file.close();
		
 }
