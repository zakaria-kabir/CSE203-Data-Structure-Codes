#include<iostream>
using namespace std;

int decimalToBinary(int decimal) {
    int binary = 0;
    int i = 1;
    while (decimal) {

        binary = binary + decimal % 2 * i;
        i *= 10;
        decimal = decimal / 2;
    }
    return binary;

}

/*
int decimalToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
      cout<< binaryNum[j];
    
}*/
int main() {
    int decimal_number;
    cin >> decimal_number;
    cout << decimalToBinary(decimal_number);
     return 0;
}


