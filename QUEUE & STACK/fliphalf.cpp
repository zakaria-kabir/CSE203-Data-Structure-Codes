#include<iostream>

#include<queue>
#include<stack>

using namespace std;

void prints(stack<int>q) {
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}
void printq(queue<int>q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void flipHalf(queue<int>& q) {
	stack<int>s;
	int count = 0;
	int sz = q.size();
	int a = 0;
	int x = 0;

	for (int i = 0; i < sz; i++) {
		a = q.front();
		q.pop();
		if (i % 2 == 0) {
			q.push(a);
		}
		else {
			s.push(a);
		}
	}
	printq(q);
	prints(s);

	while (!s.empty()) {
		x = s.top();
		s.pop();
		a = q.front();
		q.pop();
		q.push(a);
		q.push(x);
	}
	if (sz % 2 == 1) {
		x = q.front();
		q.pop();
		q.push(x);
	}
	//printq(q);
}



int main() {
	queue<int>q;

	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	//q.push(7);

	printq(q);
	flipHalf(q);
	printq(q);
}