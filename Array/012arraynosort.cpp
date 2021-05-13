#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Method 1: USing low, mid, high*/
void sortEle(int* arr,int n){
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        switch(arr[mid]){
            case 0: 
                swap(arr[low],arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high]);
                high--;
                break;
        }
    }
}

/*Method 2: Using count of each number*/
void sortEleC(int* arr,int n){
    int cnt0=0,cnt1=0,cnt2=0;

    fo(i,n){
        switch(arr[i]){
            case 0:
                cnt0++;
                break;
            case 1:
                cnt1++;
                break;
            case 2:
                cnt2++;
                break;
        }
    }
    int i=0;
    while(cnt0>0){
        arr[i++]=0;
        cnt0--;
    }
    while(cnt1>0){
        arr[i++]=1;
        cnt1--;
    }
    while(cnt2>0){
        arr[i++]=2;
        cnt2--;
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

    sortEleC(arr,n);

    fo(i,n){
        cout<<arr[i]<<" ";
    }
    return 0;
}