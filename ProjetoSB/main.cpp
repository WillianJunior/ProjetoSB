/*
 * main.cpp
 *
 */


#include <iostream>
#include "Registradores.h"
#include "CodigoIn.h"


using namespace std;

int main () {

	CodigoIn* codIn = new CodigoIn();
	string linhaAtual;
	int contadorInstrucao = 0;

	cout << "hello" << endl;// << s0.nome << endl;

	linhaAtual = codIn->pegaLinha();
	while(linhaAtual != "-FIM-"){
		cout << contadorInstrucao << " " <<linhaAtual << endl;

		//Preparar as vari‡veis para a pr—xima itera‹o.
		contadorInstrucao += 4;
		linhaAtual = codIn->pegaLinha();
	}




	cout << "bye" << endl;

}
