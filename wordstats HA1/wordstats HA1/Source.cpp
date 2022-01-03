#include<iostream>
#include<string>

using namespace std;
int main()
{
	string text;
	getline(cin, text);
	cout << text;
	int word = 0;
	float avg = 0;
	int letters = 0;
	for (int i = 0; i != '\0'; i++) {
			word++;
	}cout << "\nword=" << word;
}
