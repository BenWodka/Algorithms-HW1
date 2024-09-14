#include <search.hpp>
#include <vector>
#include <algorithm>
using namespace std;


void dfsRecursive(Graph &G, int u, int destination, vector<bool> &visited, vector<int> &path, bool &found, int numberOfBuilding, int depth) {
    if (found || depth > numberOfBuilding) {
        return; 
    }

    visited[u] = true;
    path.push_back(u);

    if (u == destination) {
        found = true;
        return;
    }

    // Iterate over the adjacency nodes of u
    int numberOfAdjacencyNodes = G.e[u].size();
    LinkedListNode<int> *p = G.e[u].getRoot();
    for (int i = 0; i < numberOfAdjacencyNodes; i++, p = p->next) {
        int v = p->value;
        if (!visited[v]) {
            dfsRecursive(G, v, destination, visited, path, found, numberOfBuilding, depth + 1);
        }
        if (found) break;
    }

    if (!found) {
        path.pop_back();
        visited[u] = false;
    }
}

void rdfs(Graph &G, int start, int destination, int numberOfBuilding, vector<int> &path) {
    int N = G.n; 
    vector<bool> visited(N, false);
    bool found = false;

    dfsRecursive(G, start, destination, visited, path, found, numberOfBuilding, 1);

    if (path.size() > numberOfBuilding || !found) {
        path.clear();
    }
}
