#ifndef _CODIGOIN_H
#define _CODIGOIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "ItemLabel.h"
#include <list>

using namespace std;

class CodigoIn {
public:
	string pegaLinha();
	CodigoIn(string url){this->url = url;this->abreArquivo();};
	CodigoIn(){ this->abreArquivo();};

private:
	string url;
	fstream Entrada;

	void abreArquivo();

};

#endif  //_CODIGOIN_H
