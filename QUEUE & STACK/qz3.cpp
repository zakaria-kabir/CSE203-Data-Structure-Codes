#include<bits/stdc++.h>

using namespace std;
//Q1
/*
void prints(stack<int>q){
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
		cout<<endl;
}

void replace(stack<int>& st){
	stack<int>s;
	while(!st.empty()){
		int a=st.top();
		st.pop();
		if(a%2!=0){
			a=a+1;
			s.push(a);
		}
		else
			s.push(a);

	}
	while(!s.empty()){
		st.push(s.top());
		s.pop();
	}
}


int main(){
	stack<int>s;
	s.push(23);
	s.push(11);
	s.push(31);
	s.push(24);
	s.push(3);
	s.push(-4);
	s.push(-5);

		replace(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
		cout<<endl;

}
*/



//Q2
void printq(queue<int>q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
/*
void reverseQueue(queue<int>& q)
{

	if (q.empty())
		return;
	int x = q.front();
	q.pop();
	reverseQueue(q);
	q.push(x);
}

void sortQ(queue<int> &q){
	priority_queue<int> pq;
	while(!q.empty()){
		pq.push(q.front());
		q.pop();
	}
	while(!pq.empty()){
		q.push(pq.top());
		pq.pop();
	}
	reverseQueue(q);
}
*/
/*
int posOFmin(queue<int> &q, int n)
{
	int pos = 0;
	int min = INT_MAX;
	int sz = q.size();
	for (int i = 0; i < sz; i++)
	{
		int a = q.front();
		q.pop();
		if (a <= min && i <= n)
		{	//cout<<pos<<endl;
			pos = i;
			min = a;
			//cout<<min<<endl;
		}
		q.push(a);
	}
	return pos;
}
void addlast(queue<int> &q, int pos)
{
	int min = 0;
	int sz = q.size();
	for (int i = 0; i < sz; i++)
	{
		int a = q.front();
		q.pop();
		if (i != pos)
			q.push(a);
		else
			min = a;
	}
	q.push(min);
}
void sortQ(queue<int> &q) {
	for (int i = 1; i <= q.size(); i++) {
		//cout<<posOFmin(q,q.size()-i)<<endl;
		int x = posOFmin(q, q.size() - i);
		addlast(q, x);
	}

}
*/
/*
void minimum(queue<int> &q, queue<int>&qu)
{
	if (!q.empty()) {

		int min = INT_MAX;
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			int a = q.front();
			q.pop();
			if (a <= min )
			{

				min = a;

			}
			q.push(a);
		}
		for (int i = 0; i < sz; i++) {
			int x = q.front();
			if (x == min) {
				qu.push(x);
				q.pop();
			}
			else {
				q.pop();
				q.push(x);
			}

		} minimum(q, qu);
	}

}
void sortQ(queue<int> &q) {
	queue<int>qu;

	minimum(q, qu);
	while (!qu.empty()) {
		q.push(qu.front());
		qu.pop();
	}

}
*/
/*
void sortQ(queue<int>& q)
{
	stack<int>s;
	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	stack<int>s1;
	int a = 0;
	while (!s.empty())
	{
		a = s.top();
		s.pop();
		while (!s1.empty() && s1.top() >a)
		{
			s.push(s1.top());
			s1.pop();
		}
		s1.push(a);
	}
	while (!s1.empty())
	{
		s.push(s1.top());
		s1.pop();
	}
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}
*/

int main() {
	queue<int>q;
	q.push(3);
	q.push(19);
	q.push(4);
	q.push(15);
	q.push(20);
	q.push(3);
	q.push(9);
	q.push(4);
	q.push(15);
	q.push(0);


	printq(q);
	sortQ(q);
	printq(q);


}
