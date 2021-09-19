#include "Graph.h"

Graph::Graph(){
	numOfVertex = 0;
	source = -1;
	target = -1;
}

Graph::Graph(const Graph& other) : graph(other.graph){
	numOfVertex = other.numOfVertex;
	source = other.source;
	target = other.target;
}

void Graph::makeEmptyGraph(int n){
	graph.makeEmpty(n+1);
	numOfVertex = n;
}

bool Graph::isAdjacent(int u, int v) {
	try {
		checkIfVertexExist(u,v);
	}
	catch (vertexDoesntExistException e){
		return false;
	}

	try {
		return graph[u].isExist(v);
	}
	catch (outOfIndexExeption  e) {
		return false;
	}
}

List<int>& Graph::getAdjList(int u){
	return graph[u];
}

void Graph::addEdge(int u, int v) {
	checkIfVertexExist(u,v);

	List<int>* tempForDebbuging = &graph[u];

	graph[u].add(v);
}

void Graph::removeEdge(int u, int v){
	try {
		graph[u].deleteItem(v);
	}
	catch (itemDoesntExistException) {
		throw edgeDoesntExistException();
	}
}

void Graph::readGraph() {
	int n;  //number of vertexes in G
	int s;  //start vertex for shortest path algorithm
	int t;  //target vertex for shortest path algorithm 
	int u;  //origin vertex
	int v;  //destination vertex
	cin >> n;

	cin >> s;
	
	cin >> t;


	if (s < 0 || t < 0 || n < 0)
	{
		throw wrongInputException();
	}
	if (s > n || t > n)
	{
		throw wrongInputException();
	}

	makeEmptyGraph(n);
	setSource(s); // initialize source
	setTarget(t); // initialize destination.         //create G graph

	while (cin >> u)    //check if input is eof (^Z)
	{
		if (cin >> v)
		{
			if (u < 0 || v < 0)
			{
				throw wrongInputException();
			}
			if (u > n || v > n)
			{
				throw wrongInputException();
			}
		}
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}

		addEdge(u, v);
	}
}

void Graph::printGraph(){
	cout << endl;
	for (int u = 1; u <= numOfVertex; u++){

		List<int> &adjacent = graph[u];

		if (!adjacent.isEmpty()) {
			List<int>::Item *p = adjacent.getHead();

			while (p) {
				cout << u << "    " << p->data << endl;
				p = p->next;
			}

		}
	}
}

bool Graph::isEmpty(){
	return (numOfVertex == 0);
}

void Graph::checkIfVertexExist(int vertex) {
	if ((vertex < 1) || (vertex > numOfVertex)) {
		throw new vertexDoesntExistException;
	}
}

void Graph::checkIfVertexExist(int vertex1, int vertex2){
	checkIfVertexExist(vertex1);
	checkIfVertexExist(vertex2);
}

Graph Graph::transport(){
	Graph res;
	res.makeEmptyGraph(numOfVertex);
	res.source = target;
	res.target = source;

	for (int u = 1; u <= numOfVertex; u++){

		List<int>& adjacent = getAdjList(u);
        List<int>::Item* p = adjacent.getHead();

		while (p) {
			res.addEdge(p->data, u);
			p = p->next;
		}
	}

	return res;
}

void Graph::setNumberOfVertex(int n) {
	numOfVertex = n;
}

void Graph::setSource(int s) {
	source = s;
}

void Graph::setTarget(int t) {
	target = t;
}

int Graph::getNumberOfVertex()
{
	return numOfVertex;
}

int Graph::getSource()
{
	if (source == -1) {
		throw sourceNotInitializedException();
	}
	return source;
}

int Graph::getTarget()
{
	if (target == -1) {
		throw targetNotInitializedException();
	}
	return target;
}

void Graph::clearAdjList(int u) {
	graph[u].makeEmpty();
}