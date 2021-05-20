#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Brute force approach (O(n2))
int findDuplicate(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){ 
                return arr[i];
            }
        }
    }
    return -1;
}

//Using sort O(nlogn)
int findDuplicateUsingSort(int* arr,int n){
    sort(arr,arr+n);
    fo(i,n-1){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

//Using absolute method (It won't work on 0)
int findDuplicateUsingTwoP(int* arr,int n){
    fo(i,n){
        if(arr[abs(arr[i])]>=0){
            arr[abs(arr[i])]=-arr[abs(arr[i])];
        } else {
            return abs(arr[i]);
        }
    }
    return -1;
}

//Copied from GFG
void printDuplicates(int arr[], int n)
{
    int i;
 
    //used to check if repeated element found or not
    int fl = 0;
    fo(i,n){
 
        // Check if current element is repeating or not. If it is repeating then value will be greater than or equal to n.
        if (arr[arr[i] % n] >= n) {
 
            // Check if it is first
            // repetition or not. If it is
            // first repetition then value
            // at index arr[i] is less than
            // 2*n. Print arr[i] if it is
            // first repetition.
            if (arr[arr[i] % n] < 2 * n) {
                cout << arr[i] % n << " ";
                fl = 1;
            }
        }
 
        // Add n to index arr[i] to mark
        // presence of arr[i] or to
        // mark repetition of arr[i].
        arr[arr[i] % n] += n;
    }
 
    // If flag variable is not set
    // then no repeating element is
    // found. So print -1.
    if (!fl)
        cout << "-1";
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

    // cout<<findDuplicateUsingTwoP(arr,n);
    printDuplicates(arr,n);
    return 0;
}