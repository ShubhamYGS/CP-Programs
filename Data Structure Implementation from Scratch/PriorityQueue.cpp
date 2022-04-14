#include <bits/stdc++.h>
using namespace std;

/*Priority Queue:
Each item in the priority queue is associated with a priority.
The item with the highest priority is the first item to be removed from the queue.

It can be implemented in three ways:
1) Using array/linked list
2) Using heap (Most efficient way)
3) Using STL
*/

class PriorityQueueUsingArray
{
public:
    int n, rear;
    int *arr;

    PriorityQueueUsingArray(int num)
    {
        n = num;
        arr = new int[n];
        rear = -1;
    }

    void enqueue() // Time Complexity: O(n)
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
            if (rear == -1)
            {
                rear++;
                arr[rear] = ele;
            }
            else
            {
                int temp = ele;
                for (int i = 0; i <= rear; i++)
                {
                    if (arr[i] > ele)
                    {
                        swap(temp, arr[i]);
                    }
                }
                arr[++rear] = temp;
            }
            cout << "Enqueued: " << ele << "\n";
        }
    }

    void dequeue() // Time Complexity: O(1)
    {
        if (rear == -1)
        {
            cout << "Empty: dequeue operation can't be perfoemed\n";
        }
        else
        {
            cout << "Dequeued: " << arr[rear] << "\n";
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

    void getTop()
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Top is: " << arr[rear] << "\n";
        }
    }
};

int main()
{
    int choice;
    int n;
    cout << "How many elements you want in queue: ";
    cin >> n;
    PriorityQueueUsingArray q(n);
    do
    {
        cout << "1.Enqueue"
             << "\n2.Dequeue"
             << "\n3.Traverse"
             << "\n4.Top"
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
            q.getTop();
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
