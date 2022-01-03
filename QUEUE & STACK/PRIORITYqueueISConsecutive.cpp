#include<bits/stdc++.h>
using namespace std;
void print(priority_queue <int> q) 
{ 
    priority_queue <int> z = q; 
    while (!z.empty()) 
    { 
        cout<< z.top()<<" "; 
        z.pop(); 
    } 
    cout <<endl; 
}
void printq(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}


bool isConsecutive(priority_queue<int>& pq) {

	if(pq.size()==0){
		return true;
	}
	priority_queue<int> q;
	bool flag=true;
	int x=pq.top();
	pq.pop();
	q.push(x);
	while(!pq.empty()){
		int z=pq.top();
		pq.pop();
		q.push(z);
		if(x-z!=1){
			flag=false;
			break;
		}
		x=z;
	}
	while(!q.empty()){
		int i=q.top();
		q.pop();
		pq.push(i);

	}
	return flag;
}

int main(){

    priority_queue <int> q; 
    q.push(1); 
    q.push(2); 
    q.push(3); 
    q.push(4); 
    q.push(5); 

    print(q);
    cout<<isConsecutive(q)<<endl;
print(q);
}
//csbs code
/*
bool isConsecutive(PriorityQueue<int>& pq) {
	if(pq.size()==0){
		return true;
	}
	PriorityQueue<int> q;
	bool flag=true;
	int x=pq.front() ;
    q.enqueue(x,pq.peekPriority());
    pq.dequeue();
	while(!pq.isEmpty()){
		int z=pq.front();
		q.enqueue(z,pq.peekPriority());
        pq.dequeue();
		if((z-x)!=1){
			flag=false;
			break;
		}
		x=z;
	}
    while(!pq.isEmpty()){
		int z=pq.front();
		q.enqueue(z,pq.peekPriority());
        pq.dequeue();
	}
	while(!q.isEmpty()){
		int i=q.front();
    pq.enqueue(i,q.peekPriority());
    q.dequeue();
	}
	return flag;
}	
*/