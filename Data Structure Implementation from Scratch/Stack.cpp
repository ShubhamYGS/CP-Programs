#include<bits/stdc++.h>
using namespace std;

/*For implementing stack using linkedlist
For Push: create at start
For Pop: delete at start
*/

class Stack
{
public:
    int n;
    int *arr;
    int top = -1;

    Stack(int num)
    {
        n = num;
        arr = new int[n];
    }

    void pushElement()
    {
        if (top == n - 1)
        {
            cout << "Stack is overflow\n";
        }
        else
        {
            top++;
            cout << "Enter Element: ";
            cin >> arr[top];
        }
    }

    void popElement()
    {
        if (top == -1)
        {
            cout << "Stack is underflow\n";
        }
        else
        {
            cout << "Deleted: " << arr[top] << "\n";
            top--;
        }
    }

    void traverse()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }

    int giveTopElement()
    {
        return arr[top];
    }
};

int main()
{
    int choice;
    int n;
    cout << "How many elements you want in stack: ";
    cin >> n;
    Stack s(n);
    do
    {
        cout << "1.Push"
             << "\n2.Pop"
             << "\n3.Top"
             << "\n4.Traverse"
             << "\n5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.pushElement();
            break;
        case 2:
            s.popElement();
            break;
        case 3:
            cout << "Top is: " << s.giveTopElement() << "\n";
            break;
        case 4:
            s.traverse();
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
