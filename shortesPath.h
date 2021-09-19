#pragma once
#include "BFS.h"

//the class get a graph and returns the graph with the shortest paths beetween s and t
class ShortesPath {
private:

	Graph buildGs(Graph& graph);//The function get a graph performing DFS on it and remove every edge (u,v) that d[v] != d[u] +1

	Graph buildHT(Graph& graph);//The function get a graph performing DFS on it and remove every edge that not in the path s--->t
public:

	Graph operator()(Graph& graph);
};
