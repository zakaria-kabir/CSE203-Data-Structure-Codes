#include<bits/stdc++.h>
using namespace std;
int sum(int* arr,int n){
	if(n<=0){
return 0;
	}
	else{
		return sum(arr,n-1)+arr[n-1];
	}
}

int main(){
	int n=0;
	int *array=new int[0];
cin>>n;
array=new int[n]; 
sum(array,n);

}