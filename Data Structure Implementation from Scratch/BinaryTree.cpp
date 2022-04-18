#include <bits/stdc++.h>
using namespace std;

/*Tree
            2
         /    \
        4       1
       / \     /
      7   10  3
     /
    6
*/

/*For Creating tree using array
Create array with +1 size as we will not store elements at 0 index
(As it will create problem in finding left and right child)
Left Child: 2*i right child: 2*i+1
*/

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

Node *root = NULL;

/* -1 as a input is considered as NULL */
void createBinaryTree()
{
    queue<Node *> q;
    Node *p, *temp;
    int ele;

    cout << "Enter root value: ";
    cin >> ele;
    root = new Node; // changes use the global root only
    root->data = ele;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << ": ";
        cin >> ele;
        if (ele != -1)
        {
            temp = new Node;
            temp->data = ele;
            temp->lchild = temp->rchild = 0;
            p->lchild = temp;
            q.push(temp);
        }

        cout << "Enter right right of " << p->data << ": ";
        cin >> ele;
        if (ele != -1)
        {
            temp = new Node;
            temp->data = ele;
            temp->lchild = temp->rchild = 0;
            p->rchild = temp;
            q.push(temp);
        }
    }
}

void preOrderTraversal(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOrderTraversal(p->lchild);
        preOrderTraversal(p->rchild);
    }
}

void inOrderTraversal(Node *p)
{
    if (p != NULL)
    {
        inOrderTraversal(p->lchild);
        cout << p->data << " ";
        inOrderTraversal(p->rchild);
    }
}

void postOrderTraversal(Node *p)
{
    if (p != NULL)
    {
        postOrderTraversal(p->lchild);
        postOrderTraversal(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{

    createBinaryTree();
    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << "\nInOrder Traversal: ";
    inOrderTraversal(root);
    cout << "\nPostOrder Traversal: ";
    postOrderTraversal(root);

    return 0;
}