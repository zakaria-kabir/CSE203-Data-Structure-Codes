#include<iostream>
using namespace std;
double circleArea(double r){
    double pi;
    double area;
    pi = 3.141592653589793238;
    area = pi * r * r;
    return area;
}
int main()
{
    double  radius;
    cout << "enter the radius= ";
    cin >> radius;
    circleArea(radius);
    cout << "circleArea " << circleArea(radius);

    return 0;
}