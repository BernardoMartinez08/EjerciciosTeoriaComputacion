#include <conio.h>
#include "Conjunto.h"
#include <iostream>

using namespace std;
int main() {
	Set S;

	S.addNode("1");
	S.addNode("4");
	S.addNode("5");
	S.addNode("6");
	S.addNode("8");

	S.print();
	
	if (S.belong("1")) 
		cout << "Elemento 1 pertenece al conjunto!\n";
	else
		cout << "Elemento 1 no pertenece al conjunto!\n";

	if (S.belong("6"))
		cout << "Elemento 6 pertenece al conjunto!\n";
	else
		cout << "Elemento 6 no pertenece al conjunto!\n";
	
	if (S.belong("89"))
		cout << "Elemento 89 pertenece al conjunto!\n";
	else
		cout << "Elemento 89 no pertenece al conjunto!\n";

	S.deleteNode("5");

	if (S.notBelong("1"))
		cout << "Elemento 1 no pertenece al conjunto!\n";
	else
		cout << "Elemento 1 pertenece al conjunto!\n";

	if (S.notBelong("5"))
		cout << "Elemento 5 no pertenece al conjunto!\n";
	else
		cout << "Elemento 5 pertenece al conjunto!\n";

	S.print();

	Set X;
	X.addNode("1");
	X.addNode("4");
	X.addNode("5");
	X.addNode("5");
	X.addNode("6");
	X.addNode("6");
	X.addNode("6");
	X.addNode("8");

	Set Y;
	Y.addNode("1");
	Y.addNode("4");
	Y.addNode("5");
	Y.addNode("6");
	Y.addNode("8");

	X.print();
	Y.print();

	X.equalTo(Y);

	_getch();
}