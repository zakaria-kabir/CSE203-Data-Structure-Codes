/*
#include<iostream>
using namespace std;

void banish(int arr1[], int arr2[]) {
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < len1; i++) {
		bool found = false;
		
		for (int j = 0; j < len2; j++) {
			if (arr1[i] == arr2[j]) {
				found = true;
			}
		}
		if (found) {
			for (int j = i + 1; j < len1; j++) {
				arr1[j - 1] = arr1[j];
				cout << arr1[j];
			}
			arr1[len1 - 1] = 0;
			i--;
		}
	}
}
int main()
{
	int arr1 = { 1,3,4 };
	int arr2 = { 3,5 };
	banish(arr1[4], arr2[4]);
}
*/
/*
#include<iostream>
using namespace std;

int banish(int arr1[], int len1, int arr2[],int len2) {
	bool remove = false;
	
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (arr1[i] == arr2[j]) {
				remove = true;
				for (int k = i; k < len1 -1; k++) {
					arr1[k] = arr1[k+1];
				}
				arr1[len1 - 1] = 0;
			}
		}
		if (remove == true) {
			i--;
		}
		remove = false;
		
	}for(int i=0;i<len1;i++)
	cout << arr1[i]<<";";
	return 0;
}
int main()
{
		int arr1[] = { 3,3,5,4,1,5,3 };
		int arr2[]= { 3,4 };
		banish(arr1,7, arr2,2);z
	
}
*/
#include<iostream>

using namespace std;
int banish(int a1[], int a, int a2[], int b) {
	bool equal = false;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (a1[i] == a2[j]) {
				equal = true;
				for (int k = i; k < a - 1; k++) {
					a1[k] = a1[k + 1];
				}
				a1[a - 1] = 0;
			}

		}
		if (equal == true) {
			i--;
		}
		
			equal = false;
		
	}
	for (int i = 0; i < a; i++) {
		cout << a1[i] << ",";
	}
	return 0;
}
int main() {
	int a1[] = { 42,3,9,42,42,0,42,9,42,42,17,8,2222,4,9,0,1 };
	int a2[] = { 42,2222,9 };
	 banish(a1, 17, a2, 3);


}
