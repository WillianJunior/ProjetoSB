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

void mostraHelp() {
	ifstream streamLeiame("LEIAME");
	while (streamLeiame.good()) {
		cout << (char) (streamLeiame.get());
	}
	streamLeiame.close();
	cout << endl;
}

int main (int argc, char** argv) {

	if (string("-h").compare(argv[1]) == 0 || argc != 3 ) {
		mostraHelp();
		return 0;
	}

	// cria os objetos de entrada e saida de arquivo
	CodigoIn codigoIn(argv[1]);
	CodigoOut codigoOut(argv[2]);

	// monta o codigo assembly
	Montador montador(&codigoIn, &codigoOut);
	montador.monta();

	// escreve no arquivo a saida
	codigoOut.escreveSaida();

	return 0;
}
