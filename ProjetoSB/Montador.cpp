#include "Montador.h"


Montador::Montador(CodigoIn *codigoIn, CodigoOut *codigoOut) {
	this->codigoIn = codigoIn;
	this->codigoOut = codigoOut;
}

void Montador::monta() throw (runtime_error*) {
	primeiraPassagem();
	segundaPassagem();
}

void Montador::primeiraPassagem() throw (runtime_error*) {
	string linha;
	list<string> tokens;
	size_t posicao_fim_label;
	Operacao *predicado;
	ItemLabel temp_label;
	int PLC = 0;

	while((linha = codigoIn->pegaLinha()).compare("-FIM-")) {

		//Procura o fim de um label.
		posicao_fim_label = linha.find(":");

		//Caso  tenha label na string.
		if (posicao_fim_label != string::npos){

			temp_label.label = linha.substr(0,posicao_fim_label);
			temp_label.endereco = PLC;

			linha = linha.substr(posicao_fim_label+1, (linha.size()-posicao_fim_label));
			listaLabels.push_back(temp_label);
		}

		if(!linha.empty()){
			// pega uma lista de tokens
			tokens = separaTokens(linha);

			// verifica o tipo de predicado
			predicado = pegaPredicado(tokens);
			listaInstrucoes.push_back(predicado);
			PLC += 4;
		}
	}
}

void Montador::segundaPassagem() throw (runtime_error*) {

	//Contador de posicoes
	list<Operacao*>::iterator i;
	list<ItemLabel>::iterator j;
	stringstream enderecoString;
	bool tipoj;

	for(i = listaInstrucoes.begin(); i != listaInstrucoes.end(); i++){
		//Procura o endereco do label na lista de labels
		tipoj = false;
		if((*i)->verificaNome("j")){
			for(j = listaLabels.begin(); j!= listaLabels.end(); j++){
				if((*i)->verificaLabel(j->label)){
					enderecoString << j->endereco;
					(*i)->setEndereco(enderecoString.str());
					tipoj = true;
					break;
				}
			}
			if (!tipoj)
				throw runtime_error("label não encontrado!");
		}
	}

	list<Operacao*>::iterator it;
	it = listaInstrucoes.begin();
	for (;it != listaInstrucoes.end();it++) {
		codigoOut->novaLinha((*it)->conversaoBinaria());
	}
}

list<string> Montador::separaTokens(string linha)throw (runtime_error*) {

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

	list<string>	tokensSaidaValidado;
	tokensSaidaValidado = validaTokens(tokensSaida, numVirgulas);

	return tokensSaida;
}

Operacao* Montador::pegaPredicado(list<string> tokens) throw (runtime_error*) {

	ItemOperacao op = encontraOperacao(tokens.front());

	switch (op.tipo) {
	case FR:
		return new OperacaoBinaria(tokens);
	case R:
		return new OperacaoBinaria(tokens);
	case J:
		return new OperacaoJump(tokens,-1);
	default:
		throw new runtime_error("Operação não identificada");
	}
}

list<string> Montador::validaTokens(list<string> listaTokens, int numVirgulas) throw (runtime_error*) {

	ItemOperacao op = encontraOperacao(listaTokens.front());
	list<string>::const_iterator i;
	stringstream virgulas;
	virgulas << numVirgulas;
	switch (op.tipo) {
	case FR:
		if (numVirgulas != 2)
			throw new runtime_error("Problema no numero de virgulas - " + virgulas.str());
		if (listaTokens.empty())
			throw new runtime_error("Lista de tokens vazia - OperacaoBinaria");
		if (listaTokens.size() != 4){
			stringstream num;
			num << listaTokens.size();
			throw new runtime_error("Operação binaria com numero errado de argumentos, esperava 4 mas tem " + num.str());
		}
		//Checa se os registradores sao validos
		i = listaTokens.begin();
		i++;
		for (; i != listaTokens.end(); i++) {
			if (encontraRegistrador(*i).codigo.compare(none.codigo) == 0) {
				throw new runtime_error("registradores inexistentes");
			}
		}

		break;
	case R:
		// TODO espaço para validação de operações do tipo R
		break;
	case J:
		if (numVirgulas != 0)
			throw new runtime_error("Problema no numero de virgulas " + numVirgulas);
		if (listaTokens.empty())
			throw new runtime_error("Lista de tokens vazia - OperacaoBinaria");
		if (listaTokens.size() != 2){
			stringstream num;
			num << listaTokens.size();
			throw new runtime_error("Operação J com numero errado de argumentos, esperava 2 mas tem " + num.str());
		}
		break;
	default:
		throw new runtime_error("operação não identificada");
	}

	return listaTokens;
}
