#include<iostream>
using namespace std;
int power(int base, int pow) {
	if (pow < 0) {
		throw 404;
	}
	if (pow == 0)
		return 1;
	else {
		return base * power(base, pow - 1);
	}

		
}
int main() {
	cout << power(-3, -2);
}