#include <iostream>

using namespace std;
/*
int sumOfDigits(int num)
{

    if(num == 0)
        return 0;

    return ((num % 10) + sumOfDigits(num / 10));
}*/
int digitSum(int n){

    if(n == 0)
        return 0;
    else{
    {int sum;
         int a;
    sum = sum + (n%10);
    a = n/10;
        digitSum(a);
        return sum;
    }
    }
}



int main()
{
    cout<<digitSum(18);
}
