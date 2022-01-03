#include<iostream>
using namespace std;
int mystery(int a, int& b) {
	b = b / 2;
	a += b;
	cout << a << " " << b << endl;
	return a;
}
int main() {
	int a = 2;
	int b = 6;
	int c = 10;
	mystery(b, a);
	c = mystery(a, b);
	mystery(b, c);
	cout << a << " " << b << " " << c << endl;
	return 0;
}