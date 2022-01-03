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

if(size%2==0){
	for(int i=0;i<size/2;i++){
		int x=q.front();
		q.pop();
		int a=q.front();
		q.pop();
		sum=x+a;

		q.push(sum);
	}
}
else{
	for(int i=0;i<(size+1)/2;i++){
		x=q.front();
		q.pop();
		if(q.empty()){		
		sum=x;
            goto STEP;
		}
		else{
			a=q.front();
		q.pop();
		}
		
		sum=x+a;
		STEP:
		s.push(sum);
	}
	
}
reverse(s);




}
*/

void collapse (stack<int>& s) {
queue<int> q ;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    //printq(q);                 
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    //prints(s);    
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
     //printq(q);
    
	while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

}


int main(){
stack<int>s;

s.push(5);
s.push(4);
s.push(3);
s.push(2);
s.push(1);


prints(s);
collapse (s);
cout<<"collapse form: "<<endl;
prints(s);


//prints(st);
//collapse (st);
//cout<<"collapse form: "<<endl;
//prints(st);

}

