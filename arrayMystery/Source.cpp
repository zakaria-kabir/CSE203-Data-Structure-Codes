#include<iostream>
using namespace std;
void mystery2(int a[], int length) {
	for (int i = 1; i < length; i++) {

		a[i] = a[length - 1 - i] - a[i - 1];
		cout << a[i];
	}

}
int main()
{
	int a[] =
	{ 6, 2, 4 };
	mystery2(a, 3);
}