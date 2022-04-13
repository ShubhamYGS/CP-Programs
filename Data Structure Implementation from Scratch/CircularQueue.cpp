#include <bits/stdc++.h>
using namespace std;

/*we can’t insert the new element in the queue even if it has an empty space in beginning.
This drawback can be solved using circular queue.
*/

class CircularQueue
{
public:
    int n, front, rear;
    int *arr;

    CircularQueue(int num)
    {
        n = num;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue()      // Time Complexity: O(n)
    {
        if (front == (rear + 1) % n)
        {
            cout << "Full: enqueue operation can't be perfoemed\n";
        }
        else
        {
            int ele;
            cout << "Enter Element: ";
            cin >> ele;
            if (front == -1)
                front = 0;
            rear = (rear + 1) % n;
            arr[rear] = ele;
            cout << "Enqueued: " << arr[rear] << "\n";
        }
    }

    void dequeue()      // Time Complexity: O(n)
    {
        if (front == -1)
        {
            cout << "Empty: dequeue operation can't be perfoemed\n";
        }
        else
        {
            cout << "Dequeued: " << arr[front] << "\n";
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % n;
            }
        }
    }

    void getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Front is: " << arr[front] << "\n";
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
            if (front <= rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            else
            {
                for (int i = front; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
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
    CircularQueue q(n);

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
