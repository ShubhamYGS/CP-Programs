#include <bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)

using namespace std;

struct interval{
    int start;
    int end;
};

bool compareStartInterval(interval i1,interval i2){
    return (i1.start<i2.start);
}

//Array of structure Space- O(1), Time- O(nlogn) [for sorting merging takes linear time]
int mergerOverlapInterval(struct interval *arr,int n){
    int count=0;
    sort(arr,arr+n,compareStartInterval);
    
    foi(i,1,n){
       if(arr[count].end>=arr[i].start){
           arr[count].end=max(arr[count].end,arr[i].end);
       } else {
           count++;
           arr[count]=arr[i];
       }
    }
    return count;
}

//stack of struct Space- O(1), Time- O(nlogn) [for sorting merging takes linear time]
void mergeOverlapInterval2(struct interval *arr,int n){
    
    sort(arr,arr+n,compareStartInterval);
    stack<interval> st;
    st.push(arr[0]);
    
    foi(i,1,n){
       interval top = st.top();
       
       if(top.end>=arr[i].start){
            top.end=max(top.end,arr[i].end);
       } else {
           st.push(arr[i]);
       }
    }
    
    while(!st.empty()){
        interval i = st.top();
        cout<<i.start<<","<<i.end<<" ";
        st.pop();
    }
}
int main() {
    int n,count;
    cin>>n;
    struct interval arr[n];
    fo(i,n){
        int num1,num2;
        cin>>num1>>num2;
        arr[i].start=num1;
        arr[i].end=num2;
    }
    
    mergeOverlapInterval2(arr,n);
    
    // count=mergerOverlapInterval(arr,n);
    
    // for(int i=0;i<=count;i++){
    //     cout<<arr[i].start<<","<<arr[i].end<<" ";
    // }
    return 0;
}