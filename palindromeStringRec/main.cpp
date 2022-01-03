#include<iostream>
#include<string>


using namespace std;


bool Palindrome (string s,int first,int last){
        if(first==last)
            return true;
    if(s[first]==s[last])
        return true;
    if(first<last+1)
    return Palindrome (s,first+1,last-1);

return true;
}

bool isPalindrome(string str){
if(str.size()==0)

return true;

else
    Palindrome(str,0,str.size()-1);

}



int main()
{
    string str="MadaM";
    if(isPalindrome (str)==1)
        cout<<"yes";
    else
        cout<<"no";
}
