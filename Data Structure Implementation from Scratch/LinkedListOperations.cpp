#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL, *start1=NULL, *start2=NULL;
struct node *p, *q;

//First linked list
void createAtEnd(int ele)
{
    p = new node;
    p -> data = ele;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}

//Second Linked List
void createAtEnd1(int ele)
{
    p = new node;
    p -> data = ele;
    if (start1 == NULL)
    {
        p->next = NULL;
        start1 = p;
    }
    else
    {
        q = start1;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}

void traverse()
{
    q = start2;
    if (start2 == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        while (q != NULL)
        {
            cout << q->data << " ";
            q = q->next;
        }
    }
    cout << "\n";
}


/*Linked List Operations start here*/

void insertElementInSortedArray(int element){
    struct node *ele=new node;
    ele->data=element;
    p=start;
    
    while(p!=NULL and p->data < ele->data){
        q=p;
        p=p->next;
    }

    if(p==NULL){
        createAtEnd(element);
    }else {
        q->next=ele;
        ele->next=p;
    }
}

bool checkIfLinkListIsSorted(){
    p=start;

    while(p->next!=NULL){
        if(p->data > (p->next)->data)
            return false;
        p=p->next;
    }

    return true;
}

void removeDuplicateNoFromSortedList(){
    q=start;
    while(q!=NULL){
        p=q;
        q=q->next;
        if(p->data == q->data){
            p->next=q->next;
            delete(q);
            q=p->next;
        }
    }
}

//1. Copy all elements of LL in vetcor. Reverse iterate the vector and again copy elements in linked list.
void reverseLinkedList1(){
    vector<int> arr;
    
    q=start;

    while(q!=NULL){
        arr.push_back(q->data);
        q=q->next;
    }
    
    q=start;
    for(int i=arr.size()-1;i>=0;i--){
        q->data=arr[i];
        q=q->next;
    }
}

//2. Reverse the links (Recommended Way) [Sliding pointers]
void reverseLinkedList2(){
    p=start;    
    q=NULL;
    struct node *r=NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        r=q->next;
    }
}

//3.Using recursion with two pointers
void reverseLinkedList3(struct node *q,struct node *p){
    if(p!=NULL){
        reverseLinkedList3(p,p->next);
        p->next=q;
    } else {
        start=q;
    }
}

//Traverse first linked list till last element, attach last element's next element to start of second
void concatenateTwoLinkedList(){
    //p1 and start1 are the points of second LL
    p=start;
    q=start1;

    while(p->next!=NULL){
        p=p->next;
    }

    p->next=q;
}

void mergeTwoSortedLinkedList(){
    struct node *r=NULL;
    p=start;
    q=start1;
    if(p->data<q->data){
        start2=r=p;
        p=p->next;
    } else {
        start2=r=q;
        q=q->next;
    }
    start2->next=NULL;
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            r->next=p;
            r=p;
            p=p->next;
            r->next=NULL;
        } else {
            r->next=q;
            r=q;
            q=q->next;
            r->next=NULL;
        }
    }
    if(q!=NULL)
        r->next=p;
    if(p!=NULL)
        r->next=q;
}

bool findLoopInLinkedList(){
    struct node *slow=start,*fast=start;
        
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow)
           return true;
    }
        
    return false;

}

void findMiddleOfLinkList(){
    struct node *slow=start,*fast=start;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }

    cout<<slow->data;
}

//We have to a find point where both linked lists have same element starts.
//Will store all elements in stack so that we can visit them in reverse order.
//Eg. LL1: 1 2 3 4 5, LL2: 7 8 9 4 5 [Here, from fourth points LL having same element] 
void findIntersectionPointOfTwoLinkedList(){
    stack<struct node*> s1,s2;
    struct node *topElement=NULL;
    p=start;
    q=start1;

    while(p!=NULL){
        s1.push(p);
        p=p->next;
    }

    while(q!=NULL){
        s2.push(q);
        q=q->next;
    }

    while(!s2.empty() && !s1.empty()){
        if(s1.top()->data==s2.top()->data){
            topElement=s1.top();
            s1.pop();
            s2.pop();
        } else {
            break;
        }
    }

    cout<<topElement->data;
}

int main()
{
    int arr[5]={3,5,7,8,9};

    for(int i=0;i<5;i++){
        createAtEnd(arr[i]);
    }

    int arr1[5]={1,2,7,8,9};

    for(int i=0;i<5;i++){
        createAtEnd1(arr1[i]);
    }

    //insertElementInSortedArray(4);

    // if(checkIfLinkListIsSorted())
    //     cout<<"Sorted\n";
    // else
    //     cout<<"Not Sorted\n";

    //removeDuplicateNoFromSortedList();

    // reverseLinkedList3(NULL,start);

    // concatenateTwoLinkedList();

    // mergeTwoSortedLinkedList();

    // if(findLoopInLinkedList)
    //     cout<<"Loop found\n";
    // else
    //     cout<<"No Loop found\n";

    //findMiddleOfLinkList();

    // findIntersectionPointOfTwoLinkedList();

    // traverse();

    return 0;
}
