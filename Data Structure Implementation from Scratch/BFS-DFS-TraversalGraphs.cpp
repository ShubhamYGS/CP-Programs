#include<bits/stdc++.h>
using namespace std;

/*Graph is

    1----2
    | \  |
    |   \|     
    4----3
        \  /
        5
        / \
        6   7
*/

/*BFS Traversal: (Using queue data structure to implement)
1. Take starting vertex as 1 (We can take any vertex as starting vertex)
2. Add 1 to the queue and make it visited
3. store it in explore variable and pop it from queue and print it
4. Explore all the neighbors of 1 and add to queue and make them visited
5. Now again follow the same process (from 3 to 4)

So, in bfs every time we are taking one vertex and exploring it fully.
*/

/*DFS Traversal (Using stack data structure to implement)
1. Take starting vertex as 1 make it visited and emplace it into stack
2. Start explooring 2 if you found any free vertex and it's not visited then stop exploing previous vertex
3. make this as a new vertex and start the loop again

In DFS Traversal, we are picking one element and exploring it fully (1->2-3->4). If it ends then start exploring 4 then 3 ...
*/

const int size=8;

void DFSUsingMatrix(int arr[size][size],int size,int vertex){
    //Insert the first element make it as visited and insert in stack
    int explore;
    stack<int> s;
    bool visited[size]={0};
    visited[vertex]=true;
    cout<<vertex<<" ";
    s.push(vertex); 

    while(!s.empty()){      // while all elements are not explored fully
        for(int i=1;i<size;i++){
            if(arr[vertex][i]==1 && visited[i]==false){     //If we found any free vertex then stop exploring previous vertex and start exploring new vertex
                s.push(vertex);
                vertex=i;
                cout<<vertex<<" ";
                visited[vertex]=true;
                i=1;        // Start again
            }
        }
        vertex=s.top(); //Once we are done with exploring all the vertexes from starting vertex then make source vertex as last viisted vertex.
        s.pop();
    }
}

void dfsRecursion(int arr[size][size],int size,int vertex){
    static int visited[8] {0};  //Initializing with static is important here
    if(visited[vertex]==0){     // When all the elements are visited it will stop
        cout<<vertex<<" "   ;
        visited[vertex]=1;
        for(int i=1;i<size;i++){
            if(arr[vertex][i]==1 && visited[i]==0){     //If found stop and do recursive call
                dfsRecursion(arr,size,i);
            }
        }
    }
}

void BFSUsingMatrix(int arr[size][size], int size, int vertex){
    int explore;
    queue<int> q;
    bool visited[size]={0};     //Initially all nodes are unvisited which is false in this case

    q.push(vertex);     // We will push first vertex in queue 
    visited[vertex]=true;   // Make it visited

    while(!q.empty()){      // Loop in until all the vertex are visited
        explore=q.front();  // Take the element from queue
        q.pop();

        cout<<explore<<" ";     //Print it

        //Explore all the neighbors of vertex explore and insert them in queue and make them visited
        for(int i=1;i<size;i++){
            if(arr[explore][i]==1 && visited[i]==false){    // If element present and it's not visited
                q.push(i);
                visited[i]=true;
            }
        }
    }
}


int main(){
    int ele;
    
    int arr[size][size];

    //Taking input for Adjacency Matrix (Will start array from 1)
    /*Array size: 8*8
    0 1 1 1 0 0 0
    1 0 1 0 0 0 0
    1 1 0 1 1 0 0
    1 0 1 0 1 0 0
    0 0 1 1 0 1 1
    0 0 0 0 1 0 0
    0 0 0 0 1 0 0
    */

    for(int i=1;i<8;i++){
        for(int j=1;j<8;j++){
            cin>>ele;
            arr[i][j]=ele;
        }
    }
    
    cout<<"BFS: ";
    BFSUsingMatrix(arr,8,6);

    cout<<"\nDFS: ";
    DFSUsingMatrix(arr,8,4);

    return 0;
}