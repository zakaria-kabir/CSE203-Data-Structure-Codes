#include<iostream>
using namespace std;

void passByValue(int a) {
	a=548;//here just changing the value in function bt main e etar kno effect nai
	cout <<"PASS BY VALUE " << endl;
	cout << "a is " << a << endl;
	cout << "&a is " << &a << endl;
}

void passByReference(int& a) {//function got the address of x,now a&x have same address
	a = 548;//change the value to 548 in that addresss
	cout << "PASS BY REFERENCE " << endl;
	cout << "a is " << a << endl;
	cout << "&a is " << &a << endl;
}
//pass by pointer
void passByAddress(int* a) {//a=&x   *a pointed to the value ,address of x .... 
	*a = 548;//
	cout << "PASS BY ADDRESS " << endl;
	cout << "a is " << a << endl;
	cout << "&a is " << &a << endl;
	cout << "*a is " << *a << endl;
}

// void passBypointerTopointer(int*& a) 

int main() {
	int x = 5;
	int* y;//declaring a pointer named y
	y = &x; //x er address y er vitre jacche which is a pointer


	cout << "y is " << y << endl;
	cout << "&y is " << &y << endl;//address of y is different ,pointer y and &x is same
	cout << "*y is " << *y << endl;//addressing that memory location to get value
	cout << "x is " << x << endl;
	//cout << *x << endl; //*x cant be done because x is not a pointer typ var
	cout << "&x is " << &x << endl;// address of x
	
	passByValue(x);//pass by value
	cout << "x is " << x << endl;
	cout << "&x is " << &x << endl;

	passByReference(x);//passing the  value of x in function 
	cout << "x is " << x << endl;
	cout << "&x is " << &x << endl;

	passByAddress(y);//passing pointer pointed to location of x
	cout << "y is " << y << endl;
	cout << "&y is " << &y << endl;
	cout << "x is " << x << endl;
	cout << "&x is " << &x << endl;

}
