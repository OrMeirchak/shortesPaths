#include "shortesPath.h"

Graph ShortesPath::operator()(Graph& graph){

	Graph Gs=buildGs(graph);
	
	Graph GsT = Gs.transport();

	Graph HT =buildHT(GsT);

	Graph H = HT.transport();

	return H;
}

Graph ShortesPath::buildGs(Graph& graph)
{
	Graph res = graph;

	BFS bfs;
	bfs(graph);
	int* distance = bfs.getDistanceArray();

	for (int u = 1; u <= graph.getNumberOfVertex(); u++) {

		List<int>& adjacent = graph.getAdjList(u);
		List<int>::Item* p = adjacent.getHead();

		while (p) {
			int v = p->data;

			if (distance[v] != distance[u] + 1) {
				res.removeEdge(u, v);
			}
			p = p->next;
		}
	}
	return res;
}

Graph ShortesPath::buildHT(Graph& graph){
	Graph res = graph;

	BFS bfs;
	bfs(graph);
	int* distance = bfs.getDistanceArray();

	for (int u = 1; u <= graph.getNumberOfVertex(); u++) {
		if (distance[u] == (-1)) {
			res.clearAdjList(u);
		}
		else {

			List<int>& adjacent = res.getAdjList(u);
			List<int>::Item* p = adjacent.getHead();

			while (p) {
				int v = p->data;

				if (distance[v] ==(-1)) {
					res.removeEdge(u, v);
				}
				p = p->next;
			}
		}
	}
	return res;
}
