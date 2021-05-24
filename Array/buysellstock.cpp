#include <bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)

using namespace std;

//Brute Force Approach O(n2)
void buySellStock1(int* arr,int n){
    int maxProfit=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]>maxProfit){
                maxProfit=arr[j] - arr[i];
            }
        }
    }
    
    cout << maxProfit;
}

//Optimal approach O(n)
void buySellStock2(int* arr,int n){
    int maxProfit=0;
    int minPrice=arr[0];
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,arr[i]);
        maxProfit=max(maxProfit,arr[i]-minPrice);
    }
    cout<<maxProfit;
}

int main() {
    int n;
    cin>>n;
    
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    
    buySellStock2(arr,n);
    
    return 0;
}4