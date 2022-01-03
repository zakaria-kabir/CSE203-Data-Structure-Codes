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
/*
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

	while(!s.empty()){
		x=s.top();
		s.pop();
		a=q.front();
		q.pop();
		sum=x+a;
		q.push(sum);

	}
	while(!q.empty()){
		x=q.front();
		q.pop();
		s.push(x);
	}

}
*/
void collapse (stack<int>& s) {

  queue<int> q ;
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
                        
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
        
    while(!s.empty()) {
        int n1 = s.top();
        s.pop();
                                                            
        if(s.empty()) {
            q.push(n1);
            break;
        }
        
        int n2 = s.top();
        s.pop();
        q.push(n1 + n2);
    }
    
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

}

int main(){
stack<int>s;
s.push(10);
s.push(9);
s.push(8);
s.push(7);
s.push(6);
s.push(5);
s.push(4);
s.push(3);
s.push(2);
s.push(1);


prints(s);
collapse (s);
prints(s);

}