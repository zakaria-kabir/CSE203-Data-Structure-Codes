#include<iostream>
using namespace std;
void mystery2(int a, int b) {

	if (a % b == 0) {
		a = a / b;
		if (a < b) {
			b = b - a;
		}
	}
	else if (b % 2 == 0) {
		b = b / 2;
	}
	else {
		a = a - b;
	}
	cout << a << " " << b << endl;

}
int main() {
	
	mystery2(20, 4);
	mystery2(7, 6);
	mystery2(14, 7);
	mystery2(24, 8);
	mystery2(13, 9);
	return 0;
}