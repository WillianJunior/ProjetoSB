//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : ProjetoSB
//  @ File Name : Montador.cpp
//  @ Date : 09/01/2013
//  @ Author : Willian
//
//


#include "Montador.h"

Montador::Montador(CodigoIn codigoIn, CodigoOut codigoOut) {
	this->codigoIn = codigoIn;
	this->codigoOut = codigoOut;
}

void Montador::monta() {
	primeiraPassagem();
	segundaPassagem();
}

void Montador::primeiraPassagem() {
	string linha;
	list<string> tokens;
	Operacao predicado;

	while(!(linha = codigoIn.pegaLinha()).empty()) {
		// pega uma lista de tokens
		tokens = separaTokens(linha);

		// verifica o tipo de predicado
		predicado = pegaPredicado(tokens);

		switch (predicado.tipoOperacao.tipo) {
		case R:
//			linha = predicado.pegaArgumentos();
			codigoOut.novaLinha(linha);
			break;
		case I:
			break;
		case J:
			break;
		case LABEL:
			break;
		case FR:
			break;
		default:
			throw "predicado com operação não implementada!";
		}

	}
}

void Montador::segundaPassagem() {

}

list<string> Montador::separaTokens(string linha) {

}

Operacao Montador::pegaPredicado(list<string> tokens) {

}

string Montador::validaTokens(list<string> listaTokens) {

}

