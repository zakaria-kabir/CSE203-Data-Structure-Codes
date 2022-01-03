#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<cctype>
#include<map>
using namespace std;

void wordStats(string file) {

    ifstream myFile(file);
    int totalNumOfWords = 0;
    double totalLenOfWords = 0;
    int count = 0;
    string str1;
    char charInWord;
    map< char, int > charFreq;

    cout << endl;
    if (!myFile.is_open()) {
        cout << "Error, bad input file." << endl;
    }
    else {

        while (true) {
            myFile >> str1;

            if (myFile) {
                totalNumOfWords++;
                totalLenOfWords += str1.size();

            }
        } cout << "Total words   " << " = " << totalNumOfWords << endl;
        cout << "Average length" << " = " << (totalLenOfWords / totalNumOfWords) << endl;
    }
        else
            {
             while (true) {
                myFile >> str1;
                if (myFile) {
                    for (int i = 0; i < totalLenOfWords; i++) {
                        if ((str1[i] >= 65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122)) {
                            for (int j = i + 1; j < totalLenOfWords; j++) {
                                if (toupper(str1[i]) == toupper(str1[j])) {
                                    count++;
                                    cout << str1[i];
                                }
                            }
                            /*charInWord = str1[i];
                            charInWord = toupper(charInWord);
                            charFreq[charInWord]++;*/
                        }
                    }
                }
            }
        
        myFile.close();




       
        cout << "Unique letters" << " = " << str1.size()-count << endl;


    }
}










int main() {

    string filename = "tobe.txt";

    wordStats(filename);

    cout << endl;

    return 0;
}







