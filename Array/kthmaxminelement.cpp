#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Using sort function complexity O(nlogn)*/
void findKthEle(int* arr,int n,int k){
    sort(arr,arr+n);
    cout<<"Min: "<<arr[k-1]<<", Max: "<<arr[n-k];
}

/*Find kth largest using bubble sort O(n*k)*/
void findKthLargest(int* arr,int n,int k){
    //After every iteration it pushes the largest element to its appro. position
    fo(i,k) {    //Outer loop till k
        fo(j,n){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"Kth Largest: "<<arr[n-k];
}
 
/*We can solve this problem using minheap, maxheap and quickselect*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;

    findKthEle(arr,n,k);

    return 0;
}