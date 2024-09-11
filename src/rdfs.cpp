#include <search.hpp>
/*
To iterate over the adjancy nodes of u, you can use the following template code 
int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
    int v = p->value; // v is the adjvancy node of u
    // YOUR CODE HERE
}
*/

void rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n; // Number of nodes in the graph
    // YOUR CODE HERE
}

