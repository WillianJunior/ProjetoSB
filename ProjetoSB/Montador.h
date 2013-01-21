#ifndef _MONTADOR_H
#define _MONTADOR_H

#include "CodigoIn.h"
#include "CodigoOut.h"
#include "ItemLabel.h"

#include <string>
#include <list>
#include <vector>
#include <iostream>

#include "Operacoes.h"

using namespace std;

class Montador {
public:
	Montador(CodigoIn *codigoIn, CodigoOut *codigoOut);
	void monta() throw (runtime_error*);
private:
	CodigoIn *codigoIn;
	CodigoOut *codigoOut;
	list<ItemLabel> listaLabels;
	list<Operacao*> listaInstrucoes;
	void primeiraPassagem() throw (runtime_error*);
	void segundaPassagem() throw (runtime_error*);
	list<string> separaTokens(string linha)throw (runtime_error*);
	Operacao* pegaPredicado(list<string> tokens) throw (runtime_error*);
	list<string> validaTokens(list<string> listaTokens, int numVirgulas)throw (runtime_error*);
};

#endif  //_MONTADOR_H
