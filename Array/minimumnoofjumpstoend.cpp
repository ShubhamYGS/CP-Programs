#include<bits/stdc++.h>
#define end '\n'
#define ll long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i,k,n) for(int i=k;i<n;i++)
using namespace std;

//Normal Approach [Complexity: O(n)]
int findMinJump(int* arr,int n){
    //When there is only one number 0 jumps are needed
    if(n==1)
        return 0;

    //If first element is 0 that means we cannot jump further
    if(arr[0]==0)
        return -1;
    //Store the maximum reach in maxReach variable    
    int maxReach=arr[0];
    //As we have some number in arr[0] that means we have already taken jump once
    int jump=1;
    //step variable will hold the value at the particular index (no. of steps we can take)
    int step=arr[0];

    foi(i,1,n){
        //Check if we reached the end of an array
        if(i==n-1)
            return jump;
        //updating maxreach at every index to get the Maximum Reach
        maxReach=max(maxReach,i+arr[i]);
        //We used a step to get the maximum reach so just do step--
        step--;
        //If we have used all the steps at arr[i] that means we left with 0 steps
        if(step==0){
            //So we have taken the jump so do increase jump by 1
            jump++;
            //Check if the current index has crossed the maxReach
            if(i>=maxReach)
                return -1;
            //update the steps as steps are now zero
            step=maxReach-i;
        }
    }
    return -1;
}

//Greedy approach [Complexity: O(n)]
int jump(int* nums, int n) {
    int previous = 0;
    int current = 0;
    int jumps = 0;
    fo(i,n) {
        if(i > previous) {
            jumps = jumps + 1;
            previous = current;
        }
        current = max(current, i + nums[i]);
    }
    return jumps;
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
    
    cout<<jump(arr,n);
    return 0;
}