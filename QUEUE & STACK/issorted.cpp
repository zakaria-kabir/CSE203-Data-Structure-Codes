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
bool isSorted(stack<int>&st)

{
    stack<int> s = st;
    if(st.empty()||st.size()==1)
   {
       return true;
   } 
   while(!st.empty())
   {
       int x = s.top();
       s.pop();
       if(!s.empty()&&x>s.top())
       {
           return false;
           break;
       }
       
   } 
 return true;
}
/*
bool isSorted(stack<int>& s) {
queue<int>q;
bool flag=true;
int sz=s.size();
for(int i=0;i<sz;i++){

int x=s.top();
s.pop();
q.push(x);

if(!s.empty()&& x<s.top()){// csbs->if(!s.isEmpty()&& x>s.peek()){
    flag=false;
}
}

   reverseQueue(q);
while(!q.empty()){
    s.push(q.front());
    q.pop();
}

return flag;


}
*/
/*
bool isSorted(stack<int>& s){ //4 3 2 1

     stack<int> t;
     int x=0,y=0;
     bool flag=true;
     while(!s.empty()) {
        if(s.size()==1){
            x=y=s.top();
            s.pop();
             t.push(x); 
        }
else{
      x = s.top(); 
     s.pop();

      y= s.top(); 
     //s.pop(); 
       t.push(x); 
     //t.push(y); 
   }
     if(x>y) 
     {
        flag=false;
        break;
    }
   


     } 


     while (!t.empty()){ //t 1 2 3 4 5
     s.push(t.top()); 
     t.pop();
     } 
     return flag;



}
*/
int main(){
stack<int>s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);


prints(s);
cout<<isSorted(s)<<endl;
prints(s);

}