#include <bits/stdc++.h>
using namespace std;

/*Symbol (+,-) are having second priority and (*,/) are having first prirority. 
symbol  OutStackPre  InStackPre
 +,-        1           2
 *,/        3           4
  ^         6           5   (right to left associativity)
  (         7           0
  )         0           ?
*/

int outStackPrecendence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else if(c==')')
        return 0;
    return 0;
}

int inStackPrecendence(char c){
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='(')
        return 0;
    return 0;
}

//Convert infix to postfix
string afterPostFixConversion(string str){
    string postfix="";
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if((str[i]>=97 && str[i]<=122) || (str[i]>=48 && str[i]<=57)){
            postfix+=str[i];
        } else {
            if(s.empty()){
                s.push(str[i]);
            } else if(outStackPrecendence(str[i])>inStackPrecendence(s.top())){ 
                s.push(str[i]);
            } else if(outStackPrecendence(str[i])==inStackPrecendence(s.top())){
                s.pop();
            } else {
                postfix+=s.top();
                s.pop();
                i--;
            }
        }
    }

    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

//Evaluating postfix (only works on number)
int evaluatePostfix(string str){
    stack<int> st;
    for(int i=0;i<str.length();i++){
        if(str[i]>=48 && str[i]<=57){
            st.push(str[i]-48);
        } else {
            int second=st.top();
            st.pop();
            int first=st.top();
            st.pop();
            switch(str[i]){
                case '*':
                    st.push(first*second);
                    break;
                case '/':
                    st.push(first/second);
                    break;
                case '+':
                    st.push(first+second);
                    break;
                case '-':
                    st.push(first-second);
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string str;
    getline(cin,str);

    string postfix=afterPostFixConversion(str);
    cout<<"Postfix: "<<postfix<<"\n";
    cout<<"Result: "<<evaluatePostfix(postfix);

    return 0;
}