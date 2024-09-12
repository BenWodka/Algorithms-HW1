#include <graph.hpp>

Graph::Graph(int n) {
    this->n = n;
    this->e = std::vector<LinkedList<int> >(n, LinkedList<int>());
}

Graph::~Graph() {
    this->e.clear();
}

void Graph::insertEdge(int u, int v, bool directed) {
    this->e[u].insert(v);
    if (!directed)
        this->e[v].insert(u);
}

int Graph::search(int start, int destination, int numberOfBuilding, void (*searchfn)(Graph &, int, int, int, std::vector<int>&), std::vector<int> &path) {
    path.clear();
    searchfn(*this, start, destination, numberOfBuilding, path); 
    return 0;
} 
