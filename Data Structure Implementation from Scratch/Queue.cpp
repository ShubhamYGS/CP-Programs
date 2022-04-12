#include <bits/stdc++.h>
using namespace std;

/*For implementing queue using linkedlist
For enqueue: create at end
For dequeue: delete at start
*/

class Queue
{
public:
    int n, front, rear;
    int *arr;

    Queue(int num)
    {
        n = num;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue()
    {
        if (rear == n - 1)
        {
            cout << "Full: enqueue operation can't be perfoemed\n";
        }
        else
        {
            int ele;
            cout << "Enter Element: ";
            cin >> ele;
            if (front == -1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            arr[rear] = ele;
            cout << "Enqueued: " << arr[rear] << "\n";
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Empty: dequeue operation can't be perfoemed\n";
        }
        else
        {
            cout << "Dequeued: " << arr[front] << "\n";
            front++;
            // If we are at the end of queue
            if (front > rear)
            {
                front = -1;
                rear = -1;
            }
        }
    }

    void traverse()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int choice;
    int n;
    cout << "How many elements you want in queue: ";
    cin >> n;
    Queue q(n);
    do
    {
        cout << "1.Enqueue"
             << "\n2.Dequeue"
             << "\n3.Traverse"
             << "\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.traverse();
            break;
        case 4:
            cout << "Exited Successfully\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}
