#include<iostream>
using namespace std;
void mystery1(int a1[], int length1, int a2[], int length2) {

	for (int i = 0; i < length1; i++) {

		a1[i] += a2[length2 - i - 1];
		cout << a1[i]<<",";

	}

}

int main() {
	int a1[] = { 1, 3, 5, 7, 9 };

	int a2[] = { 1, 4, 9, 16, 25 };

	mystery1(a1, 5, a2, 5);
}