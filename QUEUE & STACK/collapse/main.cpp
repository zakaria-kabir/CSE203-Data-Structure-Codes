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


void reverseQueue(queue<int>& q)
{

    if (q.empty())
        return;
   	int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

void collapse (stack<int>& s) {
	queue<int>q;
	int size=s.size();
	int x=0;
	int a=0;
	int sum=0;
	while(!s.empty()){
		x=s.top();
		s.pop();
		q.push(x);

	}

	for(int i=0;i<size/2;i++){
		x=q.front();
		q.pop();
		a=q.front();
		q.pop();
		q.push(x);
		s.push(a);
	}

	reverseQueue(q);
	prints(s);
	printq(q);
	int sz=q.size();

	while(!s.empty()){
		x=s.top();
		s.pop();
		a=q.front();
		q.pop();
		sum=x+a;
//		cout<<"s-"<<x<<" "<<"q-"<<a<<endl;
		q.push(sum);

	}
	while(!q.empty()){
		x=q.front();
		q.pop();
		s.push(x);
	}

}



int main(){
stack<int>s;

s.push(1);
s.push(2);
s.push(3);
s.push(0);
s.push(-3);
s.push(-2);
s.push(-1);


prints(s);
collapse (s);
prints(s);

}
