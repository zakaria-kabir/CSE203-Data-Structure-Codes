/*
#include <iostream>
using namespace std;

int main() {

   int row=0;
   cout<<"input index of array: ";
   cin>>row;
   int **arr1= new int*[row];
   int *arr2= new int[row];
   for(int j=0;j<row;j++) {
       int sizeofarray=0;
       cout<<"input size of "<<j+1<<" array: ";
       cin>>sizeofarray;
       arr2[j]=sizeofarray;
       int *arr=new int[sizeofarray];
       arr1[j]=arr;
       for (int i = 0; i < sizeofarray; i++) {
           cin >> arr[i];
       }
   }
   for(int i=0;i<row;i++){
        int *a=arr1[i];
        for(int j=0;j<arr2[i];j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
   }
}
*/
//by Function
#include <bits/stdc++.h>

using namespace std;

int input(int **marks,int *course,int Nsem){
    for(int i=0;i<Nsem;i++) {
        int Ncourse;
        cout << "number of course taken in sem " << i+1<<" : ";
        cin>>Ncourse;
        course[i]=Ncourse;
        marks[i]=new int[Ncourse];

        for(int j=0;j<Ncourse;j++){
            cout<<"number in course "<<j+1<< " : ";
            cin>>marks[i][j];
        }
    }
}
int output(int **mark,int* course,int nsem){
    cout<<"\n \n mark sheet :"<<endl;
    for(int i=0;i<nsem;i++){
        cout<<"marks obtained in sem "<<i+1<< " : "<<endl;
        for(int j=0;j<course[i];j++){
            cout<<"course "<<j+1<<" marks : "<<mark[i][j] << " ";
        }
        cout<<endl;
    }
}
int main(){
    int numSem;
    cout<<"enter number of sem u have done :";
    cin>>numSem;
    int *coursePerSem=new int[numSem];
    int **marksPerCourse=new int*[numSem];
    input(marksPerCourse,coursePerSem,numSem);
    output(marksPerCourse,coursePerSem,numSem);
}
