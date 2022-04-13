#include <bits/stdc++.h>
using namespace std;

/*For implementing queue using linkedlist
For enqueue: create at end
For dequeue: delete at start
*/

class Queue
{
public:
    int n, rear;
    int *arr;

    Queue(int num)
    {
        n = num;
        arr = new int[n];
        rear = -1;
    }

    void enqueue() // Time Complexity: O(1)
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
            rear++;
            arr[rear] = ele;
            cout << "Enqueued: " << arr[rear] << "\n";
        }
    }

    void dequeue() // Time Complexity: O(n)
    {
        if (rear == -1)
        {
            cout << "Empty: dequeue operation can't be perfoemed\n";
        }
        else
        {
            cout << "Dequeued: " << arr[0] << "\n";
            for (int i = 0; i < rear; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }

    void traverse()
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }

    void getFront()
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Front is: " << arr[0] << "\n";
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
             << "\n4.Front"
             << "\n5.Exit\n";
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
            q.getFront();
            break;
        case 5:
            cout << "Exited Successfully\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}
