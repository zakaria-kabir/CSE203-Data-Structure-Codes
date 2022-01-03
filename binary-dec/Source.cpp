#include<iostream>
using namespace std;

int binaryToDecimal(int n) {
    int decnum = 0;
    int base = 1;
    int temp = n;
    while (temp) {
        int last = temp % 10;
        temp = temp / 10;
        decnum += last * base;
        base = base * 2;
    }
   cout <<decnum << endl;
    //return decnum;
   return 0;
}
int main() {
    int a;
    cin>>a;
    binaryToDecimal(a);
    return 0;
}
