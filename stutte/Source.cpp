#include<iostream>
using namespace std;

string stutter(string a) {
	string str = "";
	for (int i = 0; i < a.size(); i++) {
		str = str + a[i] + a[i];
	}
	return str;
}
int main()
{
	string str = "hello";
	cout<<stutter(str);
	
}