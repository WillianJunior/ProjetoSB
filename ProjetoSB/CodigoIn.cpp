#include "CodigoIn.h"


string CodigoIn::pegaLinha() {
	string line;

	if (Entrada.eof()) {
		Entrada.close();
		return "-FIM-";
	}

	getline (Entrada,line);

	//Evitar mandar linhas totalmente em branco.
	while ( ! (line.size() != 0) ){
		//Tenta pegar outra linha caso nao tenha chegado ao fim do arquivo.
		if (!Entrada.eof()) getline (Entrada,line);
		//Caso chegue ao fim do arquivo retorna o identificador de fim de arquivo.
		else return "-FIM-";
	}

	return line;

}


void CodigoIn::abreArquivo(){

	Entrada.open("entrada.s", ios::in);
	if(!Entrada.is_open())
		cout << "Problema ao abrir o arquivo de entrada!" << endl;

}
