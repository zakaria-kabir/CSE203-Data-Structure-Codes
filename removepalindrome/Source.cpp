#include<iostream>
#include<string>
#include <cctype>

using namespace std;


bool isPalindrome(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
	}
	if (str.size() <= 1)
		return true;

	char first = str[0];
	char last = str[str.size() - 1];

	if (first == last) {
		string shorter = str.substr(1, str.size() - 2);
		return isPalindrome(shorter);
	}
	return false;
}

void removePalindromes(string str[], int n) {

	for (int i = 0; i < n; i++) {
		bool checkpalindrome = isPalindrome(str[i]);
		if (checkpalindrome)
			str[i] = "";
		if (str[i] == "") {
			cout << "\"\" "<<",";
		}
		else
			cout << "\""<<str[i] +""<<"\""<<",";
	}
}

int main() {
	string a[] = { "Madam", "raceCAR", " !  ", "hi", "A", "Abba", "banana", "dog God","STOP otto POTS", "Madame", "C++", "LevEL", "she sells seashells" };
	removePalindromes(a, 13);
	
	return 0;
}


