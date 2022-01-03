#include<bits/stdc++.h>

using namespace std;
struct student {
	string name = "";
	float cgpa = 0.0;
};
string getString() {
	string str = "";
	getline(cin, str);
	return str;
}
float getFloat() {
	string str = getString();
	float f = 0.0;
	stringstream ss;
	ss << str;
	ss >> f;
	return f;
}
void writeInfo(student *s , int len) {
	for (int i = 0; i < len; i++) {
		cout << "Name: ";
		s[i].name = getString();
		cout << "CGPA: ";
		s[i].cgpa = getFloat();
	}
}
void readInfo(student* s, int len) {
	for (int i = 0; i < len; ++i) {
		cout << "Name: " << s[i].name << " CGPA: " << s[i].cgpa << endl;
	}
}
int main() {
	student* s = new student[3];
	writeInfo(s, 3);
	readInfo(s, 3);
	return 0;
}