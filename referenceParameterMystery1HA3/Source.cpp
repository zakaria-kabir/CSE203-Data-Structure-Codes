#include <iostream>

using namespace std;

void mystery(int z, int& x, int y) {

    cout << y << " + " << z << " = " << x << endl;
    x++;
    y--;
}

int main() {

    int a = 4;
    int b = 7;
    int c = -2;

    mystery(b, a, c);
    mystery(c, b, 3);
    mystery(b, c, b + a);

  

    return 0;
}