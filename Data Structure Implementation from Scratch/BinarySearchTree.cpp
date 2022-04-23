#include <bits/stdc++.h>
using namespace std;

/*Tree
No. of Nodes: 9
Key: 9 15 5 20 16 8 12 3 6

            9
         /    \
        5       15
       / \     /  \
      3   8   12   20
         /        /
        6        16
*/

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

Node *root = NULL;

/*Iterative Approach TIme Complexity: O(height)*/
void insertNodeInTree(int ele)
{
    // Temp is temporary node
    // Current and parent are two pointers. Where parent is always one step behind current pointer.
    struct Node *temp;
    struct Node *current = root;
    struct Node *parent;

    // If root itself is NULL
    if (root == NULL)
    {
        root = new Node;
        root->data = ele;
        root->lchild = root->rchild = NULL;
        return;
    }

    // If root is not NULL, move both pointers until current becomes NULL. At the end current will be NULL and parent will be pointing at the correct node.
    while (current != NULL)
    {
        parent = current;
        if (ele < current->data)
            current = current->lchild;
        else if (ele > current->data)
            current = current->rchild;
    }

    // Create a temporary node with element data filled
    temp = new Node;
    temp->data = ele;
    temp->lchild = temp->rchild = NULL;

    // check appropriate position and insert the element
    if (ele < parent->data)
        parent->lchild = temp;
    else
        parent->rchild = temp;
}

/*Recursive Approach*/
struct Node *insertNodeInTreeRecursively(Node *p, int ele)
{
    struct Node *temp;

    // Check if tree is empty
    if (p == NULL)
    {
        temp = new Node;
        temp->data = ele;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    // Traverse according to data element
    if (ele < p->data)
        p->lchild = insertNodeInTreeRecursively(p->lchild, ele);
    else if (ele > p->data)
        p->rchild = insertNodeInTreeRecursively(p->rchild, ele);

    return p;
}

// We will be using simple binary search here to seach element. If element not found then P will be pointin at NULL.
bool searchElement(int key)
{
    struct Node *p = root;

    while (p != NULL)
    {
        if (p->data == key)
            return true;
        else if (key < p->data)
            p = p->lchild;
        else if (key > p->data)
            p = p->rchild;
    }

    return false;
}

int findMaxPredecessor(Node *p)
{
    while (p->rchild != NULL)
    {
        p = p->rchild;
    }

    return p->data;
}

// Delete a node from Binary Seach Tree (Recursive Way)
Node *deleteNode(struct Node *root, int ele)
{
    // base case (If tree is empty)
    if (root == NULL)
    {
        return NULL;
    }

    // if and else if condition helps in finding the element we wanted to delete
    if (ele < root->data)
        root->lchild = deleteNode(root->lchild, ele);
    else if (ele > root->data)
        root->rchild = deleteNode(root->rchild, ele);
    else
    {
        if (root->rchild != NULL && root->lchild != NULL)
        {
            // Find the MaxPredecessor and make it as left child of root
            int nextEle = findMaxPredecessor(root->lchild);
            root->data = nextEle;
            root->lchild = deleteNode(root->lchild, nextEle);
        }
        else if (root->rchild != NULL)
        {
            // When only right element is present for the node to be deleted
            return root->rchild;
        }
        else if (root->lchild != NULL)
        {
            // When only left element is present for the node to be deleted
            return root->lchild;
        }
        else
        {
            return NULL;
        }
    }

    return root;
}

void deleteNodeIterative(Node *root, int ele)
{
    Node *child = root;
    Node *parent = NULL;

    // Searching for the element
    while (child != NULL && child->data != ele)
    {
        parent = child;
        if (ele < child->data)
            child = child->lchild;
        else
            child = child->rchild;
    }

    // If tree is empty or element is not found will return NULL
    if (child == NULL)
        return;

    // Deleting node
    if (child->rchild != NULL && child->lchild != NULL)
    {
        // If the node you want to delete is having both left and right child
        // Create a temporary node to hold the element you want to delete i.e., child node
        // Move child node to child's left and find inorder precessor and keep parent running 1 node behind the child
        Node *temp = child;
        parent = child;
        child = child->lchild;
        while (child->rchild != NULL)
        {
            parent = child;
            child = child->rchild;
        }
        // Place the data of child node into parent node
        swap(temp->data, child->data);
        // If child is also having any child then make it as child of parent
        if (parent->rchild == child)
            parent->rchild = child->lchild;
        else
            parent->lchild = child->lchild;
    }
    else
    {
        // If node has less than 2 child (0,1,2)
        // Initially childofchild is initialized to NULL (So if child is not having any child so it can be initilized to NULL)
        // childofchild will be pointing to child node of child if there is any
        Node *childOfChild = NULL;
        if (child->lchild != NULL)
            childOfChild = child->lchild;
        else if (child->rchild != NULL)
            childOfChild = child->rchild;

        // If the node we are deleting is root node with 1 or 0 childs
        if (parent == NULL)
            root = childOfChild;
        else if (parent->lchild == child) // Node to delete is left child
            parent->lchild = childOfChild;
        else
            parent->rchild = childOfChild; // Node to delete is right child
    }

    // Delete the child node
    delete child;
}

// Generating Binary Seach Tree from PreOrder Traversal
// For generating it from post order just visit the element in reversr ordeer (n-1 to 0)
void generateBSTFromPreOrderTraversal(int arr[], int n)
{
    // Creating root node
    int i = 0;
    root = new Node;
    root->data = arr[i++];
    root->lchild = root->rchild = NULL;

    // Stack is used to store the address of last node from which left node is created
    stack<Node *> st;
    Node *temp;
    Node *p = root;

    while (i < n)
    {
        // Left child case
        // Create new node and make it as a left child of parent node and insert parent node in stack. make parent pointing to new node now.
        if (arr[i] < p->data)
        {
            temp = new Node;
            temp->data = arr[i++];
            temp->lchild = temp->rchild = NULL;
            p->lchild = temp;
            st.push(p);
            p = temp;
        }
        else
        {
            // Right child case
            // Create new node and make it as right child of parent node. make parent pointing to new node now.
            // In case of stack is empty choose the maximum infinite value (As in this case we will be creating tree on right side only)
            if (arr[i] > p->data && arr[i] < (st.empty() ? INT32_MAX : st.top()->data))
            {
                temp = new Node;
                temp->data = arr[i++];
                temp->lchild = temp->rchild = NULL;
                p->rchild = temp;
                p = temp;
            }
            else
            {
                // If element is greater than parent node data and stack top. So just make parent pointing to stack top. As element will be inserted on right side of the tree.
                p = st.top();
                st.pop();
            }
        }
    }
}

/* *Predecessor: The node lies behind root node while traversing
    Successor: The node lies ahead root node while traversing
    To find Predecessor: First move left side and then keep moving right side until you found the element.
   To find Successor: First move right side and then keep moving left side until you found the element.
*/
void findInOrderPredecessorSuccessor()
{
    Node *p = root;
    Node *s = root;

    p = p->lchild;
    s = s->rchild;

    while (p->rchild != NULL)
    {
        p = p->rchild;
    }

    while (s->lchild != NULL)
    {
        s = s->lchild;
    }

    cout << "Predecessor is: " << p->data << ", Successor is: " << s->data << "\n";
}

//Pre-order Traversal
void preOrderTraversal(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOrderTraversal(p->lchild);
        preOrderTraversal(p->rchild);
    }
}

//Im-order Traversal
void inOrderTraversal(Node *p)
{
    if (p != NULL)
    {
        inOrderTraversal(p->lchild);
        cout << p->data << " ";
        inOrderTraversal(p->rchild);
    }
}

//Post-order Traversal
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
    int n, ele, key, deleteEle;
    cout << "How many nodes you want in tree: ";
    cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> ele;
    //     //Only when inserting node recursively you have to copy the result of first insertion in root
    //     // if(i==0)
    //     //     root=insertNodeInTreeRecursively(root,ele);
    //     // else
    //     //     insertNodeInTreeRecursively(root,ele);

    //     insertNodeInTree(ele);
    // }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    generateBSTFromPreOrderTraversal(arr, n);

    cout << "Inorder Traversal of the Tree: ";
    inOrderTraversal(root);

    // cout<<"\nEnter the element you want to search: ";
    // cin>>key;
    // if(searchElement(key))
    //     cout<<"Element found\n";
    // else
    //     cout<<"Element not found\n";

    // findInOrderPredecessorSuccessor();

    // cout<<"Which element you would like to delete: ";
    // cin>>deleteEle;
    // deleteNodeIterative(root,deleteEle);
    // inOrderTraversal(root);

    return 0;
}