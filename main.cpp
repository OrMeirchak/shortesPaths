#define USING_NAMESPACE_STD
#include <stdio.h>
#include <stdlib.h>
#include "shortesPath.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

//the function Finds the graph of the shortest paths from a single source to a single target in directed graphs
//there is a array of vertexes
//every vertex there is linked list of all of is adjacet
int main(void) {

	Graph graph;
	try {
		graph.readGraph();
	}
	catch (wrongInputException &e) {
		cout << "wrong input" << endl;
		exit(1);
	}
	catch (sourceNotInitializedException &e) {
		cout << "wrong input" << endl;
		exit(1);
	}
	catch (targetNotInitializedException& e) {
		cout << "wrong input" << endl;
		exit(1);
	}

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	ShortesPath shortesPath;
	Graph res=shortesPath(graph);

	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	
	res.printGraph();

	cout << endl;
	ofstream myfile(stdout); // The name of the file
	myfile << "Time taken by function shortesPath is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}