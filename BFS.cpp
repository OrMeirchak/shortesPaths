#include "BFS.h"

void BFS::initializeArrayOfDistance(int numOfVertex){
	distance = new int[numOfVertex + 1];

	for (int i = 1; i <= numOfVertex; i++){
		distance[i] = -1;
	}
}

BFS::BFS(){
	distance = nullptr;

}

BFS::~BFS() {
	delete[] distance;
}

void BFS::operator()(Graph& graph){
	queue.makeEmpty();
	initializeArrayOfDistance(graph.getNumberOfVertex());
	int source = graph.getSource();
	queue.enqueue(source);
	distance[source] = 0;

	while (!queue.isEmpty()) {
		int u = queue.dequeue();

		List<int>& adjacent= graph.getAdjList(u);
		List<int>::Item* p = adjacent.getHead();

		while (p) {
			int v = p->data;
			if (distance[v] == -1)//In case we have not yet visited d[v]
			{
				distance[v] = distance[u] + 1;
				queue.enqueue(v);
			}
			p = p->next;
		}
	}
}

int* BFS::getDistanceArray()
{
	return distance;
}


