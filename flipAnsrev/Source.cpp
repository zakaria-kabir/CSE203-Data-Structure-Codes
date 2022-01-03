#include<iostream>
#include<sstream>
#include<istream>
using namespace std;
string rev(string str) {
	stringstream ss;
	string rev = "";
	char c = ' ';
	ss << str;
	while (ss >> c) {
		if (str == " ")
		{
			cout << ' ';
		}
		rev = c+ rev;
	}
	return rev;
}
int main() {
	string s = "today is monday";
	cout<<rev(s);
}