#include<iostream>
using namespace std;

int evenDigits(int n) {
	if (n == 0)
		return 0;
	else {
		
		if ((n%10) % 2 == 0)
			return  n%10 + 10 * evenDigits(n / 10) ;

		else {
			return evenDigits(n / 10);

		}
	}
}
int main() {
	int x = 10234;
	cout << evenDigits(x);
}