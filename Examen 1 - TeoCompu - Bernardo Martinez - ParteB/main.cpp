#include <conio.h>
#include "ConjuntoVertices.h"
#include <iostream>
#include "Grafo.h"
#include <fstream>

using namespace std;

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
	vector<string> historial;

	string grafo;
	grafo = importGraph();

	Graph juego(grafo);

	string opcionesJuego = "\n\n1. Piedra.\n2. Papel.\n3. Tijeras.\n4. Lagartija.\n5. Spock.\n\n";

	while (opcion != 4) {
		cout << "\n\n\n********* M E N U  P R I N C  I P A L *********\n\n";

		cout << "1.Jugar.\n2.Ver Manual del Juego.\n3.Historial de Juego.\n4.Salir.\n";
		cout << "Ingrese una opcion:";
		cin >> opcion;

		cout << "\n";

		switch (opcion)
		{
		case 1: {
			cout << "\n\n********* P I E D R A,  P A P E L,  T I J E R A S,  L A G A R T I J A,  S P O C K *********\n";

			cout << "\n\nInstrucciones: a continuacion se le pedira que seleccione la jugada para cada uno de los jugadores.\nSeleccione el numero que acompaña la opcion que desea seleccionar.";
			cout << "\n\nOpciones a Jugar:\n" << opcionesJuego;

			bool isValid = false;

			int jugador1;
			while (isValid == false) {
				cout << "\n\nIngrese la jugada del Jugador 1: ";
				cin >> jugador1;

				switch (jugador1)
				{
				case 1: case 2: case 3: case 4: case 5: {
					isValid = true;
					break;
				}
				default: {
					cout << "\n\nJugada no valida para JUGADOR 1, intente nuevamente con una de las opciones posibles.";
					break;

				}
				}
			}

			isValid = false;
			int jugador2;
			while (isValid == false) {
				cout << "\n\nIngrese la jugada del Jugador 2: ";
				cin >> jugador2;

				switch (jugador2)
				{
				case 1: case 2: case 3: case 4: case 5: {
					isValid = true;
					break;
				}
				default: {
					cout << "\n\nJugada no valida para JUGADOR 2, intente nuevamente con una de las opciones posibles.";
					break;

				}
				}
			}

			string resultado = juego.play(jugador1 - 1 , jugador2 - 1);

			cout << "\n\nEl resultado fue:\n\n" << resultado;
			historial.push_back(resultado);

			break;

		}case 2: {
			cout << "\n\n********* M A N U A L  D E  I N S T R U C C I O N E S *********\n";

			cout << "\n\nA continuacion se muestran las opciones a jugadas seguidas de las opciones sobre la cual son superiores.";
			juego.printAdjacencyMatrix();
			break;

		}case 3: {
			cout << "\n\n********* H I S T O R I A L  D E  J U E G O *********\n";

			if (historial.empty())
				cout << "\n\nLista Vacia!!";
			else {
				for (int i = 0; i < historial.size(); i++) {
					cout << "\n\n" << historial[i];
				}
			}

			break;

		}case 4: {
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