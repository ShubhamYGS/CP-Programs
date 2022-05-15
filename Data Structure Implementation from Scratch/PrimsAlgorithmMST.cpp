#include<bits/stdc++.h>
#define I INT_MAX
#define size 6
using namespace std;

/*Time complexity of Prim's Algorithm: O(n2)*/

/* Let us create the following graph  
       4     4
    0-----1-----4
    |   / |   / | 
  6 | 6/  |3 /2 | 7         (There is one more edge from 2-4 with weight 8) 
    | /   | /   |        
    2-----3-----5
       1     3   
*/

int findMinAdjacentEdge(int graph[size][size], int vertex,int *weights, bool *visited, int *parents){
    int minWeight=INT_MAX, minIndex;

    for(int i=0;i<size;i++){
        // If we found the vertex whose weight is less than the already existing weight and it's not yet viisted
        if(graph[vertex][i]<weights[i] && visited[i]==false){
            // Modeify the weight, make it's parent point to the source vertex, To find out the min of all compare it with minWeight
            weights[i]=graph[vertex][i];
            parents[i]=vertex;
            if(weights[i]<minWeight){
                minIndex=i;
                minWeight=weights[i];
            }
        }
    }

    // return the dest index whose weight is the lowest from the source index
    return minIndex;
}


//Time complexity: O(No. of vertex)2 ~ O(n2)
void primMST(int graph[size][size], int vertex){
    int totalWeight=0;
    bool visited[size];     //For avoiding visiting to same node again
    int weights[size];      //To take the weights of edges
    int parents[size];      //To check the parent node of any vertex

    // Initially make visit of every node to false as we have not yet visited any node
    // Make weights of every edge to INT_MAX so that if there exist any lesser weight than this then it will replace it
    for(int i=0;i<size;i++) {
        visited[i]=false;
        weights[i]=INT_MAX;
    }

    // Here, will start from vertex 0, so make it as visited and make it's weight to 0 and parent to -1(No parent)
    weights[vertex]=0;
    parents[vertex]=-1;
    visited[vertex]=true;

    //As we will have no. of vertex-1 edges so traverse till that only 
    for(int i=0;i<size-1;i++){

        //every time find the min. index from a source vertex and make a edge
        int minIndex = findMinAdjacentEdge(graph,vertex,weights,visited,parents);

        //Make that vertex as visited as we will be including that edge in final MST
        visited[minIndex]=true;

        //Make the newly minimum weight vertex as a new source vertex
        vertex=minIndex;
    }

    // i- destination edge, parents[i]- source edge, weights[i]- weight on edge
    // start from 1 (no. of vertex-1 = MST) 
    // 0 is source vertex and we have already set it's parent as -1 
    for(int i=1;i<size;i++){
        totalWeight+=weights[i];
        cout<<parents[i]<<"-"<<i<<": "<<weights[i]<<"\n";
    }
}

int main(){
    
    // int graph[size][size] = { { I, 2, I, 6, I },
    //                           { 2, I, 3, 8, 5 },
    //                           { I, 3, I, I, 7 },
    //                           { 6, 8, I, I, 9 },
    //                           { I, 5, 7, 9, I } };

    int graph[size][size] = { {I, 4, 6, I, I, I},
						      {4, I, 6, 3, 4, I},
            			      {6, 6, I, 1, 8, I},
            			   	  {I, 3, 1, I, 2, 3},
            				  {I, 4, 8, 2, I, 7},
            				  {I, I, I, 3, 7, I} };

    // int graph[size][size] = {
    //         {I, 25, I, I, I, 5, I},
    //         {25, I, 12, I, I, I, 10},
    //         {I, 12, I, 8, I, I, I},
    //         {I, I, 8, I, 16, I, 14},
    //         {I, I, I, 16, I, 20, 18},
    //         {5, I, I, I, 20, I, I},
    //         {I, 10, I, 14, 18, I, I},
    // };

    primMST(graph,0);
    
    return 0;
}