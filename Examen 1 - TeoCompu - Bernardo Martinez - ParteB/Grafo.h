#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "ConjuntoAristas.h"
#include "ConjuntoVertices.h"
#include <string>

using namespace std;

class Graph {
public:
	Graph(string);

	void print();
	void printAdjacencyMatrix();

	string play(int, int);

private:
	string rootGraph = "";

	VertexSet* vertices;
	EdgesSet* edges;
	int** adjacencyMatrix;

	void addVertex(const char*);
	void addEdges(const char*, const char*);

	vector<vector<const char*>> getAdjacencyMatrix();

	int getVertexIndex(const char*);

	void convert();
};

#endif // !GRAFO_H