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
void rearrange(queue<int>& q) {
    stack<int>z;
    int x=0;
    int size=q.size();
     for(int k = 0; k < 2; k++) {
    for(int i=0;i<size;i++){
        x=q.front();
          
        if(x%2==0){
            q.push(x);         
        }
        else{
            z.push(x);
        }
         q.pop();
    }

    while(!z.empty()){
  	 q.push(z.top());
  	 z.pop(); 
    }
}
	
}*/
void rearrange(queue<int>& q) {
   stack<int> s;
    int size = q.size();
            

        for(int i = 0; i < size; i++) {
            if(q.front() % 2 == 0){
                q.push(q.front());
            
            q.pop();
        }
            else{
                s.push(q.front());
            
            q.pop();
        }
        }
reverse(s);
        while(!s.empty()){
            q.push(s.top());
        
        s.pop();
    }

    
}

int main(){
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);


printq(q);
rearrange(q);
printq(q);
}