#include <iostream>
#include <stack>
using namespace std;

//function to check matching brackets
void removeSpaces(string &str) 
{ 

    int count = 0; 

    for (int i = 0; i<str.length(); i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; 
                                   
    str[count] =  '\0'; 
} 

bool startend(char a, char b)
{
    if(a=='{'&&b=='}')
        return true;
    else if(a=='['&&b==']')
        return true;
    else if(a=='('&&b==')')
        return true;
    else
        return false;
}


int checkBalance(string code) {

  stack<char>s;
	    int flag=0;
   int i=0;
    for (i=0;i<code.length();i++){
        if (code[i]=='('||code[i]=='{'||code[i]=='['){
            s.push(code[i]);
        } 
	else if(code[i]==')'||code[i]=='}'||code[i]==']'){
        if (s.empty()||!startend(s.top(),code[i])) {
           flag=1;
            break;
        } else {
            s.pop();
        }
    }
    }
    
 if(s.empty()&&flag==0)
        return -1;
    else{
    	return i;
    }
}




int check(string str)
{
char c='(';char d=')';
   
    char e='{';char f='}';
   
    char g='[';char h=']';
  
    if(str.length() == 0)
    {
        return -1;
    }
    int len = str.length();
    stack<char> s;
    int i=0;
    int flag=0;
    for( i  = 0;i<len;++i)
    {
        if(str[i] == '(' || str[i] == '{' ||str[i]=='[' )
        {
            s.push(str[i]);
        }
         else if(str[i] == ')' ||str [i]== '}'||str[i]==']')
        {
             if(!s.empty())
             {
                if(s.top()==c&&(str[i]==f||str[i]==h)){
                flag=1;
                    break;
                }
                 
                 if(s.top()==e&&(str[i]==d||str[i]==h)){
                flag=1;
                     break;
                }
                 
                 if(s.top()==g&&(str[i]==f||str[i]==d)){
                flag=1;
                     break;
                }
                 
             }
            else if(s.empty()){
                flag=1;
                break;
            }
          
            s.pop();
            
             
        }

    }
 if(s.empty()&&flag==0)
        return -1;
    else{
        return i;
    }
}








int main()
{
    
    string s="{{[(shaba){ fool()}; ] (and) g}a{d{h}a}}";
    if(checkBalance(s)==-1){
        cout<<"nice job .no error !"<<endl;
    }
    else
    cout<<"error at "<<checkBalance(s)<<" index"<<endl;
if(check(s)==-1){
        cout<<"nice job .no error !";
    }
    else
    cout<<"error at "<<checkBalance(s)<<" index"<<endl;

    return 0;
}