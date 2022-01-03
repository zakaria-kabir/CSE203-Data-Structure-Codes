#include <iostream>
#include<cmath>
using namespace std;
/*
int sumOfSquares(int n){
if(n<0)
    throw 445;
    else if(n==0)
        return 0;
else

   return pow(n,2)+sumOfSquares(n-1);

}

int main()
{
   cout<<sumOfSquares(4);
}

*/
int a;
void evenDigits(int n){
if(n>0){
     a=n%10;
     if(a%2==0)
        cout<< a;
    evenDigits(n/10);

}

}

int main(){
evenDigits(123468);
return 0;
}


