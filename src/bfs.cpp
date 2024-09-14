#include <search.hpp>
using namespace std;

vector<int> bfs_path(Graph &G, int start, int dest) {
        int N = G.n;
        vector<int> dist(N, -1);
        vector<int> parent(N, -1);
        Queue<int> q;
        q.push(start);
        dist[start] = 0;


        // BFS
        while (!q.empty()) {
            int u = q.pop();
            int numberOfAdjacencyNodes = G.e[u].size();
            LinkedListNode<int> *p = G.e[u].getRoot();
            for (int i = 0; i < numberOfAdjacencyNodes; i++, p = p->next) {
                int v = p->value;  // v is  adjacency node of u
                if (dist[v] == -1) {  // If not visited
                    dist[v] = dist[u] + 1;  // Update distance
                    parent[v] = u;  // Set parent
                    q.push(v);  // Push to queue
                    if (v == dest) break;
                }
            }
        }

        if (dist[dest] == -1) return {};

        // Reconstruct path from `start` to `dest`
        vector<int> result;
        for (int v = dest; v != -1; v = parent[v]) {
            result.push_back(v);
        }
        reverse(result.begin(), result.end());
        return result;
    }

void bfs(Graph &G, int start, int destination, int passBy, std::vector<int> &path) {
    int N = G.n;  // Number of nodes in the graph
    int numberOfBuilding = 27;

    // Step 1: Find the path from start to passBy
    vector<int> path1 = bfs_path(G, start, passBy);
    if (path1.empty()) return;

    // Step 2: Find the path from passBy to destination
    vector<int> path2 = bfs_path(G, passBy, destination);
    if (path2.empty()) return;

    // final path
    path = path1;
    path.insert(path.end(), path2.begin() + 1, path2.end());

    if (path.size() > numberOfBuilding) {
        vector<int> directPath = bfs_path(G, start, destination);
        if (!directPath.empty() && directPath.size() <= numberOfBuilding) {
            path = directPath;
        } else {
            path.clear();
        }
    }
}

