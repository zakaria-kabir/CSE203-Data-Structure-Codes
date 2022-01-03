#include <iostream>

using namespace std;

/*
int func(int x){
x=59;
return x;
}
int main()
{
    int a=12;
  cout<<func(a);
  cout<<"\n"<<a;
  a=func(a);
  cout<<"\n"<<a;
}
*/
//reference

void func(int &a/**a*/,int &b/**b*/)
{
    int temp=a;//int temp =*a
    a=b;//*a=*b
    b=temp;//*b=temp

}
int main()
         {
             int a=0;int b=1;
             func(a,b);//func(*a,*b)
             cout<<"a "<<a<<" b "<<b;
         }

int main()
{
    int a=12;
    int &x=a;

    cout<<"x="<<x;
    cout<<"a="<<a;
}
