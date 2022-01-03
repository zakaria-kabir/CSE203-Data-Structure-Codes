#include<iostream>
using namespace std;

int printBinary(int decimal) {
  
    if (decimal > 1 || decimal < 0) {
        int decimal1 = abs(decimal);
        if (decimal1 > 0) {
            if (decimal < 0)
                cout << "-";
            cout << ((decimal1 % 2) + 10 * printBinary(decimal1 / 2));
        }
    }
    else
        
cout << decimal;
    return 0;
}
int main() {
    
    printBinary(2000);
    
}
