#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

int findMaxSubArray(int* arr, int n){
    int maxSumFinal=arr[0],sum=0;

    fo(i,n){
        sum+=arr[i];
        if(maxSumFinal<sum){
            maxSumFinal=sum;
        }
        if(sum<0){
            sum=0;
        }
    }

    return maxSumFinal;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }

    cout<<findMaxSubArray(arr,n);

    return 0;
}