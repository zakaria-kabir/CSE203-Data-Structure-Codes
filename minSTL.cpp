#include <iostream> 
#include <algorithm> 
using namespace std; 


bool comp(int a, int b) 
{ 
	return (a < b); //a>b ->maximum
} 
int main() 
{ 

	cout << min({ 1, 2, 3, 4, 5, 0, -1, 7 }, comp) << "\n"; 

	return 0; 
} 
