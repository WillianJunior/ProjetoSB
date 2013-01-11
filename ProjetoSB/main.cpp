/*
 * main.cpp
 *
 */


#include <iostream>
#include "Registradores.h"
#include "CodigoIn.h"
#include "Montador.h"

using namespace std;

int main () {

	cout << "hello" << endl;// << s0.nome << endl;

	CodigoIn codIn("teste");
	CodigoOut codOut("teste2");

	string linhaAtual;
	int contadorInstrucao = 0;

	Montador* montador = new Montador (&codIn, &codOut);
	montador->monta();
/*
	linhaAtual = codIn.pegaLinha();
	while(linhaAtual != "-FIM-"){
		cout << contadorInstrucao << " " <<linhaAtual << endl;

		//Preparar as vari�veis para a pr�xima itera��o.
		contadorInstrucao += 4;
		linhaAtual = codIn.pegaLinha();
	}
*/



	cout << "bye" << endl;

}
