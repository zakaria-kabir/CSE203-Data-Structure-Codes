#include <iostream>

using namespace std;

void zigzag(int n) {
	if (n < 1) {
		throw 404;
	}
	else if (n == 1) {
		cout << "*";
	}
	else if (n == 2) {
		cout << "**";
	}
	else {
		cout << "<";
		zigzag(n - 2);
		cout << ">";
	}

}
int main() {
	zigzag(0);
}