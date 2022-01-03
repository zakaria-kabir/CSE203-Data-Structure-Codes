#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void reverseLines(ifstream& file) {
	string str;
	if (getline(file, str)) {
		reverseLines(file);
		cout << str << endl;
	}


}
int main() {
    ifstream file("zaka.text");
    reverseLines(file);
}
