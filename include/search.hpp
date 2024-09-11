#include <iostream>
#include <graph.hpp>
#include <queue.hpp>
#include <stack.hpp>


void bfs(Graph &G, int start, int destination, int passBy, std::vector<int> &path);
void dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path);
void rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path);

void findArticulationPointsAndBridges(Graph &G, std::vector<int> &articulationPoints, std::vector<std::pair<int, int> > &bridges);
