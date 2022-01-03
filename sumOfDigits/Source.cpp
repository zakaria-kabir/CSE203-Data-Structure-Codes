#include<iostream>
#include<cmath>
using namespace std;
int sumOfDigits(int n){
    int m,sum,x;
    sum = 0;
    x = abs(n);
    while (x > 0) {
        m = x % 10;
        sum = sum + m;
        x = x / 10;
    }
    return sum;
}
int main()
{
    int n;
    cout << "number=";
    cin >> n;
    sumOfDigits(n);
    cout << "sumOfDigits" << "(" << n << ") " << sumOfDigits(n) << endl;
    return 0;
}