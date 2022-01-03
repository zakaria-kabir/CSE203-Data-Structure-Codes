#include<iostream>

using namespace std;
int longestSortedSequence(int a[],int n){
	if (n == 0)
		return 0;

	int longest = 1;
	int count = 1;

	for (int i = 1; i < n; i++)
	{
		if (a[i] >= a[i - 1])
			count++;
		else
			count = 1;

		if (count > longest)
			longest = count;
	}

	return longest;
}
int main() 
{
	int array[] = { 3, 8, 10, 1, 9, 14, -3, 0, 14, 207, 56, 98, 12 };

	cout<<longestSortedSequence(array, 13);
}