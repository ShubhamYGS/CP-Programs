#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *p, *q;

void createAtStart()
{
    p = new node;
    cout << "Enter the element: ";
    cin >> p->data;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start = p;
    }
}

void createAtEnd()
{
    p = new node;
    cout << "Enter the element: ";
    cin >> p->data;
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

void createAtGivenLocation()
{
    p = new node;
    int location;
    cout << "Enter the element: ";
    cin >> p->data;
    cout << "Enter the location: ";
    cin >> location;

    if (start == NULL)
    {
        if (location == 1)
        {
            p->next = NULL;
            start = p;
        }
        else
        {
            cout << "Location is not proper\n";
        }
    }
    else
    {
        if (location == 1)
        {
            p->next = start;
            start = p;
        }
        else
        {
            int count = 2;
            q = start;
            while (q != NULL && count != location)
            {
                q = q->next;
                count++;
            }
            if (q != NULL)
            {
                p->next = q->next;
                q->next = p;
            }
            else
            {
                cout << "Location is not proper\n";
                delete (p);
            }
        }
    }
}

void deleteAtStart()
{
    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        q = start;
        start = start->next;
        cout << "Deleted: " << q->data << "\n";
        delete (q);
    }
}

void deleteAtEnd()
{
    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else if (start->next == NULL)
    {
        p = start;
        start = NULL;
        cout << "Deleted: " << p->data << "\n";
        free(p);
    }
    else
    {
        q = start->next;
        p = start;
        while (q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        cout << "Deleted: " << q->data << "\n";
        delete (q);
    }
}

void deleteAtGivenLocation()
{
    int location;
    cout << "Enter the location: ";
    cin >> location;

    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        if (location == 1)
        {
            q = start;
            start = start->next;
            cout << "Deleted: " << q->data << "\n";
            delete (q);
        }
        else
        {
            int count = 1;
            p = start;
            while (count < location && p != NULL)
            {
                q = p;
                p = p->next;
                count++;
            }
            if (p != NULL)
            {
                q->next = p->next;
                cout << "Deleted: " << p->data << "\n";
                delete (p);
            }
            else
            {
                cout << "Location is not proper\n";
            }
        }
    }
}

void traverse()
{
    q = start;
    if (start == NULL)
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

//Recursive implementation of traverse
void recursiveTraverse(struct node *q)
{
    if (q == NULL)
    {
        cout << "\n";
        return;
    }
    cout << q->data << " ";
    recursiveTraverse(q->next);
}

int main()
{
    int choice;

    do
    {
        cout << "1.Create at Start"
             << "\n2.Create at End"
             << "\n3.Create at given location"
             << "\n4.Delete at Start"
             << "\n5.Delete at End"
             << "\n6.Delete at given location"
             << "\n7.Traverse"
             << "\n8.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createAtStart();
            break;
        case 2:
            createAtEnd();
            break;
        case 3:
            createAtGivenLocation();
            break;
        case 4:
            deleteAtStart();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtGivenLocation();
            break;
        case 7:
            traverse();
            break;
        case 8:
            cout << "Exited Successfully\n";
            break;
        default:
            cout << "Invalid Choice";
        }
    } while (choice != 8);

    return 0;
}
