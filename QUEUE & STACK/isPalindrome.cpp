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
bool isPalindrome(queue<int>& q) {
	stack<int>s;
	int a=0;
	int b=0;
	int size=q.size();
	int x=0;
	for(int i=0;i<size;i++){
		x=q.front();
		q.pop();
		s.push(x);
		q.push(x);
	}
	//prints(s);
	for(int i=0;i<size;i++){
		a=q.front();
		q.pop();
		b=s.top();
		s.pop();
		if(a!=b){
			return false;
		}
		
		q.push(a);
	}
	return true;

}
*/
bool isPalindrome(queue<int>& q) {
    if(q.empty() || q.size()==1){
        return true;
    }
    queue<int> c = q;
    stack<int> s;
    while(!c.empty()){
        s.push(c.front());
        c.pop();
    }
    int mid = q.size()/2;
    for(int i = 0; i < mid; ++i){
        if(q.front() == s.top()){
            return true;
        }
        else{
            return false;
            break;
        }
        q.pop();
        s.pop();
    }
	return false;
}
 

int main(){
queue<int>q;
	
	q.push(3);
	q.push(8);
	q.push(17);
	q.push(9);
	//q.push(17);
	q.push(8);
	q.push(3);

printq(q);
cout<<isPalindrome(q)<<endl;
printq(q);

}