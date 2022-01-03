#include<bits/stdc++.h>
using namespace std;
struct myQueue{
	int size=0;
	int *arr=new int[size];
	int head=0;
	int tail=0;
};
void enqueue(myQueue*& q,int n){
	q->arr[q->tail]=n;
	q->tail++;
}
int dequeue(myQueue*& q){
	int r= q->arr[q->head];
	q->head++;
	return r;
}
int main(){
	int num;
	int size;
	cout<<"array size =";
	cin>>size;
	myQueue *q=new myQueue;
	q->size=size;

	for(int i=0;i<size;i++){
		cout<<"iteam in array:";
		cin>>num;
		enqueue(q,num);
	}
	for(int i=0;i<size;i++){
		cout<<dequeue(q)<<" ";
	}

}
