#ifndef _CODIGOOUT_H
#define _CODIGOOUT_H

#include <string>
#include <list>
#include "CodigoIn.h"
#include <fstream>

using namespace std;
class CodigoOut {
public:
	CodigoOut(){
		this->abreArquivo();
	};
	CodigoOut(string url){
		this->url = url;
		abreArquivo();
	};
	void novaLinha(string linha);
	void escreveSaida(void);
	void mostraSaida ();
private:
	string url;
	list<string> codigo;
	fstream Saida;

	void abreArquivo();
};


#endif  //_CODIGOOUT_H
