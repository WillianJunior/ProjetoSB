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

//	if (argc != 3 || string("-h").compare(argv[1]) == 0) {
//		mostraHelp();
//		return 0;
//	}

	// cria os objetos de entrada e saida de arquivo
//	CodigoIn codigoIn(argv[1]);
//	CodigoOut codigoOut(argv[2]);
	CodigoIn codigoIn;
	CodigoOut codigoOut;

	// monta o codigo assembly
	Montador montador(&codigoIn, &codigoOut);
	try {
		montador.monta();
	} catch (runtime_error *e) {
		cout << "Erro: " << e->what() << endl;
		return -1;
	}

	// escreve no arquivo a saida
	codigoOut.mostraSaida();
	codigoOut.escreveSaida();

	return 0;
}
