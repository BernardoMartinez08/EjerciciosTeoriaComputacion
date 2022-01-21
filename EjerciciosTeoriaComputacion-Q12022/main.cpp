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
	
	S.belong("1");
	S.belong("6");
	S.belong("89");

	S.deleteNode("5");

	S.notBelong("1");
	S.notBelong("5");

	S.print();
	_getch();
}