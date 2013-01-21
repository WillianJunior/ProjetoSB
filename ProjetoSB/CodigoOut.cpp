#include "CodigoOut.h"

void CodigoOut::novaLinha(string linha) {
	codigo.push_back(linha);
}

void CodigoOut::escreveSaida() {
	if (Saida.eof()) {
		Saida.close();
	}

	while(!codigo.empty()){

		Saida << codigo.front() << endl;
		codigo.pop_front();
	}
}

void CodigoOut::mostraSaida () {
	list<string>::const_iterator i;
	cout << "Lista de instruções decodificadas: " << endl;
	for( i = codigo.begin(); i != codigo.end(); ++i)
		cout << *i << endl;
	cout << endl;
}

void CodigoOut::abreArquivo(){

	Saida.open("saida.s", ios::out);
	if(!Saida.is_open())
		cout << "Problema ao abrir o arquivo de saida!" << endl;

}

