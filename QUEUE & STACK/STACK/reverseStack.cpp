#include<bits/stdc++.h>
//#include <algorithm> reverse STl function
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
int pop(myStack* s){
	s->count--;
	return s->arr[s->count];
}
void reverse(myStack* s)
{
   int temp;
   for (int i = 0; i < s->count/2; ++i)
   {
      temp = s->arr[i];
      s->arr[i] = s->arr[s->count-i-1];
      s->arr[s->count-i-1] = temp;
   }
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
	//reverse(s->arr,s->arr+size);//STL function
	reverse(s);

	for(int i=0;i<size;i++){
		cout<<pop(s)<<" ";
	}
	
}