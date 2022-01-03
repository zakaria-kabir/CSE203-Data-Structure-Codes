#include<bits/stdc++.h>
using namespace std;
int maximum(string file) {
	ifstream myfile(file);
	int max = INT_MIN;
	int num = 0;
	while (myfile >> num)

	{
		if (num > max)
		{
			max = num;
		}
	}
	return max;
	myfile.close();
}
int minimum(string file) {
	ifstream myfile(file);
	int min = INT_MAX;
	int num = 0;
	while (myfile >> num)

	{
		if (num < min)
		{
			min = num;
		}
	}
	return min;
	myfile.close();
}
int length(string myimfile, int startp, int end)
{

	ifstream myfile(myimfile);
	int number = 0;
	int count = 0;
	while (myfile >> number)
	{
		if (number >= startp && number <= startp + end)
		{
			count++;
		}
	}
	return count;

}
void elements(string file, int range, int array[], int min)
{

	ifstream myfile(file);
	int number = 0;
	int k = 0;
	while (myfile >> number)
	{
		if (number >= min && number <= min + range)
		{
			array[k] = number;
			k++;
		}
	}
}
void printhistorgram(int** historgram, int bin, int* element, int range, int m)
{
	cout << "Historgram with the bin size " << bin << " : " << endl;
	for (int i = 0; i < bin; i++)
	{
		cout << m << " - " << m + range << " : ";
		for (int j = 0; j < element[i]; j++)
		{
			cout << historgram[i][j] << " ";
		}
		cout << endl;
		m += range + 1;
	}
}
void freememory(int** historgram, int* elements, int binsz)
{
	delete[] elements;
	for (int i = 0; i < binsz; i++)
	{
		delete[] historgram[i];
		
	}
}
int main()
{
	int bin = 3;
	int b = 0, max = 0, min = 0;
	//cout << "enter the number of bin = ";
	//cin >> bin;
	int** historgram = new int* [bin];
	int* element = new int[bin];
	int* array = new int[bin];
	string file = "input.txt";
	max = maximum(file);
	min = minimum(file);
	b = min;
	int range;
	range = (max - min) / bin;
	for (int i = 0; i < bin; i++)
	{
		int countnumber = length(file, min, range);
		element[i] = countnumber;
		array = new int[countnumber];
		elements(file, range, array, min);
		historgram[i] = array;
		min += range + 1;
	}
	printhistorgram(historgram, bin, element, range, b);
	freememory(historgram, element,bin);
	return 0;
}
