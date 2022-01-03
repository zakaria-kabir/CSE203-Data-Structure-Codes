#include<bits/stdc++.h>
using namespace std;
int main(){
	/*for(int i=0;i<10;i++){
		if(i%2){ //if condition e % dile ==0 na dile shudu mod krle j gulay 0 asche na se gulai dekhabe.karon baki gula vagfol mile zay
			cout<<i<<" ";
		}
	}
	cout<<endl;
	for(int i=0;i<10;i++){
			cout<<i%2<<" ";	//i%2 te 10 tar mod e dekhabe 
	}*/
	string s;
	string a;
	int len=0;
	int length=0;
	string text="";
	string str="z.txt";
	ifstream file(str);
	//while(file>>s){
		//text=text+s;
	//}
	//cout<<text<<endl;
	while(getline(file,text)){

	for (int i = 0, len = text.size(); i < len; i++)
    {int j=0;
    	
    	if (ispunct(text[i]))
        {
            text.erase(i--, 1);
            len = text.size();   
            }   
    	for ( j = 0;j < i; j++){
    		if(isalpha(text[i])){
    			if(toupper(text[i])==toupper(text[j])){
  				break;
    }
}
          
        }
        if(i==j){
        	//if(isalpha(text[i]))

        	cout<<text[i];
        
        
}
    }
}

	file.close();
}
