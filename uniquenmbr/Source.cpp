
#include <iostream>
using namespace std;
int  numUnique(int a[], int n) {

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (a[i] == a[j])
            {
                count++;
                break;
            }
        }

    }
    return (n - count);

}
int main()
{
    int a[] = { 5, 7, 7, 7, 8, 22, 22, 23, 31, 35, 35, 40, 40, 40, 41 };
    cout << numUnique(a, 15);
    return 0;
}


