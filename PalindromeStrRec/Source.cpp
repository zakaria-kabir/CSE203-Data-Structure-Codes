#include<iostream>
#include<string>
#include<cctype>

using namespace std;



bool Palindrome(string s, int first, int last) {
    if (s.size()==1)
        return true;
    if (first >= last)
        return true;
    if (toupper(s[first]) != toupper(s[last]))
        return false;
    
        
        return Palindrome(s, first + 1, last - 1);

    return true;
}
bool isPalindrome(string str) {
    
    if (str.size() == 0)

        return true;

    else
        return Palindrome(str, 0, str.size() - 1);

}


int main()
{
    string str = "Madam";
    if (isPalindrome(str)==true)
        cout << "yes";
    else
        cout << "no";
    

}

/*
#include<iostream>
using namespace std;
bool isPalindrome(string str) {
	int len = str.length();

	if(len==0|| len==1)
        return true;
	else if (toupper(str[0]) != toupper(str[len - 1])) {
		return false;
	}

    return isPalindrome(str.substr(1, len - 2));


}
int main()
{
    bool x=isPalindrome("racecar");
    if(x==true){
        cout<<"true";
    }
    else
        cout<<"false";


}
*/