#include <bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;

void printArray(int* arr,int n){
    fo(i,n){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

//Merging the two sortes arrays with extra space- O(n), Time- O(nlogn2)+O(n)+O(n)
void mergeSortedArrayExtra(int* arr1,int* arr2,int n1,int n2){
    int len=n1+n2;
    int mergedArray[len];
    int ma = max(n1,n2),count=0;
    for(int i=0;i<ma;i++){
        if(i<n1){
            mergedArray[count++]=arr1[i];
        }
        if(i<n2){
            mergedArray[count++]=arr2[i];
        }
    }
    sort(mergedArray,mergedArray+len);
    
    fo(i,ma){
        if(i<n1){
            arr1[i]=mergedArray[i];
        } 
        if(n1+i<len){
            arr2[i]=mergedArray[n1+i];
        }
    }
}

//Time- O(n*m) Space- O(1)
void mergeSortedArray(int* arr1,int* arr2,int n1,int n2){
    int low1=0,low2=0;
    
    while(low1<n1 and low2<n2){
        if(arr1[low1]>arr2[low2]){
            swap(arr1[low1],arr2[low2]);
            sort(arr2,arr2+n2);
        }
        low1++;
    }
}

//Merge using GAP method Time- O(nlogn) Space- O(1)
void mergeSortedArrayGap(int* arr1,int* arr2,int n1,int n2){
    int len=n1+n2;
    int gap=(len/2)+(len%2);
    int tempGap=gap;
    int i=0,count=0;
    while(1){
        if(tempGap>=len){
            gap=(gap/2)+(gap%2);
            if(count==1)    break;
            if(gap<=1)  count++;
            tempGap=gap;
            i=0;
        } else {
            if(tempGap<n1){
                if(i<n1){
                    if(arr1[i]>arr1[tempGap]){
                        swap(arr1[i],arr1[tempGap]);
                    }
                } else {
                    if(arr2[i-n1]>arr1[tempGap]){
                        swap(arr2[i-n1],arr1[tempGap]);
                    }
                }
                
            } else{
                if(i<n1){
                    if(arr1[i]>arr2[tempGap-n1]){
                        swap(arr1[i],arr2[tempGap-n1]);
                    }
                } else {
                    if(arr2[i-n1]>arr2[tempGap-n1]){
                        swap(arr2[i-n1],arr2[tempGap-n1]);
                    }
                }
            }
            i++;
            tempGap++;   
        }
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];
    
    fo(i,n1){
        cin>>arr1[i];
    }
    fo(i,n2){
        cin>>arr2[i];
    }
    
    mergeSortedArrayGap(arr1,arr2,n1,n2);
    
    printArray(arr1,n1);
    printArray(arr2,n2);
}