#include "Operacoes.h"
#include <iostream>

OperacaoBinaria::OperacaoBinaria (list<string> tokens) throw (runtime_error*) {

	operacao = encontraOperacao(tokens.front());
	tokens.pop_front();
	rd = tokens.front();
	tokens.pop_front();
	rs = tokens.front();
	tokens.pop_front();
	rt = tokens.front();

}

void OperacaoBinaria::montaRegistradoresR(string& saida) throw (runtime_error*) {
	ItemRegistrador irs, irt, ird;
	irs = encontraRegistrador(rs);
	irt = encontraRegistrador(rt);
	ird = encontraRegistrador(rd);

	saida += irs.codigo;
	saida += irt.codigo;
	saida += ird.codigo;
}

string OperacaoBinaria::conversaoBinaria() throw (runtime_error*) {
	string saida("");
	switch (operacao.tipo) {
	case FR:
		saida = operacao.opcode;
		saida += operacao.fmt;
		montaRegistradoresR(saida);
		saida += operacao.funct;
		break;
	case R:
		saida = operacao.opcode;
		montaRegistradoresR(saida);
		saida += "000000"; // TODO melhorar para incorporar o shamt
		saida += operacao.funct;
		break;
	default:
		throw runtime_error("operação não implementada para operação binaria");
	}
	return saida;
}

void OperacaoBinaria::prettyPrinter() {
	cout << operacao.nome << " " << rs << " " << rt << " " << rd << endl;
}

bool OperacaoBinaria::verificaLabel(string nomeOperacao){
	throw runtime_error("Este metodo nao pode ser chamado nesta classe");
}

void OperacaoBinaria::setEndereco(const string& endereco){
	throw runtime_error("Este metodo nao pode ser chamado nesta classe");
}
bool OperacaoBinaria::verificaNome(string nomeOperacao){
	if(operacao.nome == nomeOperacao)
		return true;
	else
		return false;
}

OperacaoJump::OperacaoJump (list<string> tokens, int Endereco) throw (runtime_error*) {

	operacao = encontraOperacao(tokens.front());
	tokens.pop_front();
	if(Endereco != -1)
		endereco = conversaoIntBinario(Endereco);
	else
		endereco = tokens.front();
}

string OperacaoJump::conversaoBinaria() throw (runtime_error*) {
	// TODO fazer a coversão binaria de operaçoes jump
	return "00000";
}

string OperacaoJump::conversaoIntBinario(int Endereco){

	int resto = 0;
	string valor;

	while(Endereco > 0)
	{
		resto = Endereco % 2;
		Endereco /= 2;
		if(resto == 0) valor.push_back('0');
		else valor.push_back('1');
	}
	while(valor.length()<=26) valor.insert(0,"0");
	return valor;
}

bool OperacaoJump::verificaNome(string nomeOperacao){
	if(operacao.nome == nomeOperacao)
		return true;
	else
		return false;
}

bool OperacaoJump::verificaLabel(string label){
	if(endereco == label)
		return true;
	else
		return false;
}

void OperacaoJump::prettyPrinter() {
	cout << operacao.nome << " " << endereco << endl;
}

ItemOperacao encontraOperacao(string nomeOperacao) {
	map<string,ItemOperacao>::const_iterator temp = listaOperacao.find(nomeOperacao);
	return temp != listaOperacao.end() ? temp->second : nullOp;
}
