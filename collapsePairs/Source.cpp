#include<iostream>
using namespace std;
void collapsePairs(int arr[], int l) {
	
	for (int i = 0; i < l-1 ; i += 2) {
		int sum = arr[i] + arr[i + 1];
		if (sum % 2 == 0) {
			arr[i] = sum;
			arr[i + 1] = 0;

		}
		else {
			arr[i] = 0;
			arr[i + 1] = sum;
		}
		cout << arr[i] <<","<< arr[i + 1]<<",";
	}
	
}
int main() {
	int a[]= { 2,5,6,1,2 };
	collapsePairs(a, 5);

}