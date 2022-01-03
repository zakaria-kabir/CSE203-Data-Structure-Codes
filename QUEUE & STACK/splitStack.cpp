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
void splitStack(stack<int>& s) {
	queue<int>q;
	while(!s.empty()){
		int x=s.top();
		s.pop();
		q.push(x);
	}
	//printq(q);
	int sz=q.size();
	for(int i=0;i<sz;i++){
		int x=q.front();
		q.pop();
		if(x<0){
			q.push(x);
		}
		else{
			s.push(x);
		}
	}
//	printq(q);
//	prints(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		s.push(x);
	}
//	printq(q);
	

	
}



int main(){
stack<int>s;
s.push(7);
s.push(2);
s.push(-3);
s.push(-6);
s.push(5);
s.push(-1);
s.push(0);
s.push(4);
prints(s);
splitStack(s);
prints(s);
}
