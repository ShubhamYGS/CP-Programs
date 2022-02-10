#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

void findSubsequenceSumEqualsK(int index,int k,int sum,vector<int> &ds,int arr[],int n){
    if(index==n){
        if(sum==k){
            for(int i=0;i<ds.size();i++){
                cout<<ds[i]<<" ";
            }
            cout<<end;
        }
        return;
    }

    //Include index Element
    sum+=arr[index];
    ds.push_back(arr[index]);
    findSubsequenceSumEqualsK(index+1,k,sum,ds,arr,n);

    //Don't include
    sum-=arr[index];
    ds.pop_back();
    findSubsequenceSumEqualsK(index+1,k,sum,ds,arr,n);
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
    fo(i,n){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    vector<int> ds;
    
    findSubsequenceSumEqualsK(0,k,0,ds,arr,n);
    return 0;
}