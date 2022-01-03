#include<iostream>
using namespace std;
int up(int a);
int sevenup(int n) {
	

	if (n < 3) {
		return 0;
	}
	else if (n %3 == 0){
		return 1 + sevenup(n - 1);
		
	}
	else if (n==2) {
		return 1;
	}
	else {
		return up(n);
	}
	
}
int up(int x) {
	if (sevenup(x) / 3 >= 0) {
		return sevenup(x) / 3;
	}
	return up(x) + sevenup(x);
}

int main() {
	int returnbottle = 0;
	cout << "how many bottle :";
	cin >> returnbottle;
	cout << sevenup(returnbottle);
}