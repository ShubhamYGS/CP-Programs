#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

bool checkPalindrome(string str,int i){
    if(i>=str.size()/2)
        return true;
    if(str[i]!=str[str.size()-i-1])
        return false;
    return checkPalindrome(str,i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;

    cin>>str;

    if(checkPalindrome(str,0)){
        cout<<"Yes, it's Palindrome!";
    } else {
        cout<<"No, it's not Palindrome!";
    }
    
    return 0;
}