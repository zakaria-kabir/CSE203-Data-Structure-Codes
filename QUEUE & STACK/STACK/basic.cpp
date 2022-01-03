#include<bits/stdc++.h>
using namespace std;
struct myStack{
	int size=0;
	int *arr=new int[size];
	int count=0;
};
void push(myStack*& s,int n){
	s->arr[s->count]=n;
	s->count++;
}
int pop(myStack*& s){
	s->count--;
	return s->arr[s->count];
}
int main(){
	int num;
	int size;
	cout<<"array size =";
	cin>>size;
	myStack *s=new myStack;
	s->size=size;
	
	for(int i=0;i<size;i++){
		cout<<"iteam in array:";
		cin>>num;
		push(s,num);
	}
	for(int i=0;i<size;i++){
		cout<<pop(s)<<" ";
	}

}