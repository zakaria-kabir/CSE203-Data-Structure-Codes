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
/*
void switchPairs(stack<int>& s) {
	stack<int> n;
	stack<int> m;
	float x=s.size();
	int a=floor(x/2);
//cout<<a<<endl;
	for(int i=0;i<a;i++){
		m.push(s.top());
		s.pop();
		n.push(s.top());
		s.pop();
	}
	//print(n);  //1 3 5
	//print(m);// 2 4 6 
	while(!n.empty()&&!m.empty()){
		s.push(m.top());
		m.pop();
		s.push(n.top());
		n.pop();
	}
	//print(s);
}*/

void switchPairs(stack<int>& s) {
	queue<int>q;

   int a = 0;
    int b = 0;
    while(!s.empty()){
      a = s.top();
      s.pop();
        if(s.empty()){
            q.push(a);
        } 

        else {
    b = s.top();
    s.pop();
    q.push(b);
    q.push(a);
        }

        }
        while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
		while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
       // prints(s);
 
  
}

int main(){
stack<int>s;
s.push(42);
s.push(14);
s.push(4);
s.push(3);
s.push(2);
s.push(1);
s.push(3);
s.push(8);
s.push(17);
s.push(9);
s.push(99);
s.push(9);
s.push(17);
s.push(8);
s.push(3);
//cout<<s.top()<<endl;
prints(s);//6 5 4 3 2 1 
switchPairs(s);
prints(s);

}