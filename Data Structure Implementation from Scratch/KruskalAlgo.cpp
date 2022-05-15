#include<bits/stdc++.h>
#define I INT_MAX
#define size 6
using namespace std;

/* Let us create the following graph  
       4     4
    0-----1-----4
    |   / |   / | 
  6 | 6/  |3 /2 | 7         (There is one more edge from 2-4 with weight 8) 
    | /   | /   |        
    2-----3-----5
       1     3   
*/

/* To implement the kruskal's algorithm we are using disjoint set
Time complexity of this algorithm: O(nlogn)
 To better understand this algorithm first go through disjoint algo*/

//To sort the edges according to weights
bool comp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y){
    return x.second < y.second;
}

//Initially every vertex is a independent set 
void makeParentOfSelf(int *rank, int *parent) {
    for(int i=0; i<size; i++) {
        rank[i] = 0;
        parent[i] = -1;
    }
}

//To find the parent of Node/Vertex
int findParent(int *parent, int v) {
    if(parent[v]==-1)
        return v;
    return parent[v]=findParent(parent,parent[v]);
}

//To combine two sets
bool makeUnion(int x, int y, int *parent, int *rank){
    int parentOfX = findParent(parent, x);
    int parentOfY = findParent(parent, y);

    if(parentOfX == parentOfY)  
        return false;
    else {
        if(rank[parentOfX] > rank[parentOfY])
            parent[parentOfY] = parentOfX;
        else {
            parent[parentOfX] = parentOfY;
            if(rank[parentOfX] == rank[parentOfY])
                rank[parentOfY]++;
        }
    }

    return true;
}

int main(){
    
    int rank[size], parent[size];
    int countEdges=0;

    int graph[size][size] = { {I, 4, 6, I, I, I},
						      {4, I, 6, 3, 4, I},
            			      {6, 6, I, 1, 8, I},
            			   	  {I, 3, 1, I, 2, 3},
            				  {I, 4, 8, 2, I, 7},
            				  {I, I, I, 3, 7, I} };

    vector<pair<pair<int,int>,int>> v;

    // Fill all the edges from adjacency matrix to vector
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){    //Traverse only upper traingular matrix (as we have same node in lower traingular matrix)
            if(graph[i][j]!=I) {    //If it's not INT_MAX then there is a valid age
                int source=i;
                int destination=j;
                int weight=graph[i][j];
                v.push_back(make_pair(make_pair(source,destination),weight));
            }
        }
    }        

    //Sort the vector according to weights. So the edge having lesser weight will be chosen first.
    sort(v.begin(),v.end(),comp);
    
    // Make each vertex a independent set
    makeParentOfSelf(rank,parent);

    // Traverse through a sorted vector
    for(auto i: v){
        int source = i.first.first;
        int dest = i.first.second;
        int weight = i.second;

        // As per the MST property edges are always 1 lesser than the no. of vertex
        if(countEdges < size)   //Stop it when we found enough edges (Edges are sorted in ascending weight order so it's already MST)
            if(makeUnion(source, dest, parent, rank)) {
                //If the function returns true means there is no cycle and we can form an edge
                cout<<source<<"-"<<dest<<": "<<weight<<"\n";    //Print source, dest and weight of every valid edge
                countEdges++;
            }
        else    //If we have found edges == vertex-1 (Done with MST)
            break;
    }

    return 0;
}