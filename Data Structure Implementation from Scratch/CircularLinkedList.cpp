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
    cout << "Enter Element: ";
    cin >> p->data;

    if (start == NULL)
    {
        start = p;
        start->next = start;
    }
    else
    {
        p->next = start;
        q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        q->next = p;
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
        start = p;
        start->next = start;
    }
    else
    {
        q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        q->next = p;
        p->next = start;
    }
}

void createAtGivenLocation()
{
    p = new node;
    int location;
    cout << "Enter Element: ";
    cin >> p->data;
    cout << "Enter Location: ";
    cin >> location;

    if (start == NULL)
    {
        if (location == 1)
        {
            start = p;
            start->next = start;
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
            q = start;
            while (q->next != start)
            {
                q = q->next;
            }
            q->next = p;
            start = p;
        }
        else
        {
            int count = 2;
            struct node *first;
            first = start;
            q = start->next;
            while (count < location && q != start)
            {
                count++;
                first = first->next;
                q = q->next;
            }
            if (q == start)
            {
                cout << "Location is not proper\n";
            }
            else
            {
                first->next = p;
                p->next = q;
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
    else if (start->next == start)
    {
        p = start;
        cout << "Deleted: " << p->data << "\n";
        delete (p);
        start = NULL;
    }
    else
    {
        q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        p = start;
        start = start->next;
        q->next = start;
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
    else if (start->next == start)
    {
        p = start;
        cout << "Deleted: " << p->data << "\n";
        delete (p);
        start = NULL;
    }
    else
    {
        q = start;
        while (q->next != start)
        {
            p = q;
            q = q->next;
        }
        p->next = start;
        cout << "Deleted: " << q->data << "\n";
        delete (q);
    }
}

void deleteAtGivenLocation()
{
    int location;
    cout << "Enter location: ";
    cin >> location;
    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else if (start->next == start && location == 1)
    {
        p = start;
        cout << "Deleted: " << p->data << "\n";
        delete (p);
        start = NULL;
    }
    else
    {
        if (location == 1)
        {
            q = start;
            while (q->next != start)
            {
                q = q->next;
            }
            p = start;
            start = start->next;
            q->next = start;
            cout << "Deleted: " << p->data << "\n";
            delete (p);
        }
        else
        {
            int count = 2;
            p = start;
            q = start->next;
            while (q != start && count < location)
            {
                p = p->next;
                q = q->next;
                count++;
            }
            if (q == start)
            {
                cout << "Location is not proper\n";
            }
            else
            {
                p->next = q->next;
                cout << "Deleted: " << q->data << "\n";
                delete (q);
            }
        }
    }
}

void traverse()
{
    q = start;

    if (start == NULL)
    {
        cout << "Linked list is empty\n";
    }
    else
    {
        do
        {
            cout << q->data << " ";
            q = q->next;
        } while (q != start);
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