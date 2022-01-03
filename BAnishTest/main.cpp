


#include<iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <cctype>


    using namespace std;

void wordStats(string str1) {
    ifstream myFile(str1);
    char c[30];
    char x[30];
    int count=0;
    while(myFile){
            for(int i=0;i<30;i++){
                    myFile>>c[i];
             x[i]=toupper(c[i]);
            if(x[i]>=65 && x[i]<=90)
                {
                    cout<<x[i];


                }

    }myFile.close();
}
}

    int main() {

        string filename = "tobe.txt";

        wordStats( filename );

        cout << endl;

        return 0;
    }







