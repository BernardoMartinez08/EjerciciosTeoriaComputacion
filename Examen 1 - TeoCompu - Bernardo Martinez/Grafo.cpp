#include "Grafo.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Graph::Graph(): vertices(nullptr), edges(nullptr), adjacencyMatrix(nullptr) {
}

void Graph::addVertex(const char* _verticeID) {
	if (vertices == nullptr)
		vertices = new VertexSet();

	vertices->add(_verticeID);


	//actualizacion de filas en aristas, actualiza el numero de filas
	int graphSize = vertices->size() - 1;

	int** adjacencyAux = new int* [graphSize + 1];

	for (int i = 0; i < graphSize; i++)
	{
		adjacencyAux[i] = adjacencyMatrix[i];
	}

	if (adjacencyMatrix != nullptr)
		delete adjacencyMatrix;

	adjacencyMatrix = adjacencyAux;


	//Actualizacion de columnas en aristas por cada fila del arreglo de aristas

	for (int i = 0; i < graphSize; i++)
	{
		int* adjacencyColumnaAux = new int[graphSize + 1];

		for (int j = 0; j < graphSize; j++)
		{
			adjacencyColumnaAux[j] = adjacencyMatrix[i][j];
		}

		if (adjacencyMatrix[i] != nullptr)
			delete adjacencyMatrix[i];

		adjacencyColumnaAux[graphSize] = 0;

		adjacencyMatrix[i] = adjacencyColumnaAux;
	}

	//actualizacion de la ultima fila de aristas

	adjacencyMatrix[graphSize] = new int[graphSize + 1];
	for (int i = 0; i < graphSize + 1; i++)
	{
		adjacencyMatrix[graphSize][i] = 0;
	}
}

void Graph::addEdges(const char* verticeOrigen, const char* verticeDestino) {
	int indiceOrigen = getVertexIndex(verticeOrigen);
	int indiceDestino = getVertexIndex(verticeDestino);

	if (indiceOrigen != -1 && indiceDestino != -1) {
		adjacencyMatrix[indiceOrigen][indiceDestino] = 1;
		adjacencyMatrix[indiceDestino][indiceOrigen] = 1;

		if (edges == nullptr)
			edges = new EdgesSet();

		edges->add(verticeOrigen, verticeDestino);
	}
}

void Graph::addVertexTag(const char* vertice, const char* tag)
{
	if (vertices != nullptr)
		vertices->tag(vertice, tag);
}

void Graph::print() {
	int graphSize = vertices->size();

	cout << "Grafo: \nG = ( ";
	vertices->print();
	cout << ", ";
	edges->print();
	cout << " )";

	cout << "\n\nAristas: \n";
	cout << setw(3) << " ";

	Vertex* actual = vertices->getFirst();
	do {
		cout << setw(3) << " " << actual->getValue() << "  ";
		actual = actual->getNext();

	} while (actual != vertices->getFirst());
	cout << "\n";

	actual = vertices->getFirst();
	int x = 0;
	do {
		cout << setw(3) << actual->getValue();

		for (int i = 0; i < graphSize; i++) {
			cout << setw(3) << "[ " << adjacencyMatrix[x][i] << " ]";
		}
		cout << endl;

		actual = actual->getNext();

		x++;
	} while (actual != vertices->getFirst());
}

int Graph::getVertexIndex(const char* _valor) {
	if (vertices->size() == 0) {
		return -1;
	}

	int x = 0;
	Vertex* actual = vertices->getFirst();
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			return x;
		}

		x++;
		actual = actual->getNext();;

	} while (actual != vertices->getFirst());

	return -1;
}

vector<vector<const char*>> Graph::getAdjacencyMatrix() {
	int graphSize = vertices->size();
	vector<vector<const char*>> listaAdyacencia(graphSize);

	for (int i = 0; i < graphSize; i++) {
		int x = 0;
		Vertex* actual = vertices->getFirst();
		do {
			if (adjacencyMatrix[i][x] != 0)
				listaAdyacencia[i].push_back(actual->getValue());

			x++;
			actual = actual->getNext();;

		} while (actual != vertices->getFirst());
	}

	return listaAdyacencia;
}

void Graph::printAdjacencyMatrix() {
	vector<vector<const char*>> _lista = getAdjacencyMatrix();
	int graphSize = vertices->size();

	cout << "\n\nLISTA DE ADYACENCIA\n\n";

	cout << "Vertices: ";
	vertices->print();

	cout << "\n\nConexiones: \n";

	int x = 0;
	Vertex* actual = vertices->getFirst();
	do {
		cout << setw(3) << actual->getValue() << "--->";
		for (int i = 0; i < _lista[x].size(); i++) {
			cout << setw(3) << "[ " << _lista[x][i] << " ]";
		}
		cout << endl;

		x++;
		actual = actual->getNext();;

	} while (actual != vertices->getFirst());
}