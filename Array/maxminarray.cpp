#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Using sort function*/
void findMaxMin(int* arr,int n){
    sort(arr,arr+n);
    cout<<"Min: "<<arr[0]<<", Max: "<<arr[n-1];
}

/*Using pre-defined methods*/
void findMaxMin1(int* arr,int n){
    int min=*min_element(arr,arr+n);
    int max=*max_element(arr,arr+n);
    cout<<"Min: "<<min<<", Max: "<<max;
}

/*Iterative way*/
void findMaxMin2(int* arr,int n){
    int min=arr[0],max=arr[0];
    foi(i,1,n){
        if(arr[i]<min)
            min=arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    cout<<"Min: "<<min<<", Max: "<<max;
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
    
    findMaxMin2(arr,n);
    
    return 0;
}