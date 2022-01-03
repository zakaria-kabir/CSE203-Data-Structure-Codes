#include<bits/stdc++.h>
using namespace std;
int main()
{
	char* fseme = new char[3]{ 'A','B','A' };
	char* sseme = new  char[4]{ 'B','A','A','A' };
	char* tseme = new char[2]{ 'A','B' };
	char** final = new char* [3];
	final[0] = fseme;
	final[1] = sseme;
	final[2] = tseme;
	char* a = final[0];
	{
		for (int i = 0; i < 3; i++)
		{
			cout << a[i] << " ";
		}cout << endl;

	}
	char* b = sseme;
	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	char* c = tseme;
	for (int i = 0; i < 2; i++)
	{
		cout << c[i] << " ";

	}
	cout << endl;
	delete[] final;
	return 0;



}