/*
#include<iostream>

using namespace std;

int isVowel(char c) {
    char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
    for (int i = 0; i < sizeof(vowels) / sizeof(vowels[0]); i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }

    return 0;
}
int main() {
    char c;
    cin >> c;
    isVowel(c);
    return 0;

}
*/
/*
#include <iostream> 
using namespace std;


bool isVowel(char a)
{
	bool b;
	switch (a)
	{
	case 'a': 	b = true;  break;
	case 'e':   b = true;  break;
	case 'i':   b = true;  break;
	case 'o':   b = true;  break;
	case 'u':   b = true;  break;
	case 'A':   b = true;  break;
	case 'E':   b = true;  break;
	case 'I':   b = true;  break;
	case 'O':   b = true;  break;
	case 'U':   b = true;  break;

	default:
		b = false;
	}

	return b;
}


int main()
{
	char c;
	bool r;

	cout << "  Enter any character :: ";
	cin >> c;
	

	r = isVowel(c);

	if (r==true)
		cout << "  Character = Vowel " << endl;
	else
		cout << "  Character = Consonent " << endl;


	
	return 0;
}

*/
#include<iostream>
using namespace std;

bool isVowel(string s) {
	if (s =="a" ||s== "e" ||s== "i" || s == "o" || s == "u" || s == "A" || s == "E" || s == "I" || s == "O" || s == "U" )
		return true;
	else
		return false;
	
}

int main() {
	string c;
	cin >> c;
	cout<<isVowel(c);
	
}