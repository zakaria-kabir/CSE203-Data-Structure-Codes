#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
bool isPalindrome(string s)
{
    if((s.length()==0)||(s.length()==1))
    {
        return true;
    }

  else if(toupper(s[0])!=toupper(s[s.length()-1]))
    {
        return false;

    }

return isPalindrome(s.substr(1,s.length()-2));


}
int main()
{

    cout<<isPalindrome("able was");
    return 0;
}*/
/*
#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s)
{
    if((s.length()==0)||(s.length()==1))
    {
        return true;
    }
    {
  if (s[0]==s[s.length()-1])
    {
        return isPalindrome(s.substr(1,s.length()-2));
    }


    if (s.at(0)!=toupper(s.at(s.length()-1)))
    {
     return false;
    }
    else {
         return true  ;
        }
}
}
int main()
{

    cout<<isPalindrome("axc cba");
    return 0;
}
*/
/*
void printBinary(int n)
{   int rem =0;
if(n<0){
        n=-1*n;
cout<<"-";}
    if (n==0 ||n==1) {
    cout<<n; }

    else  {rem=n%2;
    printBinary(n/2); cout<<rem;


}
}
int main()
{
printBinary(-43);

}
*/
/*
void reverseLines(ifstream& input) {
string a="";

    if (getline(input,a)) {
    reverseLines(input);
        cout<<a<<endl;
    }
    input.close();

}
int main()
{
    ifstream str("input.txt");
    reverseLines(str);

}
*/
/*
#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s)
{
    if((s.length()==0)||(s.length()==1))
    {
        return true;
    }
    {
  if (toupper(s[0])==toupper(s[s.length()-1]))
    {
        return isPalindrome(s.substr(1,s.length()-2));
    }


    if (s.at(0)!=toupper(s.at(s.length()-1)))
    {
     return false;
    }
    else {
         return true  ;
        }
}
}
int main()
{
    cout<<isPalindrome("able was I ere I saw Elba");
    return 0;
}
*/
bool checkChars (string a,int b,int c ) {
    if(b>=c)
        return true;
    if(toupper(a[b])!=toupper(a[c]))
     return false;
    return checkChars(a,b+1,c-1);

}
bool isPalindrome(string s) { int b=0; int c=s.size()-1;
return checkChars(s,b,c);
}
int main()
{
    cout<<isPalindrome("Step on NO pEs");
    return 0;
}

/*
void recursionMystery4(int n) {

if (n <= 1) {

cout << "*";

} else if (n == 2) {

recursionMystery4(n - 1);

cout << "*";

} else {

cout << "(";

recursionMystery4(n - 2);

cout << ")";

}

}
*/

