#include<bits/stdc++.h>
using namespace std;
void print(int n) {
	if (n == 1) {
		cout << "1 " << "1 ";
	}
	else if (n > 1) {
		cout << n << " ";
		print(n - 1);
		cout << n << " ";
	}
	else
		cout << "-";
}
int main() {
	int n = 3;
	//cin>>n;
	cout << n << " | ";
	print(n);

}