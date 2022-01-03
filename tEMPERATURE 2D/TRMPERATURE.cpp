#include<bits/stdc++.h>
using namespace std;
int main()
{
	int** tem = new int* [3];
	int* array = new int[11]{ 1,19,20,12,30,11,15,25,35,13,-5 };
	int a = 0;
	int b = 0;
	int c = 0;
	int col1 = 0;
	int col2 = 0;
	int col3 = 0;
	for (int i = 0; i < 11; i++)
	{
		if (array[i] <= 10)
		{
			col1++;
		}
		else if (array[i] > 10 && array[i] < 20)
		{
			col2++;
		}
		else if (array[i] > 20)
		{
			col3++;
		}
	}
		tem[0] = new int[col1];
		tem[1] = new int[col2];
		tem[2] = new int[col3];
		for (int i = 0; i < 11; i++)
		{
			if (array[i] <= 10)
			{
				tem[0][a] = array[i];
				a++;
			}
			else if (array[i] >= 11 && array[i] < 20)
			{
				tem[1][b] = array[i];
				b++;
			}
			else if (array[i] >= 20)
			{
				tem[2][c] = array[i];
				c++;
			}
		}
		for (int i = 0; i < a; i++)
		{
			cout << tem[0][i] << " ";
		}cout << endl;
		for (int i = 0; i < b; i++)
		{
			cout << tem[1][i] << " ";
		}
		cout << endl;
		for (int i = 0; i < c; i++)
		{
			cout << tem[2][i] << " ";
		}cout << endl;
}