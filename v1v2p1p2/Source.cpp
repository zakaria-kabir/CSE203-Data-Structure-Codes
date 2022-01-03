#include<iostream>
using namespace std;
int main()
{

	int v1 = 1;

	int v2 = 2;

	int* p1 = &v1;

	int* p2 = &v2;
	
	*p1 +=*p2;
	
	*p2 = *p1;
	
	*p2 = *p1 + *p2;


		cout << v1 << " " << v2 << endl;

	cout << *p1 << " " << *p2 << endl;

}