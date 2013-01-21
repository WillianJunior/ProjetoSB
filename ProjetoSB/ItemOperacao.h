#ifndef _ITEMOPERACAO_H
#define _ITEMOPERACAO_H

#include "TipoOperacao.h"

#include <string>

using namespace std;

struct ItemOperacao {
	string nome;
	TipoOperacao tipo;
	string opcode;
	string funct;
	string fmt;

};

#endif  //_ITEMOPERACAO_H
