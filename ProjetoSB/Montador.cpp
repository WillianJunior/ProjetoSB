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

void Montador::monta() throw (runtime_error) {
	primeiraPassagem();
	segundaPassagem();
}

void Montador::primeiraPassagem() throw (runtime_error) {
	string linha;
	list<string> tokens;
	string label;
	int posicao_fim_label;
	Operacao predicado;


	while((linha = codigoIn->pegaLinha()).compare("-FIM-")) {

		//Procura o fim de um label.
		posicao_fim_label = linha.find(":");

		//Caso  tenha label na string.
		if (posicao_fim_label != string::npos){

			label = linha.substr(0,posicao_fim_label);
			tokens.push_front(label);
			linha = linha.substr(posicao_fim_label+1, (linha.size()-posicao_fim_label) );
			cout << "LABEL IDENTIFICADO - " << label << endl;

		}

		cout << "Instrucao Lida: "<< linha << endl;
		if(!linha.empty()){
			// pega uma lista de tokens
			tokens = separaTokens(linha);

			// verifica o tipo de predicado
			predicado = pegaPredicado(tokens);

		}

	}
}

void Montador::segundaPassagem() throw (runtime_error) {

}

list<string> Montador::separaTokens(string linha)throw (runtime_error) {

	// troca as virgulas por espaços em branco
	int virgula, numVirgulas = 0;
	while ((virgula = linha.find(',')) != string::npos) {
		linha.replace(virgula, 1," ");
		numVirgulas++;
	}

	// separa por espaço em branco
	istringstream linhaStream(linha);
	vector<string> tokens;
	copy(istream_iterator<string>(linhaStream),
				istream_iterator<string>(),
				back_inserter<vector<string> >(tokens));

	list<string> tokensSaida(tokens.begin(),tokens.end());
	ItemOperacao op = encontraOperacao(tokens[0]);

	list<string>::const_iterator i;
	cout << "Lista de Tokens Gerada: ";
	for( i = tokensSaida.begin(); i != tokensSaida.end(); ++i)
						cout << *i << " - ";
					cout << endl;


	list<string>	tokensSaidaValidado;
	tokensSaidaValidado = validaTokens(tokensSaida, numVirgulas);




	return tokensSaida;
}

Operacao Montador::pegaPredicado(list<string> tokens) throw (runtime_error) {
	ItemOperacao op = encontraOperacao(tokens.front());

	switch (op.tipo) {
	case FR:
		return OperacaoBinaria(tokens);
		//	case R:
		//		return OperacaoBinaria(tokens);
		//	case I:
		//	case J:
		//	case LABEL:
	default:
		throw runtime_error("operação não identificada");
	}
}

list<string> Montador::validaTokens(list<string> listaTokens, int numVirgulas) throw (runtime_error) {
	return listaTokens;
}

