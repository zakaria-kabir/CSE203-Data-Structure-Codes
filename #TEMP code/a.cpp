
#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b);
void read(string s) {
	//string st = "output.txt";
	int n =0;
	int c=0;
	int arr_size = 0;
	int i = 0;
	ifstream file(s);
	
	while (file >> n) {
		
		//if(isdigit(n))
		c++;
	}
	//cout<<c<<endl;
	file.close();
	file.open(s);
	int arr[c];
 	n=0;
	while (file >> n) {
		arr[i]=n;
		i++;
	}
	arr_size = sizeof(arr) / sizeof(arr[0]);

	int left = 0, right = arr_size - 1;
	while (left < right)
	{

		while (arr[left] % 2 == 0 && left < right)
			left++;

		while (arr[right] % 2 == 1 && left < right)
			right--;

		if (left < right)
		{

			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	
	ofstream myfile("output.txt");
	for (int i = 0; i < 100; i++) {
		myfile << arr[i]<< " " ;
	}
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void write(string str) {
	fstream file(str);
	if (file.is_open()) {
		for (int i = 0; i < 100; i++) {
			file << rand() % 100 << " ";
		}
	}file.close();
	read(str);
	
}

int main() {
	string r = "input.txt";

	write(r);

}