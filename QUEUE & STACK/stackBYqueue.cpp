#include<bits/stdc++.h>

using namespace std;

void prints(stack<int>q){
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
		cout<<endl;
}
void printq(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}
void push(queue<int>& q, int element) {
	int x=0;
	int sz=q.size();
	q.push(element);
	for(int i=0;i<sz;i++){
		q.push(q.front());
		q.pop();
	}

	
}
int pop(queue<int>&q)
{ 
    if (q.empty()) 
        return 0;
    else
        {
        	int x=q.front();
        	q.pop();
        	return x;
        } 
} 

int main(){

queue<int>q;
push(q,1);
push(q,2);
push(q,3);
cout<<pop(q)<<endl;
cout<<pop(q)<<endl;
cout<<pop(q)<<endl;

   
}
