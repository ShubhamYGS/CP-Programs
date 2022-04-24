#include<bits/stdc++.h>
using namespace std;

//In AVL Tree height is also needed (As node insertion will be done based on height of the tree)
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    int height;
};

struct Node *root=NULL;

//To calculate the height 
int nodeHeight(struct Node *p){
    //hl=Height of left subtree
    //hr=Height of right subtree

    int hl, hr;

    //Check if there is any node on the left side of node (If present take that node's height and assign it to hl else 0)
    if(p!=NULL && p->lchild)
        hl=p->lchild->height;
    else
        hl=0;

    //Check if there is any node on the right side of node (If present take that node's height and assign it to hr else 0)
    if(p!=NULL && p->rchild)
        hr=p->rchild->height;
    else
        hr=0;

    //At the end whoever is maximum return it with +1 (As we have taken the height of child node. So adding p will make it +1)
    return hl>hr?hl+1:hr+1;
}


//Calculate the height of left and right subtree and give the difference of it as a balance factor
//Suppose if node is having 2 child on left and 1 child on right (BF=2-1=1)
int balanceFactor(struct Node *p) {
    int hl, hr;
    if(p!=NULL && p->lchild)
        hl=p->lchild->height;
    else
        hl=0;

    if(p!=NULL && p->rchild)
        hr=p->rchild->height;
    else
        hr=0;

    return hl-hr;
}

//To understand the rotations we made refer the written notes
struct Node *LLRotation(struct Node *p){
    Node *pleft=p->lchild;
    Node *pleftright=pleft->rchild;
    pleft->rchild=p;
    p->lchild=pleftright;

    p->height=nodeHeight(p);
    pleft->height=nodeHeight(pleft);

    if(root==p)
        root=pleft;

    return pleft;
}

struct Node *RRRotation(struct Node *p){
    Node *pright=p->rchild;
    Node *prightleft=pright->lchild;

    p->rchild=pright;
    pright->lchild=p;

    p->height=nodeHeight(p);
    pright->height=nodeHeight(pright);

    if(root==p)
        root=pright;

    return pright;
}

struct Node *LRRotation(struct Node *p){
    Node *pleft=p->lchild;
    Node *pleftright=pleft->rchild;

    p->lchild=pleftright->lchild;
    pleft->rchild=pleftright->rchild;
    pleftright->lchild=pleft;
    pleftright->rchild=p;

    p->height=nodeHeight(p);
    pleft->height=nodeHeight(pleft);
    pleftright->height=nodeHeight(pleftright);

    if(root==p)
        root=pleftright;

    return pleftright;
}

struct Node *RLRotation(struct Node *p){
    Node *pright=p->rchild;
    Node *prightleft=pright->lchild;

    p->rchild=prightleft->rchild;
    pright->lchild=prightleft->lchild;
    prightleft->lchild=p;
    prightleft->rchild=pright;

    p->height=nodeHeight(p);
    pright->height=nodeHeight(pright);
    prightleft->height=nodeHeight(prightleft);

    if(root==prightleft)
        root=prightleft;

    return prightleft;
}

struct Node *insertNode(struct Node *p,int ele){
    struct Node *t=NULL;
    
    //If tree is empty or Element is found insert it make height as 1
    if(p==NULL){
        t=new Node;
        t->data=ele;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }

    //Traverse according to data element
    if(ele<p->data) p->lchild=insertNode(p->lchild,ele);
    else if(ele>p->data)    p->rchild=insertNode(p->rchild,ele);

    //After inserting element calculate it's height and assign it to node.
    p->height=nodeHeight(p);

    //LL Rotation
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1){
        return LLRotation(p);
    } else if(balanceFactor(p)==-2 && balanceFactor(p->lchild)==-1){
        return RRRotation(p);
    } else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1){
        return LRRotation(p);
    } else if(balanceFactor(p)==-2 && balanceFactor(p->lchild)==1){
        return RLRotation(p);
    }
    return p;
}

struct Node *inOrderTraversal(struct Node *p){
    if(p!=NULL){
        inOrderTraversal(p->lchild);
        cout<<p->data<<" ";
        inOrderTraversal(p->rchild);
    }

    return p;
}


int main(){

    int n;
    cout<<"How many nodes you want in tree: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        //Everytime asssign the return value to root [IMP]
        //As there is a chance to have an update on root node as well
        root=insertNode(root,ele);
    }

    inOrderTraversal(root);
    
    return 0;
}