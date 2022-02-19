#include "Grafo.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Graph::Graph(string _rootGraph): vertices(nullptr), edges(nullptr), adjacencyMatrix(nullptr) {
	this->rootGraph = _rootGraph;

	if (!validar())
		this->rootGraph = "";

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
		adjacencyMatrix[indiceDestino][indiceOrigen] = 1;

		if (edges == nullptr)
			edges = new EdgesSet();

		edges->add(verticeOrigen, verticeDestino);
	}
}

bool Graph::addVertexTag(const char* vertice, const char* tag)
{
	if (vertices != nullptr)
		return vertices->tag(vertice, tag);
	return false;
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
	
	cout << "\n\nAristas: \n";
	if (vertices->size() != 0 && edges->size() != 0) {
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
	else {
		cout << "\n[ empty ]";
	}
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

bool Graph::validar() {
	auto toString = [](char a) {
		string s(1, a);
		return s;
	};
	
	if (rootGraph.empty()) {
		cout << "\nGrafo Vacio!!!*\n";
		return false;
	}

	bool esValid = true;
	bool llavesAbiertas = false;
	bool parentesisAbiertos = false;
	bool verticeValidos = false;
	bool finVertices = false;

	if (toString(rootGraph[0]).compare("(") != 0) {
		cout << "\nFormato del Grafo Incorrecto debe iniciar con (!!!";
		return false;
	}
	else if (toString(rootGraph[rootGraph.size() - 1]).compare(")") != 0) {
		cout << "\nFormato del Grafo Incorrecto debe finalizar con )!!!";
		return false;
	}

	for (int i = 0; i < rootGraph.size(); i++) {
		if (toString(rootGraph[i]).compare("{") == 0) {
			llavesAbiertas = true;
		}
		else if (toString(rootGraph[i]).compare("}") == 0) {
			if (llavesAbiertas == true)
				llavesAbiertas = false;
			else
				llavesAbiertas = true;

			if (finVertices == false) {
				verticeValidos = esValid;
				finVertices = true;
			}
		}
		else if (toString(rootGraph[i]).compare("(") == 0) {
			llavesAbiertas = true;
		}
		else if (toString(rootGraph[i]).compare(")") == 0) {
			if (parentesisAbiertos == true)
				parentesisAbiertos = false;
			else
				parentesisAbiertos = true;
		}
		else if (toString(rootGraph[i]).compare(",") != 0) {
			esValid = true;
		}
		else if (toString(rootGraph[i]).compare(",") == 0) {
			esValid = false;
		}
	}
	
	if (parentesisAbiertos != true && llavesAbiertas != true || verticeValidos != false)
		return esValid;
	else
		return false;
}