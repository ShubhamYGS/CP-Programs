#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;


void printSubSequenceUsingRecursion(int index,int arr[],vector<int> &ds,int n){
    if(index==n){
        for(int i=0;i<ds.size();i++){
            cout<<ds[i];
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<end;
        return;
    }

    ds.push_back(arr[index]);
    printSubSequenceUsingRecursion(index+1,arr,ds,n);
    ds.pop_back();

    printSubSequenceUsingRecursion(index+1,arr,ds,n);

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
    vector<int> ds;

    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    
    printSubSequenceUsingRecursion(0,arr,ds,n);

    return 0;
}


/*Output:
For the input [3 1 2]
{}
3
1
2
3 1
1 2
3 1
3 1 2
*/