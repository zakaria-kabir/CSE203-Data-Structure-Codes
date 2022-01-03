#include<bits/stdc++.h>
using namespace std;


void fibonacci(int *&arr,int n){
	int i;
	arr[0]=0;
	arr[1]=1;
	for(i=2;i<n;i++){
	arr[i]=arr[i-1]+arr[i-2];
	}
}
void print(int *&arr,int l){
	for(int i=0;i<l;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	
	int n;
	cout<<"till how :";
	cin>>n;
	int *arr=new int[n];
	fibonacci(arr,n);
	print(arr,n);
}