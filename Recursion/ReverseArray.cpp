#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Using two pointers left and right
void reverseArray(int *arr,int l,int r){
    if(l<=r)
        swap(arr[l],arr[r]);
    else
        return;
    return reverseArray(arr,l+1,r-1);
}

//Using single variable
void reverseArray1(int *arr,int i,int n){
    if(i>=n/2)
        return;
    swap(arr[i],arr[n-i-1]);
    return reverseArray1(arr,i+1,n);
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

    reverseArray(arr,0,n-1);
    //reverseArray1(arr,0,n);

    fo(i,n){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}