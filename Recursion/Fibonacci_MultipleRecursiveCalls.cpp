#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Time complexity = 2^n
int findFibo(int n){
    if(n<=1)    return n;
    return findFibo(n-1)+findFibo(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    cout<<findFibo(n);
    
    return 0;
}