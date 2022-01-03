#include<iostream>
using namespace std;

void mystery3(int nums[], int length) {

	for (int i = 0; i < length - 1; i++) {

		if (nums[i] > nums[i + 1]) {

			nums[i + 1]++;

			cout << nums[i];
		}

	}

}
int main() {
	int nums[] = { 14 };
	mystery3(nums, 7);
}