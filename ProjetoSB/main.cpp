/*
 * main.cpp
 *
 */


#include <iostream>
#include "Registradores.h"
#include "Operacoes.h"
#include "CodigoIn.h"
#include "Montador.h"

using namespace std;

int main () {

	cout << "hello" << endl;// << s0.nome << endl;
	list<string> tokens(1,"adds");
//	tokens.push_front("add");
	tokens.push_back("$s0");
	tokens.push_back("$s1");
	tokens.push_back("$t1");

	OperacaoBinaria opBin(tokens);
	try {
		cout << opBin.conversaoBinaria() << endl;
	}
	catch (runtime_error* e) {
		cout << "Exception!! " << e->what() << endl;
	}

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
