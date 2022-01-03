#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=0;
	string r="a.txt";
	string w="x.txt";
	fstream file(r);
	fstream myfile(w);
	while(file>>x){
		myfile<<x<<" ";
	}
	myfile.close();
	file.close();
}