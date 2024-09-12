#include <search.hpp>



//To iterate over the adjancy nodes of u, you can use the following template code 
// int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
// LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
// for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
//     int v = p->value; // v is the adjvancy node of u
//     // YOUR CODE HERE
// }

std::vector<int> bfs_path(Graph &G, int src, int dest) {
        int N = G.n;
        std::vector<int> dist(N, -1);
        std::vector<int> parent(N, -1);
        Queue<int> q;
        q.push(src);
        dist[src] = 0;

        // Perform BFS
        while (!q.empty()) {
            int u = q.pop();
            int numberOfAdjacencyNodes = G.e[u].size();
            LinkedListNode<int> *p = G.e[u].getRoot();
            for (int i = 0; i < numberOfAdjacencyNodes; i++, p = p->next) {
                int v = p->value;  // v is the adjacency node of u
                if (dist[v] == -1) {  // If not visited
                    dist[v] = dist[u] + 1;  // Update distance
                    parent[v] = u;  // Set parent
                    q.push(v);  // Push to queue
                    if (v == dest) {  // Stop if we reach the destination
                        break;
                    }
                }
            }
        }

        if (dist[dest] == -1) {
            return {};
        }

        // Reconstruct path from `src` to `dest`
        std::vector<int> result;
        for (int v = dest; v != -1; v = parent[v]) {
            result.push_back(v);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

void bfs(Graph &G, int start, int destination, int passBy, std::vector<int> &path) {
    int N = G.n;  // Number of nodes in the graph

    // Step 1: Find the path from start to passBy
    std::vector<int> path1 = bfs_path(G, start, passBy);
    if (path1.empty()) {
        return;
    }

    // Step 2: Find the path from passBy to destination
    std::vector<int> path2 = bfs_path(G, passBy, destination);
    if (path2.empty()) {
        return;
    }

    // final path
    path = path1;
    path.insert(path.end(), path2.begin() + 1, path2.end());
}

