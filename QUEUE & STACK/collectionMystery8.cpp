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


void collectionMystery8(stack<int>& stack) {

    queue<int> queue;

    set<int> set;

    while (!stack.empty()) {

        if (stack.top() % 2 == 0) {

            queue.push(stack.top());
            stack.pop();
    
        } else {

            set.insert(stack.top());
            stack.pop();

        }

    }

    for (int n : set) {
//1 3 5(ascending order)
        stack.push(n);
        prints(stack);
    }

    while (!queue.empty()) {

        stack.push(queue.front());
        queue.pop();

    }

 prints(stack);

}

int main(){
stack<int>s;

s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);


prints(s);
collectionMystery8 (s);

//prints(s);

}