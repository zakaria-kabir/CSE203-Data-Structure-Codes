#include<bits/stdc++.h>

using namespace std;

void print(queue<string>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
		cout<<endl;
}
void mirror(queue<string>& q) {
 stack<string> s;
 string str=" ";
  int size = q.size();
  for (int i = 0; i < size; i++) {
    //str = q.pop();
    s.push(q.front());
    q.push(q.front());
    q.pop();
  }
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
}
int main(){
	queue<string>que;	
	que.push("A");
	que.push("B");
	que.push("C");
	
	print(que);

	mirror(que);
	print(que);
}