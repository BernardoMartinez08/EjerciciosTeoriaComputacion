#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "ConjuntoAristas.h"
#include "ConjuntoVertices.h"

using namespace std;

class Graph {
public:
	Graph(string);

	void print();
	void printAdjacencyMatrix();

	void convert();

private:
	string rootGraph = "";

	VertexSet* vertices;
	EdgesSet* edges;
	int** adjacencyMatrix;

	void addVertex(const char*);
	void addEdges(const char*, const char*);

	void addVertexTag(const char*, const char*);

	vector<vector<const char*>> getAdjacencyMatrix();

	int getVertexIndex(const char*);
};

#endif // !GRAFO_H