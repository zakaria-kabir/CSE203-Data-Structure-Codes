
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

string zakaria(string s) {

    fstream File(s);

    string str;

    string a = "";
    string c = "";
    string n = "";
    string x = "";

    if (File.is_open()) {


        for (int i = 1; getline(File, str); i++) {


            for (int j = 0; j < str.size(); j++) {


                if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {

                    a += str[j];
                }

                if (isalpha(str[j] )){


                    if (str[j] != 'a' && str[j] != 'e' && str[j] != 'i' && str[j] != 'o' && str[j] != 'u' && str[j] != 'A' && str[j] != 'E' && str[j] != 'I' && str[j] != 'O' && str[j] != 'U') {

                        c += str[j];
                    }
                }

                if (str[j] >= '0' && str[j] <= '9') {

                    n += str[j];
                }
            }

        }


        for (int i = 0; i < a.size(); ++i) {
            x += a[i];
        }
        x += "\n";
        for (int i = 0; i < c.size(); ++i) {
            x += c[i];
        }
        x += "\n";
        for (int i = 0; i < n.size(); ++i) {
            x += n[i];
        }
    }
    else {
        cout << "File can't open .Try again later :) " << endl;
    }
    return x;

    File.close();
}
int main() {

    string str1 = "x.txt";
    string str2 = "z.txt";

    fstream file;
    file.open(str2);

    file << zakaria(str1)<<endl;
    file.close();
    return 0;
}

