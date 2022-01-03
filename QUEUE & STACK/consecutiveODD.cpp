#include<bits/stdc++.h>

using namespace std;

void printq(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}
int consecutiveODD(queue<int>q){
	int count=0;
	int sz=q.size();
	int a=q.front();
		q.pop();
	q.push(a);
	for(int i=1;i<sz;i++){
		int b=q.front();
		q.pop();
		q.push(b);
		if(a%2==1&&b%2==1){
			count++;
		}
		a=b;
	}
	return count;
}
int main(){
queue<int>q;
	q.push(1);
	q.push(1);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(7);
	q.push(8);
	q.push(10);


printq(q);
cout<<consecutiveODD(q)<<endl;

printq(q);

}