#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

void rotateByOne(int* arr,int n){
    int extra=arr[0];
    foi(i,1,n){
        if(i==n-1){
            swap(arr[0],arr[i]);
            swap(extra,arr[i]);
        } else{
            swap(extra,arr[i]);
        }
    }
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
    
    rotateByOne(arr,n);

    fo(i,n){
        cout<<arr[i]<<" ";
    }

    return 0;
}