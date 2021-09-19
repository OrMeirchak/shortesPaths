#pragma once
#include "List.h"
#include "MyArray.h"
#include <iostream>
using namespace std;

class vertexDoesntExistException : public exception {};
class edgeDoesntExistException : public exception {};
class sourceNotInitializedException : public exception{};
class targetNotInitializedException : public exception{};
class wrongInputException : public exception{};

//The class implements a directed graph that is implemented by a list of neighbors adjacent

class Graph {
private:
	MyArray<List<int>> graph;
	int numOfVertex;
	int source;
	int target;

public:

	Graph();//constructure
	Graph(const Graph&);//copy constructore

	//required functions
	void makeEmptyGraph(int n);

	bool isAdjacent(int u,int v);

	List<int> &getAdjList(int u);

	void addEdge(int u, int v);

	void removeEdge(int u, int v);

	void readGraph();

	void printGraph();

	bool isEmpty();

	//other function
	void checkIfVertexExist(int vertex);//the function get number 
	//In case the number represents a vertex exists in the graph the function The function will do nothing
	//else the function throw exception

	void checkIfVertexExist(int vertex1,int vertex2);//the function get 2 numbers
	//In case the numbers represents a vertexes exists in the graph the function The function will do nothing
	//else the function throw exception

	Graph transport();//the function return the transported garph 

	void clearAdjList(int u);//The function remove all the edge coming out of u

	//setters
    void setNumberOfVertex(int n);

	void setSource(int s);

	void setTarget(int s);

	//getters
	int getNumberOfVertex();

	int getSource();

	int getTarget();

};
