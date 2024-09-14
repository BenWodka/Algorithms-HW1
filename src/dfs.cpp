#include <search.hpp>
using namespace std;


void dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n; // Number of nodes in the graph
    vector<bool> visited(N, false);
    vector<int> parent(N, -1);
    Stack<int> s;
    s.push(start);
    visited[start] = true;

    while(!s.empty()){
        int u = s.pop();

        if (u == destination) break;

        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
        for (int i = 0; i < numberOfAdjacencyNodes; i ++, p = p->next) { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
            if (!visited[v]){
                s.push(v);
                visited[v] = true;
                parent[v] = u;
            }

        }
        
    }

    vector<int> tempPath;
    for (int v = destination; v!= -1; v= parent[v]){
        tempPath.push_back(v);
    }
    reverse(tempPath.begin(), tempPath.end());

    if (tempPath.size() > numberOfBuilding) {
        path.clear(); 
    }
    else{
        path = tempPath;
    }
}
