#include <conio.h>
#include "ConjuntoVertices.h"
#include <iostream>
#include "Grafo.h"
#include <fstream>


using namespace std;

void menuSecundario(string _grafo, bool _dirigido) {
	int opcion = 0;

	Graph grafo(_grafo, _dirigido);

	while (opcion != 5) {
		cout << "\n\n\n********* M E N U  S E C U N D A R I O *********\n\n";

		cout << "1.Mostar el grafo.\n2.Mostrar las Aristas de cada Vertice del Grafo.\n3.Etiquetar un Vertice.\n4.Obtener el grado de un Vertice.\n5.Salir.\n";
		cout << "Ingrese una opcion:";
		cin >> opcion;

		cout << "\n";

		switch (opcion)
		{
		case 1: {
			cout << "\n\n********* M O S T R A N D O  G R A F O *********\n";
			grafo.print();
			break;

		}case 2: {
			cout << "\n\n********* M O S T R A N D O  G R A F O  E N  F O R M A T O  M A T R I Z *********\n";
			grafo.printAdjacencyMatrix();
			break;

		}case 3: {
			cout << "\n\n********* E T I Q U E T A N D O  V E R T I C E  D E L  G R A F O *********\n";
			
			string vertice;
			cout << "\nIngrese el vertice a etiquetar: ";
			cin >> vertice;

			string tag;
			cout << "\nIngrese la etiqueta para el vertice: ";
			cin >> tag;

			if (grafo.addVertexTag(vertice.c_str(), tag.c_str()))
				cout << "\nSe agrego el TAG con exito.\n";
			else
				cout << "\nNo se pudo agregar el TAG con exito!!!\n";

			break;

		}case 4: {
			cout << "\n\n********* M O S T R A N D O  E L  G R A D O  D E  U N  V E R T I C E *********\n";

			string vertice;
			cout << "\nIngrese el vertice a etiquetar: ";
			cin >> vertice;

			grafo.getVertexGrade(vertice.c_str());
			break;

		}case 5: {
			cout << "\nSALIENDO AL MENU PRINCIPAL.....\n";

			break;
		}default: {
			cout << "\nOPCION NO VALIDA";
			break;
		}
		}
	}
}

string importGraph() {
	string nombreArchivo = "grafo.txt";

	ifstream archivo(nombreArchivo.c_str());
	string linea;
	string grafo = "";
	
	if (archivo.fail()) {
		cout << "\n\nTexto entrada grafo.txt no existe" << endl;
	}
	else {
		while (!archivo.eof()) {
			archivo >> linea;
			grafo += linea;
		}
	}

	archivo.close();

	return grafo;
}


int main() {
	int opcion = 0;

	string instrucciones = "\n\nINSTRUCCIONES: Ingrese su grafo como se le pide acontinuacion, se le pediran los respectivos conjuntos de vertices y aristas entre {}\n";
	string ejemplosVertices = "\n{1,2,3} o {a,b,c,d,e}";
	string ejemplosAristas = "\n{(1,3),(3,2)} o {(a,b),(c,d),(a,c)}";

	while (opcion != 3) {
		cout << "\n\n\n********* M E N U  P R I N C  I P A L *********\n\n";

		cout << "1.Importar Grafo de un Archivo.\n2.Ingresa un Grafo Manualmente.\n3.Salir.\n";
		cout << "Ingrese una opcion:";
		cin >> opcion;

		cout << "\n";

		switch (opcion)
		{
		case 1: {
			cout << "\n\n********* I M P O R T A N D O  G R A F O *********\n";

			string grafo;
			cout << "Importando el grafo del archivo, solo se aceptan grafos en el formato ({V},{E})";
			grafo = importGraph();

			bool _dirigido;
			int opcDirigido = -1;

			while (opcDirigido == -1) {
				cout << "\nEl grafo importado del archivo es:\n1. Dirigido.\n2. No Dirigido.\nSeleccione una opcion: ";
				cin >> opcDirigido;

				if (opcDirigido == 1)
					_dirigido = true;
				else if (opcDirigido == 2)
					_dirigido = false;
				else {
					opcDirigido = -1;
					cout << "\n\nSeleccione una opcion Valida.\n";
				}

			}

			menuSecundario(grafo, _dirigido);
			break;

		}case 2: {
			cout << "\n\n********* I N G R E S A N D O  G R A F O *********\n";

			string grafoVertices;
			cout << "\n\n" << instrucciones << ejemplosVertices << "\n\nIngrese el conjunto de VERTICES correspondiente al grafo en el formato anterior descrito: \n";
			cin >> grafoVertices;

			string grafoAristas;
			cout << "\n\n" << ejemplosAristas << "\n\nIngrese el conjunto de ARISTAS correspondiente al grafo en el formato anterior descrito: \n";
			cin >> grafoAristas;

			string grafo = "(" + grafoVertices + "," + grafoAristas + ")";

			bool _dirigido;
			int opcDirigido = -1;

			while (opcDirigido == -1) {
				cout << "\nEl grafo importado del archivo es:\n1. Dirigido.\n2. No Dirigido.\nSeleccione una opcion: ";
				cin >> opcDirigido;

				if (opcDirigido == 1)
					_dirigido = true;
				else if (opcDirigido == 2)
					_dirigido = false;
				else {
					opcDirigido = -1;
					cout << "\n\nSeleccione una opcion Valida.\n";
				}

			}

			menuSecundario(grafo, _dirigido);

			break;

		}case 3: {
			cout << "\nS A L I E N D O.....\n";
			break;
		}default: {
			cout << "\nOPCION NO VALIDA";
			break;
		}
		}
	}
	_getch();
}