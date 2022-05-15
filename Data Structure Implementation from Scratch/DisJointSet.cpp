#include <bits/stdc++.h>
using namespace std;

/*Union operation can be optimised using Rank method
  find operation can be optimised using Path compression method
  Operation     bruteforce        optimised
    find            O(n)           O(logn)
    union           O(n)           O(logn)
  */

/* We will making a disjoint set like below
          5          3     0    7
         / \        /
        1   6      4 
       /          / 
      2          8
                / 
               9     

    So, here if I try to attach 8 to 3 it will form a cycle.         
*/

class disJointSet
{
public:
    int n;
    int *parent;
    // Parent array to store parent of all the vertex in a set

    disJointSet(int noOfVertex)
    {
        n = noOfVertex;
        parent = new int[n];
    }

    // Everyone is parent of themselves (eg., 2 is parent of 2, 4 is a parent of 4)
    void makeParentOfSelf()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
        }
    }

    // If parent[v]==-1 that means we have found parent of that vertex
    // (8 -> 4 -> 1) is having parent array as (for 8 parent is : 4, For 4 parent is: 1, For 1 parent is: -1 (self))
    // So the ultimate parent of 8 is 1 as it's value is -1
    int findParent(int v)
    {
        if (parent[v] == -1)
            return v;
        return findParent(parent[v]);
    }

    // This function used to union two different sets x & y
    void unionSet(int x, int y)
    {
        // If both x and y are having same parent then it is already in set
        // If you connect it may create a cycle
        if (findParent(x) == findParent(y))
        {
            cout << "Cycle Detected: Union not possible\n";
            return;
        }
        else
        {
            // Else if they are in different set
            // Suppose there is already one set with 4->3 (3 is parent) & we are adding 8,4
            // So parent(8)=8 we have to add to y which is 4 in this case. Set becomes(8->4->3)
            parent[findParent(x)] = y;
        }
    }

    // Printing all the parents to know the attachments
    void printSet()
    {
        cout << "Set: ";
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
        cout << "\n";
    }
};

class disJointSetOptimised
{
public:
    int n;
    int *parent;
    int *rank;

    // Parent to maintain the parent node of a vertex
    // Rank will maintain the rank of each node (4->3->1). If parent is 1 then it's rank is 2 (height/edges)

    disJointSetOptimised(int noOfVertices)
    {
        n = noOfVertices;
        parent = new int[n];
        rank = new int[n];
    }

    // Everyone is parent of themselves
    // Make rank of every vertex 0 as every vertex is separate set
    void makeParentOfSelf()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }

    // Improving findParent function using Path Compression
    // It speeds up the data structure by compressing the height of the trees.
    // It can be achieved by inserting a small caching mechanism into the Find operation.
    // In 3->2-1 ,Suppose I have found that parent of 3 is 1 so, instead of traversing from 3 to 2 to 1 will directly make 1 as a parent of 3 after first pass.
    int findParentUsingPC(int v)
    {
        if (parent[v] == -1)
            return v;
        return parent[v] = findParentUsingPC(parent[v]); // This line saves parent (Caching mechanism)
    }

    void unionUsingRank(int x, int y)
    {
        int xParent = findParentUsingPC(x);
        int yParent = findParentUsingPC(y);

        // If both vertex are having same parent then it may form a cycle. As both vertex comes under same set.
        if (xParent == yParent)
        {
            cout << "Cycle Detected: Union not possible\n";
        }
        else
        {
            // If two vertex are having different sets
            if (rank[xParent] > rank[yParent])
            {
                parent[yParent] = xParent;
            }
            else
            {
                // The else part will execute when left set is equal to the right set or when we are adding the set for the first time
                // eg., 4->3 (3 is having rank 1), 6->5 (5 is having rank 1). So here will attach 3 to 5 and increase the rank of 5 as now subset 3 comes under 5.

                // Second part when first set is 4->3 second set is 7->6->5. Here set 2 is having more rank than set 1.
                // As per the rule attach small subtree to bigger. 3 will be attahced to 5 and as we are adding small subtree to large subtree height remain same. So no change in rank.
                parent[xParent] = yParent;
                if (rank[xParent] == rank[yParent])
                    rank[yParent]++;
            }
        }
    }

    // Printing all the parents to know the attachments
    void printSet()
    {
        cout << "Set: ";
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int n = 10;
    // cout << "How many element you want in a whole set: ";
    // cin >> n;

    disJointSet d(n);

    d.makeParentOfSelf();

    d.unionSet(2, 1);
    d.printSet();
    d.unionSet(4, 3);
    d.printSet();
    d.unionSet(8, 4);
    d.printSet();
    d.unionSet(9, 8);
    d.printSet();
    d.unionSet(6, 5);
    d.printSet();
    d.unionSet(1,5);
    d.printSet();
    d.unionSet(8,3);      //This will create a cycle

    // //Check parents of two node [n=5]
    // d.unionSet(0,2);
    // d.unionSet(4,2);
    // d.unionSet(3,1);

    // if(d.findParent(0) == d.findParent(4))
    //     cout<<"Parents are same\n";
    // else
    //     cout<<"Parents are different\n";
    // if(d.findParent(1) == d.findParent(0))
    //     cout<<"Parents are same\n";
    // else
    //     cout<<"Parents are different\n";

    return 0;
}