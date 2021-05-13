#include<bits/stdc++.h>
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Iterative way*/
void reverseArray(int* arr,int n){
    int size=n-1;
    fo(i,n/2){
        int temp=arr[i];
        arr[i]=arr[size];
        arr[size]=temp;
        size--;
    }
}

/*Recursive Way*/
void reverseArray(int* arr,int start,int end){
    if(start>=end)
        return;
    int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
    reverseArray(arr,start+1,end-1);
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

    //reverseArray(arr,n);
    reverseArray(arr,0,n-1);
    
    fo(i,n){
        cout<<arr[i]<<" ";
    }
    return 0;
}