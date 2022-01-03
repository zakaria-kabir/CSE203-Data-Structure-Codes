#include<iostream>
#include<queue>
//push(a),pop(),front(),back(),empty(),size(),swap()
using namespace std;

void print(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}

int main(){
	queue<int>que;	
	que.push(2);
	que.push(3);
	que.push(4);
	
	print(que);

	//cout<<que.size()<<endl;
	//cout<<que.back()<<endl;
	
	//print(que);

	queue<int>q;
	q.push(-1);
	q.push(-0);
	q.push(-9);

	print(q);

	swap(que,q);
	print(q);
	print(que);
}