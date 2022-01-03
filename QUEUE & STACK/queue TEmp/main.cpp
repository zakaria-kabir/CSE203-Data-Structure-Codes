#include <iostream>
#include <stack>
using namespace std;

//function to check matching brackets
int matchingPair(char a, char b)
{
    if(a=='{' && b=='}')
        return 1;
    else
    if(a=='[' && b==']')
        return 1;
    else
    if(a=='(' && b==')')
        return 1;
    else
        return 0;
}

int main()
{
    
    stack<char> st;
    string s="for (i=0;i&lt;a(3};i++) { foo{); ); ";
    int flag=0;
   int i=0;
    for ( i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } 
	else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
        if (st.empty() || !matchingPair(st.top(),s[i])) {
           flag=1;
            break;
        } else {
            st.pop();
        }
    }
    }
    
    if(st.empty()&&flag==0)
        cout<<"Brackets are balanced and matched\n";
    else{
    	 cout<<"Not a matching pair\n";
    }
    cout<<i<<endl;
    return 0;
}
