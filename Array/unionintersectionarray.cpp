#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Time Complexity: O(n1+n2)

void findUnion(int arr1[],int arr2[],int n1,int n2){
    int i1=0,i2=0;

    cout<<"Union: ";
    while(i1<n1 && i1<n2){
        if(arr1[i1]<arr2[i2]){
            cout<<arr1[i1++]<<" ";
        } else if(arr1[i1]>arr2[i2]){
            cout<<arr2[i2++]<<" ";
        } else {
            cout<<arr1[i1++]<<" ";
            i2++;
        }
    }

    while(i1<n1){
        cout<<arr1[i1]<<" ";
        i1++;
    }
    while(i2<n2){
        cout<<arr2[i2]<<" ";
        i2++;
    }
}

void findIntersection(int arr1[],int arr2[],int n1,int n2){
    int i1=0,i2=0;
    
    cout<<"\nIntersection: ";
    while(i1<n1 && i2<n2){
        if(arr1[i1]<arr2[i2]){
            i1++;
        } else if(arr1[i1]>arr2[i2]){
            i2++;
        } else {
            cout<<arr1[i1++]<<" ";
            i2++;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];
    fo(i,n1){
        cin>>arr1[i];
    }
    fo(i,n2){
        cin>>arr2[i];
    }
    
    findUnion(arr1,arr2,n1,n2);
    findIntersection(arr1,arr2,n1,n2);

    return 0;
}