#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Improving Linear Search Algorithm
1. Using transposition: Every time you seacrh the element shift it by 1 position back.
So that every time you search you will get the element in 1 less operation.
2. Using Move to front/head: In this method you directly swap the searched element with 
first element. So that when next you search you can get it in constant time O(1) */ 

//Time complexity O(n)
int LinearSearch(int arr[],int n,int ele){
    int index=-1;
    fo(i,n){
        if(arr[i]==ele){
            index=i;
            break;
        }
    }
    return index;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,ele;
    cin>>n;
    
    int arr[n];

    fo(i,n){
        cin>>arr[i];
    }
    
    cin>>ele;
    
    int index=LinearSearch(arr,n,ele);

    if(index==-1)
        cout<<"Element not found"<<end;
    else    
        cout<<"Element found at index "<<index<<end;

    return 0;
}