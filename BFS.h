#pragma once
#include "Graph.h"
#include "Queue.h"

//The class implements the BFS algorithm using a queue
//the function doesnt release the memory of the distance array!
class BFS {
private:

	int* distance;
	Queue<int> queue;

	void initializeArrayOfDistance(int numOfVertex);//the function allocate memory to the distance array and initialize all the cells to -1

public:
	BFS();
	~BFS();

	void operator()(Graph& graph);//The function make the array of distances by the BFS algorithm using queue

	int* getDistanceArray();//the function return the array of distance
};
