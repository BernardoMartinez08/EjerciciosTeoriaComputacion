#include "Grafo.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

/*
	Constructor que recibe como parametro un string que contiene el grafo en
	un formato crudo o texto plano en otras palabras, se realiza una validacion
	que va a ser descrita mas abajo esta validacion implica verificar si el 
	formato es correcto, si el formato no es correcto se agrega un grafo vacio
	si pasa las validaciones se agrega el grafo y se convierte a un formato
	separado vertices en un conjunto y aristas en otro conjunto.
*/
Graph::Graph(string _rootGraph, bool _dirigido): vertices(nullptr), edges(nullptr), adjacencyMatrix(nullptr), dirigido(_dirigido) {
	this->rootGraph = _rootGraph;

	if (!validar())
		this->rootGraph = "";

	convert();
}

/*
	Funcion para agregar un nuevo vertice, pide como parametros el valor
	que representan el valor del vertice, pero no pide el valor para la
	etiqueta del mismo, para agregar el nuevo vertice ademas se agregan
	columnas y filas a la matriz de adyacencia siguiente un procedimiento
	descrito abajo.
*/
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

/*
	Funcion para agregar una nueva arista, pide como parametros los valores
	que representan los componentes x y y del par ordenado luego realiza un
	prosedimiento para extraer la posicion en el conjunto de vertices se 
	encuentra cada vertice que conforma la arista, si ambos vertices existen
	se procede a agregar en el grafo no dirigido una arista entre ambos vertices
	como no es un grafo dirigido la arista se agrega de ambos sentidos.

	Si alguno de los vertices no existe no se agrega la arista.
*/
void Graph::addEdges(const char* verticeOrigen, const char* verticeDestino) {
	int indiceOrigen = getVertexIndex(verticeOrigen);
	int indiceDestino = getVertexIndex(verticeDestino);

	if (indiceOrigen != -1 && indiceDestino != -1) {
		if (edges == nullptr)
			edges = new EdgesSet();
		
		if (dirigido != true) {
			adjacencyMatrix[indiceOrigen][indiceDestino] = 1;
			adjacencyMatrix[indiceDestino][indiceOrigen] = 1;
			edges->add(verticeOrigen, verticeDestino);
			edges->add(verticeDestino, verticeOrigen);
		}
		else {
			adjacencyMatrix[indiceOrigen][indiceDestino] = 1;
			edges->add(verticeOrigen, verticeDestino);
		}
	}
}

/*
	Funcion que permite agregar un tag a un vertice la misma funcion solo
	recibe los parametros correspondientes el vertice a etiquetar y la 
	respectiva etiqueta, luego con esto redirecciona a la funcion del
	conjunto de vertices para etiquetar los mismos.

	Si la etiqueta se agrega retorna verdadero, de lo contrario retorna
	falso.
*/
bool Graph::addVertexTag(const char* vertice, const char* tag)
{
	if (vertices != nullptr)
		return vertices->tag(vertice, tag);
	return false;
}

/*
	Funcion que nos permite imprimir en consola los vertices acompanados de sus etiquetas y las aristas en
	formato de tabla o matriz, el grafo se imprimen haciendo uso de las funciones propias de imprimir de
	cada conjunto ademas se realiza una impresion de la matriz de aristas correspondientes mostrando una
	columna y una fila con los valores de cada vertice y la matriz esta llena de los valores que indican
	si existe una arista entre los vertices correspondientes.

	Si los conjuntos estan vacios se indica lo mismo y se imprimen conjuntos vacios, luego ademas si un 
	grafo no tiene aristas se indica lo mismo y la matriz no se imprime.
*/
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


/*
	Funcion que devuelve el indice o posicion de un vertice en el conjunto de vertices
	para esto se realiza un recorrido por todo el conjunto de vertices buscando el mismo
	mientras lo busca aumenta un contador que indica la posicion, si lo encuentra retorna
	la misma, si no la encuentra retorna -1 y si el conjunto esta vacio retorna -1 tambien.
*/
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

/*
	Funcion que devuelve la matriz de adyacencia la cual es construida mediante
	el recorrido de las aristas y vertices, el mismo es arreglo bidimencional
	se agrega solo los vertices con los cuales el vertice actual recorriendo 
	tiene una conexion entonces al final el arreglo esta compuesto en cada
	posicion por los vertices con los cuales existe una arista.
*/
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
/*
	Funcion que permite imprimir en consola los vertices y las aristas, pero en
	este caso imprime las aristas mostrando el vertice y luego todas sus aristas.

	Para esto se usa la matriz de adyacencia anteriormente descrita se imprime un
	vertice seguido de los demas vertices con los que tiene una conexion en el
	formato [vertice] ----> [vertice].....
*/
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
			actual = actual->getNext();

		} while (actual != vertices->getFirst());
	}
	else {
		cout << "\n[ empty ]";
	}
}

/*
	Funcion que permite convertir un grafo en formato de texto plano a conjuntos
	separados de vertices y aristas, extrayendo solo los valores obviando el formato
	osea los parentesis, comas y llaves.

	Se realiza un recorrido del grafo en texto plano se extraen solo los valores 
	correspondientes a los vertices y aristas.

	Para el caso de los vertices: se toma el texto crudo y se obvia los primeros 
	componentes osea la apertura de llave { y el parentesis inicial ( se prosigue
	a buscar cada vertice separado por comas, se un conjunto tal que {a,b,c} se
	toma solo los valores a b y c y los mismos se agregan como vertices al conjunto
	respectivo usando otras funciones ya descritas.

	Para el caso de las aristas: se realiza un proceso similar al anterior pero en 
	este caso como una arista esta compuesta por un par odenado ademas de obviar las
	llaves se pasa a eliminar prentesis y comas interiores de cada uno de los pares
	ordenados de un conjunto de aristas tal que {(a,b), (b,c)} se obvia la llave de 
	apertura { luego se incia un recorrido en el interior del par ordenado, se elimina
	el perentesis y la coma y se toma el componente x: a y el componente y: b y asi
	con los demas, tomando en cuenta solo los valores para la arista en el componente
	x y y obviando llaves {}, comas , , y parentesis ().
*/
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

/*
	Funcion que permite validar un grafo en formato de texto plano y comprobar que el
	formato en el que fue escrito sea el correcto antes de hacer la conversion del mismo
	a un formato diferente.
*/
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

int Graph::getVertexGrade(const char* _valor) {
	vector<vector<const char*>> _lista = getAdjacencyMatrix();
	int graphSize = vertices->size();
	int grade = 0;

	if (vertices->size() != 0 && edges->size() != 0) {
		int x = 0;
		Vertex* actual = vertices->getFirst();
		do {
			if (strcmp(actual->getValue(), _valor) == 0) {
				cout << "\n" << actual->getValue() << "--->";
				for (int i = 0; i < _lista[x].size(); i++) {
					cout << setw(3) << "[ " << _lista[x][i] << " ]";
					grade++;
				}

				cout << "\n\nEl grado total de: " << actual->getValue() << " es igual a: " << grade;
			}
			x++;
			actual = actual->getNext();

		} while (actual != vertices->getFirst());
	}
	else {
		return grade;
	}
}


vector<string> Graph::convertToList(string _expr) {
	string campoAux = "";
	vector<string> vertices;

	auto toString = [](char a) {
		string s(1, a);
		return s;
	};

	if(toString(_expr[0]).compare("(") == 0)
		_expr.erase(_expr.begin());

	if(toString(_expr[_expr.size()-1]).compare(")") == 0)
		_expr.erase(_expr.end());

	for (int i = 0; i < _expr.size(); i++) {
		if (i == _expr.size() - 1) {
			campoAux += _expr[i];
			vertices.push_back(campoAux);
		}
		else if (toString(_expr[i]).compare(",") != 0) {
			campoAux += _expr[i];
		}
		else if (toString(_expr[i]).compare(",") == 0 && campoAux.compare("") != 0) {
			vertices.push_back(campoAux);
			campoAux = "";
		}
	}

	return vertices;
}


bool Graph::verifyVertexWay(string _expr)
{
	vector<string> vertices = convertToList(_expr);
	bool existWay = false;

	auto toString = [](char a) {
		string s(1, a);
		return s;
	};

	for (int i = 0; i < vertices.size(); i++) {
		if ((i + 1) < vertices.size()) {
			if (edges->belong(vertices[i].c_str(), vertices[i + 1].c_str())) {
 				existWay = true;
			}
			else
				return false;
		}
	}

	return existWay;
}
