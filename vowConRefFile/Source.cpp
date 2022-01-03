#include<iostream>
#include <fstream>
#include<string>
#include <cmath>
#include<cctype>
using namespace std;
void numOfVowConsNum(string st, int& vowel, int& cons, int& num) {

    ifstream file(st);
    string str;
    if (file.is_open()) {
        for (int i = 1; getline(file, str); i++) {
            int len = str.length();
            

            for (int i = 0; i < len; ++i) {
                if (isdigit(str[i])) {
                    num = num + 1;
                }
                else if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'|| str[i] == 'u' || str[i] == 'A'|| str[i] == 'E' || str[i] == 'I'|| str[i] == 'O' || str[i] == 'U') {
                    vowel = vowel + 1;
                }
                else if((isalpha(str[i]))) {

                    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                        cons++;
                        
                    }

                }
            }

        }
            cout << "Number of vowels : " << vowel << endl;
            cout << "Number of consonant : " << cons << endl;
            cout << "Numbers : " << num << endl;
        
        
    }file.close();
}
int main() {
    int vowel = 0; int cons = 0; int num = 0;
    string myStr = "z.txt";
    
    
    numOfVowConsNum(myStr, vowel, cons, num);
    return 0;
}