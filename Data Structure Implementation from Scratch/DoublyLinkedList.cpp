#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *p, *q, *start = NULL;

void createAtStart()
{
    p = new node;
    cout << "Enter Element: ";
    cin >> p->data;
    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start->prev = p;
        p->prev = NULL;
        start = p;
    }
}

void createAtEnd()
{
    p = new node;
    cout << "Enter Element: ";
    cin >> p->data;
    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
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
        p->prev = q;
        p->next = NULL;
    }
}

void createAtGivenLocation()
{
    int location;
    p = new node;
    cout << "Enter Element: ";
    cin >> p->data;
    cout << "Enter Location: ";
    cin >> location;

    if (start == NULL)
    {
        if (location == 1)
        {
            p->next = NULL;
            p->prev = NULL;
            start = p;
        }
    }
    else
    {
        if (location == 1)
        {
            p->next = start;
            start->prev = p;
            p->prev = NULL;
            start = p;
        }
        else
        {
            int count = 1;
            q = start;
            while (q != NULL && count < location)
            {
                q = q->next;
                count++;
            }
            if (q == NULL)
            {
                cout << "Location is not proper\n";
            }
            else
            {
                p->prev = q->prev;
                p->prev->next = p;
                p->next = q;
                q->prev = p;
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
    else if (start->next == NULL)
    {
        p = start;
        start = NULL;
        cout << "Deleted: " << p->data << "\n";
        delete (p);
    }
    else
    {
        p = start;
        q = p->next;
        q->prev = NULL;
        start = q;
        cout << "Deleted: " << p->data << "\n";
        delete (p);
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
        delete (p);
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        p = q->prev;
        p->next = NULL;
        cout << "Deleted: " << q->data << "\n";
        delete (q);
    }
}

void deleteAtGivenLocation()
{
    int location;
    cout << "Enter Location: ";
    cin >> location;
    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else if (start->next == NULL)
    {
        if (location == 1)
        {
            p = start;
            start = NULL;
            cout << "Deleted: " << p->data << "\n";
            delete (p);
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
            p = start;
            q = p->next;
            q->prev = NULL;
            start = q;
            cout << "Deleted: " << p->data << "\n";
            delete (p);
        }
        else
        {
            int count = 1;
            p = start;
            while (p != NULL && count < location)
            {
                q = p;
                p = p->next;
                count++;
            }
            if (p == NULL)
            {
                cout << "Location is not proper\n";
            }
            else
            {
                q->next = p->next;
                if (p->next != NULL)
                {
                    p->next->prev = q;
                    cout << "Deleted: " << p->data << "\n";
                    delete (p);
                }
                else
                {
                    cout << "Deleted: " << p->data << "\n";
                    delete (p);
                }
            }
        }
    }
}

void traverse()
{
    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            cout << q->data << " ";
            q = q->next;
        }
        cout << "\n";
    }
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