//

//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ProjetoSB
//  @ File Name : CodigoIn.h
//  @ Date : 09/01/2013
//  @ Author : Willian
//
//

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
	list<ItemLabel> Label;
	string pegaLinha();
	CodigoIn(string url){this->url = url;this->abreArquivo();};
	CodigoIn(){ this->abreArquivo();};

private:
	string url;
	fstream Entrada;

	void abreArquivo();

};

#endif  //_CODIGOIN_H
