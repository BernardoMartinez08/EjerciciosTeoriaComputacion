#include "Grafo.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Graph::Graph(string _rootGraph): vertices(nullptr), edges(nullptr), adjacencyMatrix(nullptr) {
	this->rootGraph = _rootGraph;
	convert();
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

		if (edges == nullptr)
			edges = new EdgesSet();

		edges->add(verticeOrigen, verticeDestino);
	}
}

void Graph::print() {
	if (edges == nullptr)
		edges = new EdgesSet();

	if (vertices == nullptr)
		vertices = new VertexSet();

	int graphSize = vertices->size();

	cout << "\n\nGrafo: \nG = ( ";
	vertices->print();
	cout << ", ";
	edges->print();
	cout << " )";
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
	if (vertices->size() != 0 && edges->size() != 0) {
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
	else {
		cout << "\n[ empty ]";
	}
}

void Graph::convert() {
	string campoAux = "";
	bool fullVertex = false;

	auto toString = [](char a) {
		string s(1, a);
		return s;
	};

	rootGraph.erase(rootGraph.begin());
	rootGraph.erase(rootGraph.end());

	for (int i = 0; i < this->rootGraph.size(); i++) {		
		if (fullVertex == false) {
			if (toString(rootGraph[i]).compare("{") != 0 && toString(rootGraph[i]).compare(",") != 0) {
				campoAux += rootGraph[i];

				if (toString(rootGraph[i + 1]).compare("}") == 0) {
					addVertex(campoAux.c_str());
					campoAux = "";
					fullVertex = true;
					i++;
				}
			}
			else if (toString(rootGraph[i]).compare(",") == 0 && campoAux.compare("") != 0) {
				addVertex(campoAux.c_str());
				campoAux = "";
			}
			
		}
		else if (fullVertex == true) {
			string valueX = "";
			string valueY = "";

			if (toString(rootGraph[i]).compare("{") != 0 && toString(rootGraph[i]).compare(",") != 0 && toString(rootGraph[i]).compare("}") != 0) {
				for (int y = i; y < this->rootGraph.size(); y++) {
					if (toString(rootGraph[i]).compare("(") != 0 && toString(rootGraph[i]).compare(",") != 0 && toString(rootGraph[i]).compare(")") != 0) {
						campoAux += rootGraph[i];
					}
					else if (toString(rootGraph[i]).compare(")") == 0) {
						valueY = campoAux;
						campoAux = "";
						break;
					}
					else if (toString(rootGraph[i]).compare(",") == 0 && campoAux.compare("") != 0) {
						valueX = campoAux;
						campoAux = "";
					}
					i++;
				}
				addEdges(valueX.c_str(), valueY.c_str());
				campoAux = "";
			}
		}
	}
}


string Graph::play(int jugada1, int jugada2) {
	string jugadas[5]{"piedra","papel","tijera","lagartija","spock"};

	int indiceOrigen = getVertexIndex(jugadas[jugada1].c_str());
	int indiceDestino = getVertexIndex(jugadas[jugada2].c_str());

	if (indiceOrigen != -1 && indiceDestino != -1) {
		if (adjacencyMatrix[indiceOrigen][indiceDestino] == 1) {
			return "GANADOR JUGADOR 1\nJugador 1 Gana con: " + jugadas[jugada1] + " al Jugador 2 con: " + jugadas[jugada2] + ".";
		}
		else if (adjacencyMatrix[indiceDestino][indiceOrigen] == 1) {
			return "GANADOR JUGADOR 2\nJugador 2 Gana con: " + jugadas[jugada2] + " al Jugador 1 con: " + jugadas[jugada1] + ".";
		}
		else
			return "EMPATE\nJugador 1 Jugo: " + jugadas[jugada2] + " y el Jugador 2 Jugo: " + jugadas[jugada1] + ".";
	}
	else
		return "Alguna de las jugadas fue invalida.";
}
