#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

/*Approach 1*/
void movePosRightArr(int* arr,int n){
    int low=0,high=n-1;
    bool flag=false;
    while(low<=high){
        if(arr[low]>0){
            while(arr[high]>0){
                high--;
                if(high<=low)  {
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
            swap(arr[low],arr[high]);
        }
        low++;
    }
}

/*Approach 2*/
void movePosRightArr2(int* arr,int n){
    int j=0;
    fo(i,n){
        if(arr[i]<0){
            if(i!=j)
                swap(arr[i],arr[j]);
            j++;
        }
    }
}

/*Approach 3: Using two pointer (Sequence may change)*/
void movePosRightArr3(int* arr,int n){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]>0 && arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        } else {
            if(arr[i]<0)
               i++;
            if(arr[j]>0)
                j--;
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

    movePosRightArr3(arr,n);

    fo(i,n){
        cout<<arr[i]<<" ";
    }
    return 0;
}