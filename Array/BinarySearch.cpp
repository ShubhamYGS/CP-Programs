#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Iterative Version
int binarySearch(int arr[],int n,int ele){
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(ele==arr[mid])
            return mid;
        else if(ele<arr[mid])
            high=mid-1;
        else if(ele>arr[mid])
            low=mid+1;
    }

    return -1;
}

//Recursive Version
int binarySearchRecursive(int arr[],int n,int ele,int low, int high){
    if(low<=high){
        int mid=(low+high)/2;
        if(ele==arr[mid])
            return mid;
        else if(ele<arr[mid])
            return binarySearchRecursive(arr,n,ele,low,mid-1);
        else if(ele>arr[mid])
            return binarySearchRecursive(arr,n,ele,mid+1,high);
    }
    return -1;
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
    
    int arr[n];

    fo(i,n)
        cin>>arr[i];

    int ele;
    cin>>ele;

    //int index=binarySearch(arr,n,ele);
    int index=binarySearchRecursive(arr,n,ele,0,n-1);
    
    if(index==-1)
        cout<<"Element not found";
    else   
        cout<<"Element found at index: "<<index;

    return 0;
}