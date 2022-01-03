/*
#include<iostream>
using namespace std;
int binary(int array[17], int low, int high, int find) {

	int mid = (low + high) / 2;
	
	if (low <= high) {
		if (find == array[mid]) {
			return mid;
		}
		if (find > array[mid]) {

			return binary(array, mid + 1, high, find);
		}
		else {
			return binary(array, low, mid - 1, find);
		}
	}
	else
		return -1;
	
}
int binarySearch(int arr[17], int number) {
	return binary(arr, 0, 16, number);
}
int main() {
	int a[] = { -4, 2, 7, 10, 15, 20, 22, 25, 30, 36, 42, 50, 56, 68, 85, 92, 103 };
	cout << binarySearch(a, 104);
	return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int> &vec, int low, int high, int find) {

	int mid = (low + high) / 2;

	if (low <= high) {
		if (find == vec[mid]) {
			return mid;
		}
		if (find > vec[mid]) {

			return binary(vec, mid + 1, high, find);
		}
		else {
			return binary(vec, low, mid - 1, find);
		}
	}
	else
		return -1;

}
int binarySearch(vector<int>& vector, int number) {
	
	return binary(vector, 0, vector.size()-1, number);
}
int main() {
	vector<int> vect = { -4, 2, 7, 10, 15, 20, 22, 25, 30, 36, 42, 50, 56, 68, 85, 92, 103 };
	cout << binarySearch(vect, 10);
	return 0;
}