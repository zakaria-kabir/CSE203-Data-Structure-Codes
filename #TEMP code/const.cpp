#include<bits/stdc++.h>
using namespace std;
int main(){
	//stack
	char a[4]={'i','c','e','\0'};
	cout<<a<<endl;
	char b[]={'r','i','c','e','\0'};
	cout<<b<<endl;
	char c[]="nice";
	cout<<c<<endl;
	//heap
	char *d=new char[6]{'s','p','i','c','e'};
	cout<<d<<endl;
	//read-only
	const char* f="price";
	cout<<f<<endl;
	cout<<endl;
	//address of array
	cout<<&a<<endl;
	cout<<&b<<endl;
	cout<<&c<<endl;
	cout<<&d<<endl;
	cout<<&f<<endl;
	cout<<endl;
	//address of elements
	cout<<(void*)&a[0]<<endl;// void pointer holds address of int 'a' 
	cout<<(int*)&a[1]<<endl;// int pointer holds address of int 'a' 
	//cout<<(char*)&c[2]<<endl;//it wont work.
	cout<<&d<<endl;
	cout<<&f<<endl;
}