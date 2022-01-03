#include<iostream>
#include<string>
using namespace std;

string removeAll(string str, char c) {
    string temp = "";


    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != c) {
            temp = temp + str[i];
        }
    }
    str = temp;

    return str;


}
int main() {
    string str = "Summer is here!";
    char c = 'e';
    cout<<removeAll(str, c);
    return 0;
}