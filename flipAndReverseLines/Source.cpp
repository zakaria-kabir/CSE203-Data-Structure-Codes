#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int flipAndReverseLines() {
    string str;
    ifstream myFile(str);
    int z = 0;
    for (int i = 0; !myFile.is_open(); ++i) {

        cout << "Input file name? ";
        getline(cin, str);
        myFile.open(str, ios::in);
        if (myFile.is_open()) {

            cout << endl;

            int x = 0, y = 0;
            string fline = "";
            string sline = "";
            while (getline(myFile, fline)) {
                if (getline(myFile, sline)) {
                    string s = "";
                    for (int i = sline.length() - 1; i >= 0; --i) {
                        s += (toupper(sline[i]));


                    }
                    cout << s << endl;
                    string f = "";
                    for (int i = fline.length(); i >= 0; --i) {
                        f += tolower(fline[i]);

                    }
                    cout << f << endl;
                    x++;

                }

                else {
                    string f = "";
                    for (int i = fline.length(); i >= 0; --i) {
                        f += toupper(fline[i]);

                    }
                    cout << f << endl;

                }
                y++;

            }
            z = x + y;

            return z;
        }
        cout << "Unable to open that file.  Try again." << endl;
    }



}
int main() {
    flipAndReverseLines();
}