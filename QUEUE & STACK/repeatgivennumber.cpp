#include<bits/stdc++.h>

using namespace std;

void printq(queue<int>q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void prints(stack<int>s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
void repeatq(queue<int>&q, int n, int times) {
	int sz = q.size();
	for (int i = 0; i < sz; i++) {
		int b = q.front();
		q.pop();
		if (b == n) {
			for (int j = 0; j < times; j++) {
				q.push(b);
			}
		}
		else
			q.push(b);
	}
}
void repeats(stack<int>&s, int n, int times) {
	queue<int>q;
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	int sz = q.size();
	for (int i = 0; i < sz; i++) {
		int b = q.front();
		q.pop();
		if (b == n) {
			for (int j = 0; j < times; j++) {
				s.push(b);
			}
		}
		else
			s.push(b);
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
}
int main() {
	queue<int>q;
	q.push(2);
	q.push(1);
	q.push(3);
	q.push(2);
	q.push(4);

	printq(q);
	repeatq(q, 2, 3);
	printq(q);

	cout << "-------------------------" << endl;

	stack<int>s;
	s.push(4);
	s.push(2);
	s.push(3);
	s.push(1);
	s.push(2);

	prints(s);
	repeats(s, 2, 3);
	prints(s);

}