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
void reorder(queue<int>& q){
	stack<int>s;
	int sz=q.size();
	for(int i=0;i<sz;i++){
		int x=q.front();
		q.pop();
		if(x<0){
			s.push(x);
			
		}
		else{
			q.push(x);
		}
		
	}
reverse(s);
	prints(s);
	printq(q);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		s.push(x);
	}
	reverse(s);
		prints(s);
		
	while(!s.empty()){
		int x=s.top();
		s.pop();
		q.push(x);
	}

	
}
/*
void reorder(Queue<int>& q){
	   Stack<int> s ;
    int size = q.size();
    int c = 0; 
   for(int i = 0; i < size; i++) {
        int n = q.dequeue();
        
        if(n < 0) {
            s.push(n);
        } else {
            q.enqueue(n);
            c++;
        }
    }
    
    while(!s.isEmpty())
        q.enqueue(s.pop());
        
    for(int i = 0; i < c; i++)
        q.enqueue(q.dequeue());
}
*/

int main(){
queue<int>q;
q.push(1);
q.push(-2);
q.push(3);
q.push(4);
q.push(-5);
q.push(6);
q.push(-7);
q.push(8);
q.push(-9);
q.push(10);

printq(q);
reorder(q);
	printq(q);

}
