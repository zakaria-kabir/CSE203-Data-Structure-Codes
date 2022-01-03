#include <iostream>
using namespace std;
int  countDuplicates(int a[],int n){

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
    return count;
}
int main()
{
    int a[] = { 1, 4, 2, 4, 7, 1, 1, 9, 2, 3, 4, 1 };
    cout<<countDuplicates(a, 12);
}
