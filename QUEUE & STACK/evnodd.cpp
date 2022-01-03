#include<bits/stdc++.h>

using namespace std;

void printq(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}

void evenodd(queue<int>q){
	queue<int>s;
	int size=q.size();
	for(int i=0;i<size;i++){
		if(q.front()%2==0){
			s.push(q.front());
		}
		else
			q.push(q.front());
		q.pop();
	}
	printq(q);
	printq(s);
}
int main(){
queue<int>q;
q.push(10);
q.push(9);
q.push(8);
q.push(7);
q.push(6);
q.push(5);
q.push(4);
q.push(3);
q.push(2);
q.push(1);



evenodd (q);


}