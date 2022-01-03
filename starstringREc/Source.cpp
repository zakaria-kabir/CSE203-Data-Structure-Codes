
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;

/*
#include <iostream>
#include <string>
#include<cmath>
using namespace std;
string starprint(int n) {
    string s="*";
	if (n < 2) {
		return "*";
	}
	else {

		return s+starprint(n - 1);

	}

}
string starString(int n) {
	if (n < 0) {
		throw 1;
	}
	else if (n == 0) {
		return "*";
	}
	else
		return starprint(pow(2, n));


}


*/

/*
string repeatString(string s, int n) {
	if (n < 0) {
		throw "n must be > 1";
	}
	else if (n == 0) {
		return "";
	}
	else {
		return s + repeatString(s, n - 1);
	}
}

string starString(int n) {
	string stars = "";
	if (n < 0) {
		throw 1;
	}
	else if (n == 0) {
		return "*";
	}
	else {
		stars = repeatString("*",(pow(2, n - 1)));
		return stars + starString(n - 1);
	}
}
*/

string starString(int n) {

	if (n  ==0) {
		return "*";
	}
	else {

		return starString(n - 1)+starString(n-1);


	}

}


int main() {
	cout<<starString(3);
}
