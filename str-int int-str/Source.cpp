#include<iostream>
#include<sstream>
using namespace std;
int main() {
	/*
	int x = 123;
	stringstream ss;
	ss << x;
	string str = ss.str();
	cout << str << endl;;
	
	string a = "1234";
	int y = 0;
	stringstream s;
	s << a;
	s >> y;
	cout << y;
	*/


	//rev string
	string a = "hello what is your name ?";
	string rev = " ";
	stringstream ss;
	ss << a;
	string word = " ";
	while (ss >> word) {
		rev = word+" "+ rev;
	}
	cout << rev.substr(0, rev.size() - 1);

	
}