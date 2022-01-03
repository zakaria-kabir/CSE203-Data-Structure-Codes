#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void collectionMystery7(queue<int>& queue) {

    stack<int> stack;

    int qsize = queue.size();

    for (int i = 0; i < qsize; i++) {

        if (queue.front() % 2 == 0) {

            queue.push(queue.front() );
            queue.pop();

        } else {

            stack.push(queue.front());

            stack.push(queue.front() );
            queue.pop();
        }

    }

    while (!queue.empty()) {

        stack.push(queue.front() );
            queue.pop();
    }

    while (!stack.empty()) {

        cout << stack.top() << " ";
        stack.pop();

    }

}
int main(){
	queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);

	collectionMystery7(s);

}