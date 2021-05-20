#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

int minimizeDifference(int* arr,int n,int k){
    sort(arr,arr+n);
    int ans = arr[n-1]-arr[0];
    int mini=arr[0]+k;
    int maxi=arr[n-1]-k;
    int mi,ma;
    fo(i,n-1){
        mi=min(mini,arr[i]-k);
        ma=max(maxi,arr[i]+k);
        if(mi<0) continue;
        ans=min(ans,ma-mi);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    
    cout<<minimizeDifference(arr,n,k);

    return 0;
}