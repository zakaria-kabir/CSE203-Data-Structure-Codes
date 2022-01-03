#include<bits/stdc++.h>

using namespace std;

void printq(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}
void sort(queue<int>&q){
	int sz=q.size();
	
	for(int i=0;i<sz;i++){
		int a=q.front();
		q.pop();
	//q.push(a);
		for(int j=1;j<sz;j++){
			int b=q.front();
			q.pop();
			//q.push(b);
			if(a>b){
				int temp=a;
				a=b;
				b=temp;
				q.push(b);
			}	
			else
				q.push(b);
		}		
	}
}
int main(){
queue<int>q;
	q.push(1);
	q.push(1);
	q.push(3);
	q.push(6);
	q.push(2);
	q.push(7);
	q.push(8);
	q.push(0);


printq(q);

printq(q);

}