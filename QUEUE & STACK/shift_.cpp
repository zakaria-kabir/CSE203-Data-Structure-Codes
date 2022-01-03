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

void bottom(stack<int>&st,int x) 
{ 
  
    if(st.size() == 0) 
    st.push(x); 
  
    else
    {            
      int a = st.top(); 
        st.pop(); 
    bottom(st,x); 
   
        st.push(a); 
    } 
} 
void reverse(stack<int>&st) 
{ 
    if(st.size()>0) 
    { 
   
        int x = st.top(); 
        st.pop(); 
        reverse(st); 
    bottom(st,x); 
    } 
}  
/*
void shift(stack<int>& s, int n) {
queue<int>q;
int x=0;
int size=s.size();
    if(size>0){
while(!s.empty()){
x=s.top();
s.pop();
q.push(x);
}
printq(q);
int sz=q.size();
for(int i=0;i<sz-n;i++){
x=q.front();
q.pop();
s.push(x);
}
prints(s);
while(!s.empty()){
	x=s.top();
	s.pop();
	q.push(x);
}
printq(q);
for(int i=0;i<n;i++){
	x=q.front();
	q.pop();
	q.push(x);
}
printq(q);
while(!q.empty()){
	x=q.front();
	q.pop();
	s.push(x);
}
prints(s);
}
}
*/
void shift(stack<int>& st, int n) {
queue<int>q;
	int x = st.size();                       
	if(!st.empty()){

		while(!st.empty()){
		q.push(st.top());
		st.pop();
	}
	while(!q.empty()){
		st.push(q.front());
		q.pop();

	}
	for(int i=0;i<n;i++){
		q.push(st.top());
		st.pop();
	}
	reverse(st);
reverseQueue(q);

	while(!q.empty()){
		st.push(q.front());
		q.pop();

	}
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
shift(s,6);
prints(s);
}