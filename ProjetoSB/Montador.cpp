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


Montador::Montador(CodigoIn *codigoIn, CodigoOut *codigoOut) {
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
	string label;
	int posicao_fim_label;
	Operacao predicado;

	//TODO APAGARRRRRRRRRRRRRRRRRRRRRRRR
//	codigoIn = CodigoIn();

	while(!(linha = codigoIn->pegaLinha()).empty()) {

			//Procura o fim de um label.
			posicao_fim_label = linha.find(":");

			//Caso  tenha label na string.
			if (posicao_fim_label != string::npos){

				label = linha.substr(0,posicao_fim_label);
				tokens.push_front(label);
				linha = linha.substr(posicao_fim_label, (linha.size()-posicao_fim_label) );
				cout << "LABEL:" << label << endl;

			}

		cout << linha << endl;

		// pega uma lista de tokens
		tokens = separaTokens(linha);

		// verifica o tipo de predicado
		predicado = pegaPredicado(tokens);
	}
}

void Montador::segundaPassagem() {

}

list<string> Montador::separaTokens(string linha) {


	list<string> tokens;





	tokens.push_back(linha);
	tokens.push_back("FIM");

}

Operacao Montador::pegaPredicado(list<string> tokens) {

}

string Montador::validaTokens(list<string> listaTokens) {

}

