#include <conio.h>
#include "ConjuntoVertices.h"
#include <iostream>
#include "Grafo.h"

using namespace std;
int main() {
	/*VertexSet S;

	S.add("1");
	S.add("4");
	S.add("5");
	S.add("6");
	S.add("8");

	S.tagNode("7", "Mario");

	S.print();

	Graph a;

	a.addVertex("A");
	a.addVertex("B");
	a.addVertex("C");
	a.addVertex("D");

	a.addVertexTag("A", "Julia");

	a.addEdges("A", "B");
	a.addEdges("A", "C");
	a.addEdges("B", "C");
	a.addEdges("C", "A");
	a.addEdges("D", "C");
	a.print();

	a.printAdjacencyMatrix();*/

	string expresion = "{a,b,c,d},{(a,b),(b,c)}";
	Graph a(expresion);

	a.convert();
	a.print();
	a.printAdjacencyMatrix();

	_getch();
}