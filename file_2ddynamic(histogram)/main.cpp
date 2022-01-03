#include<bits/stdc++.h>
using namespace std;

void memory(string file, int **his,int *elements,int bin) {
	int counter = 0;
	int max = INT_MIN, min = INT_MAX;
	fstream myfile(file);
	while (myfile >> elements[counter])
	{
		if (elements[counter] > max)
			max = elements[counter];
		if (elements[counter] < min)
			min = elements[counter];
		counter++;
	}
	int x = max - min;

	int binnum = x / bin;

	for (int i = min; i <= bin; i++) {
            cout << min << "-" << min + binnum << " : ";

		for (int j = 0; j < counter; j++) {
			if (elements[j] >= min && elements[j] <= min + binnum) {
                cout<<elements[j]<<" ";
                //cout<<(char)254<< " ";
			}
		}
		cout<<endl;
min += 1 + binnum;
	}
}
int main() {
	int numberofbin =3;
	//cout<<"enter number of bin: ";
	//cin>>numberofbin;
	int** histogram = new int* [numberofbin];
	int* numInbins = new int[numberofbin];
	string file ="z.txt";
	memory(file, histogram, numInbins, numberofbin);
}
