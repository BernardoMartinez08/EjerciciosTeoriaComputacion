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
	Graph();
	void addVertex(const char*);
	void addEdges(const char*, const char*);

	void addVertexTag(const char*, const char*);

	void print();

	vector<vector<const char*>> getAdjacencyMatrix();
	void printAdjacencyMatrix();

private:
	VertexSet* vertices;
	EdgesSet* edges;
	int** adjacencyMatrix;

	int getVertexIndex(const char*);
};

#endif // !GRAFO_H