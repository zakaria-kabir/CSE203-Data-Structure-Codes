#include <iostream>
#include <string>
#include <fstream>


using namespace std;
/*
void inputStats(string filename) {

    ifstream file(filename);
    string str;

    if (file.is_open()) {
        int i = 0;
        int longest = 0;
        double totalLengths = 0;

        for (i = 1; getline(file, str); i++) {
            int len = str.length();
            totalLengths += len;
            cout << "line " << i << " has " << len << " chars" << endl;
            if (len > longest)
                longest = len;
        }
        cout << --i << " lines;";
        cout << " longest = " << longest << ", average = " << totalLengths / i << endl;
    }
    else {
        cout << "no output";
    }
    file.close();
}

int main() {

    string file = "carroll.txt";

    inputStats(file);

 
    return 0;
}
*/

/*
int isVowel(char c) {
    char v[10] = {  'a', 'e', 'i', 'o', 'u' ,'A', 'E', 'I', 'O', 'U' };
    for (int i = 0; i < sizeof(v) / sizeof(v[0]); i++) {
        if (c == v[i]) {
            return 1;
        }
    }
    return 0;
}
int countVowel(string s) {
    int vowel = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            vowel++;
        }
    }

    return vowel;
}

void vowelStats(string file) {
    ifstream fiename(file);
    if (fiename.is_open()) {
        string newline, line;
        int Num = 0;
        int Count = 0;
        int max = 0;
        int vowel = 0;
        double total = 0.0;
        double avg = 0.0;

        while (getline(fiename, line)) {
            Num++;
            Count = line.size();
            total += Count;
            vowel = countVowel(line);

            if (Count > max) {
                max = Count;
            }
            cout << "Line " << Num << " has " << Count << " chars and " << vowel << " vowels" << endl;

            newline = line;
        }
        avg = total / Num;

        cout << Num << " lines; longest = " << max << ", average = " << avg << endl;
    }
    fiename.close();
}
int main() {

    string file = "carroll.txt";

    vowelStats(file);


    return 0;
}
*/

