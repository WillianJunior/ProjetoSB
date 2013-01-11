//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ProjetoSB
//  @ File Name : Operacoes.cpp
//  @ Date : 09/01/2013
//  @ Author : Willian
//
//


#include "Operacoes.h"
#include "ItemOperacao.h"

string OperacaoBinaria::conversaoBinaria() {
	string saida;
	switch (operacao.tipo) {
	case R:
		saida = operacao.opcode;
		saida += rs;	// TODO converter para binario
		saida += rt;	// TODO converter para binario
		saida += rd;	// TODO converter para binario
		saida += "000000"; // TODO melhorar para incorporar o shamt
		saida += operacao.funct;
		break;
	case FR:
		saida = operacao.opcode;
		saida += operacao.fmt;
		saida += rs;	// TODO converter para binario
		saida += rt;	// TODO converter para binario
		saida += rd;	// TODO converter para binario
		saida += operacao.funct;
		break;
	default:
		throw "tipo de operação não é binaria!";
	}
	return saida;
}

ItemOperacao encontraOperacao(string nomeOperacao) {
	return listaOperacao.find(nomeOperacao)->second;
}

