#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <linked_list.hpp>
#include <queue.hpp>

class Graph {
    public:
        int n; // Number of vertices 
        std::vector<LinkedList<int> > e; // Adjacent list 
    public:
        Graph(int n);
        ~Graph();
        void insertEdge(int u, int v, bool directed = false);
        
        void reset();

        int search(int start, int destination, int numberOfBuilding, void (*searchfn)(Graph&, int, int, int, std::vector<int>&), std::vector<int> &path);

        friend void bfs(Graph &G, int start, int destination, int passBy, std::vector<int> &path);
        friend void dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path);
        friend void rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path);
        friend void findArticulationPointsAndBridges(Graph &G, std::vector<int> &articulationPoints, std::vector<std::pair<int, int> > &bridges);
};

