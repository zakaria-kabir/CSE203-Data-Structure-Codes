#include <bits/stdc++.h>
using namespace std;
int occurrence(int *arr,int n,int j){

    if(n<=0){
        return 0;
    }
    else if(arr[n]==j){
        return 1+ occurrence(arr,n-1,j);
    }
    else{
        return occurrence(arr,n-1,j);
    }
}
int main() {
    int n=7;
    int j=2;
    int *arr=new int[n]{1,2,2,4,2,2};
    cout<<occurrence(arr,n,j);
}
