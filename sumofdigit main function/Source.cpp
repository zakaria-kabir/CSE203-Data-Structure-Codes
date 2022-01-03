#include<iostream>
using namespace std;
int main() {
    int x,m,sum=0;
    cout << "Type an integer: ";
    cin >> x;
    while (x) {
        m = x % 10;
        sum = sum + m;
        x = x / 10;
    }
    cout << "Digit sum is "<<sum;
    return 0;
}
