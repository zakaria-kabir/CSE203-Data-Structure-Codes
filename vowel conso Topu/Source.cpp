#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
void vowelStats(string str1) {
    ifstream myFile(str1);
    
    string str;

    if (myFile.is_open()) {
        int number = 0;
        int con = 0;
        int vowel = 0;

        for (int i = 1; getline(myFile, str); ++i) {

            int countv = 0;
            int countc = 0;
            int countnum = 0;
            for (int i = 0; i < str.length(); ++i) {
                if ((str[i]) == 'a' || (str[i]) == 'e' || (str[i]) == 'i' || (str[i]) == 'o' || (str[i]) == 'u' || (str[i]) == 'A' || (str[i]) == 'E' || (str[i]) == 'I' || (str[i]) == 'O' || (str[i]) == 'U') {
                    countv++;
                   

                }
                if ((isalpha(str[i]))) {

                    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                        countc++;
                        
                    }

                }
                if (str[i] >= '0' && str[i] <= '9') {
                    countnum++;
                    
                }
            }

            vowel += countv;
            con += countc;
            number += countnum;


        }
        cout << "\nNumber of vowels: " << vowel << endl;
        cout << "Number of consonant: " << con << endl;
        cout << "Number of number: " << number << endl;
    }
      
    else {
        cout << "Unable to open!" << endl;
    }
    
    
    
    
    myFile.close();
}
int main() {
    string str1 = "x.txt";
    vowelStats(str1);
    return 0;
}