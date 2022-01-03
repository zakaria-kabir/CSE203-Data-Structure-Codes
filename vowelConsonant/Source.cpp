#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int vowel(string ch) {
    int vowel = 0;

    for (int i = 0; i < ch.length(); i++) {
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
        {
            vowel++;

        }

    }

    return vowel;
}
int number(string s) {
    int num = 0;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] >= '0' && s[i] <= '9')
        {
            num++;

        }
    }

    return num;
}
int countchar(string c) {

    int con = 0;
    for (int i = 0; i < c.size(); i++) {

        if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
        {
            con++;
        }
    }

    return con;
}

void count(string str) {
    ifstream myfile(str);
    string s="x.txt";
    fstream file(s);
    string line;
    string s = "";
    int v = 0;
    int num = 0;
    int cha = 0;

    if (myfile) {
        while (getline(myfile, line)) {
            v += vowel(line);
            cha += countchar(line);
            num += number(line);
            s == printvowel(line);
            
        }
        cout << v << " vowel  " << num << " number " << cha - v << " consonant ";
    }
    
    myfile.close();
}
int main() {
    string file = "z.txt";

    count(file);


    return 0;

}