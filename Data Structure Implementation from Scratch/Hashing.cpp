#include <bits/stdc++.h>
using namespace std;

/* 
--------------First Method-------------- (Implemented)
Function: h(x)=h(x)%10
Hashing using Chaining (Array of Linked List)
Keys are: 29 15 5 20 16 8 12 73 46 35 33

0: 20
1:
2: 12
3: 33 -> 73
4:
5: 5 -> 15 -> 35
6: 16 -> 46
7:
8: 8
9: 29
*/

/*
--------------Second Method-------------- (Implemented)
Function: h(x)=(h(x)+f(i))%10 where f(i)=0,1,2,...
Hashing using Linear Probing (Insert element at next free index)
Keys are: 12 49 25 35 26 33 89
0: 89
1:
2: 12
3: 33
4:
5: 25
6: 35
7: 26
8: 
9: 49
*/

/*
--------------Third Method-------------- (Not Implemented)
Function: h(x)=(h(x)+f(i))%10 where f(i)=0^2,1^2,2^2,3^2,...
Hashing using Quadratic Probing (Insert element at next free index) [Square]
Keys are: 23 43 13 27 64
0: 
1: 
2: 
3: 23   (23+0^2)%10
4: 43   (23+1^2)%10
5: 64   (64+1^2)%10
6: 
7: 13   (13+2^2)%10
8: 27   (27+1^2)%10
9: 
*/

/*
--------------Fourth Method-------------- (Not Implemented)
Function: h1(x)=h(x)%10 (First try this function) [If space already occupied try final function]
Function: h2(x)=R-(x%R) = 7-(x%7)   [Here R is smallest natural number near to hash size (10) which is 7]
Final Function: hf(x)=(h1(x)+i*h2(x))%10 where i=0,1,2,3,...
Keys are: 5 25 15 35 95
0: 
1: 15   (5+1*(7-(15%7)))%10 => (5+1*(7-1))%10 => 1
2: 35   (5+1*(7-(35%7)))%10 => (5+1*(7-0))%10 => 2
3: 
4: 95   (5+3*(7-(95%7)))%10 => (5+3*(7-4))%10 => 4
5: 5    5%10 => 5
6: 
7:      
8: 25   (5+1*(7-(25%7)))%10 => (5+1*(7-4))%10 => 8
9: 
*/

// This function returns index where element should be inserted
int hashIndex(int ele)
{
    return ele % 10;
}

// Node of singly linked List
struct node
{
    int data;
    struct node *next;
};

// This is main hash function contains 10 indexes
struct node *start[10];

// Inserting element in sorted order in linked list
void insert(int ele)
{
    // Finding out the index
    int index = hashIndex(ele);

    // Create a new node and store the element in it
    struct node *p = new node;
    p->data = ele;

    // If hash index is empty
    if (start[index] == NULL)
    {
        start[index] = p;
        start[index]->next = NULL;
    }
    else
    {
        // Using q for simplification
        struct node *q = start[index];

        // If the data to be inserted is greater than starting hash index (15->25->45) [insert 35]
        if (p->data > q->data)
        {
            // If hash index is having only one element
            if (q->next == NULL)
            {
                q->next = p;
                p->next = NULL;
            }
            else
            {
                // Finding out the position where q->next->data os greater than element to be inserted
                while (q->next != NULL)
                {
                    if (q->next->data < p->data)
                        q = q->next;
                    else
                        break;
                }
                // If we have reached end of LL (Element is greater than all)
                if (q->next == NULL)
                {
                    q->next = p;
                    p->next = NULL;
                }
                else
                {
                    // Make adjustment to insert new element
                    p->next = q->next;
                    q->next = p;
                }
            }
        }
        else
        {
            // If starting hash index is smaller than element to be inserted (15->25->45) [insert 5]
            p->next = q;
            start[index] = p;
        }
    }
}

// Searching element in hash Linked List
void search(int key)
{
    int index = hashIndex(key);
    struct node *q = start[index];

    while (q != NULL)
    {
        if (q->data == key)
        {
            cout << "Element found";
            return;
        }
        q = q->next;
    }

    if (q == NULL)
        cout << "Element not found";
}

/*
//In Linear Probing we are checking if index is free we will insert the element.
//if it's not free then we will insert the element in next free index.
void insertUsingLinearProbing(int *H, int ele)
{
    int index = hashIndex(ele);

    //Check if index is free
    if (H[index] == 0)
    {
        H[index] = ele;
    }
    else
    {
        //If index is not free. Find the next free index
        while (H[index] != 0)
        {
            index++;
            if (index > 9)
                index = 0;
        }
        //Insert the element at next free index
        H[index] = ele;
    }
}

void searchUsingLinearProbing(int *H, int ele)
{
    int index = hashIndex(ele);
    int count = index;

    //Check if element is present at the correct index
    if (H[index] == ele)
    {
        cout << "Element found";
        return;
    }
    else
    {
        //If the element is not present at correct index
        //iterate over all the index until you found the empty index or you revisit same index which results in element not found
        index++;
        while (H[index] != 0 && count != index)
        {
            if (H[index] == ele)
            {
                cout << "Element found";
                return;
            }
            index++;
            if (index > 9)
                index = 0;
        }
    }

    //If none of the above condition satisfies element is not present
    cout << "Element not found";
}
*/

int main()
{
    //Initializing hash index with 0 (start=NULL)
    for (int i = 0; i < 10; i++)
    {
        start[i] = NULL;
    }

    int n, ele;

    cout << "How many elements you want to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        insert(ele);
    }

    int key;
    cout<<"Enter the element you want to seach: ";
    cin>>key;

    search(key);

    //Using Linear probing
    /*
    int n, ele, key;

    int H[10] = {0};

    cout << "How many elements you want to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        insertUsingLinearProbing(H, ele);
    }

    cout << "Enter the element you want to seach: ";
    cin >> key;

    searchUsingLinearProbing(H, key);*/

    return 0;
}