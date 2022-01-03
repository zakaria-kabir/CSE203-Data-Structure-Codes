#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string reverseWordOrder(string s) {
	string rev = " ";
	string a = " ";

	if (s.size() > 0) {
		stringstream ss;
		ss << s;
		while (ss >> a) {
			rev = a + " " + rev;
		}
		return rev.substr(0, rev.size() - 2);
	}
	else
		return "";

}

int main() {
	string str = "Hello";

	cout << reverseWordOrder(str);
	return 0;
}