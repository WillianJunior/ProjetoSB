#ifndef _OPERACOES_H
#define _OPERACOES_H

#include "ItemOperacao.h"
#include "Registradores.h"

#include <string>
#include <list>
#include <map>
#include <iterator>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using namespace std;

static const map<string,ItemOperacao> montaOperacoes () {
	map<string,ItemOperacao> mapOp;
//	mapOp["add"] = {"add", R, "000000", "010000", "x"};
//	mapOp["sub"] = {"sub", R, "000000", "010010", "x"};
	mapOp["add.s"] = {"add.s", FR, "010001", "000000", "10000"};
	mapOp["add.d"] = {"add.d", FR, "010001", "000000", "10001"};
	mapOp["sub.s"] = {"sub.s", FR, "010001", "000001", "10000"};
	mapOp["sub.d"] = {"sub.d", FR, "010001", "000001", "10001"};
	mapOp["nullOp"] = {"x", NULLOP, "x", "x", "x"};
	mapOp["j"] = {"j", J, "000010", "x", "x"};
	return mapOp;
}

static const map<string,ItemOperacao> listaOperacao = montaOperacoes();


//static const struct ItemOperacao add = listaOperacao.find("add")->second;
//static const struct ItemOperacao sub = listaOperacao.find("sub")->second;
static const struct ItemOperacao adds = listaOperacao.find("add.s")->second;
static const struct ItemOperacao addd = listaOperacao.find("add.d")->second;
static const struct ItemOperacao subs = listaOperacao.find("sub.s")->second;
static const struct ItemOperacao subd = listaOperacao.find("sub.d")->second;
static const struct ItemOperacao j = listaOperacao.find("j")->second;
static const struct ItemOperacao nullOp = listaOperacao.find("nullOp")->second;

class Operacao {
public:
	virtual ~Operacao() {};
	virtual string conversaoBinaria() = 0;
	virtual void prettyPrinter() = 0;
	virtual bool verificaNome(string nomeOperacao) = 0;
	virtual bool verificaLabel(string label) = 0;
	string getOperacao () {return operacao.nome;};
	virtual void setEndereco(const string& endereco) = 0;

protected:
	ItemOperacao operacao;
};

class OperacaoBinaria:public Operacao {
public:
	OperacaoBinaria (list<string> tokens) throw (runtime_error*);
	string conversaoBinaria() throw (runtime_error*);
	bool verificaNome(string nomeOperacao);
	bool verificaLabel(string label);
	void prettyPrinter();
	void setEndereco(const string& endereco);
private:
	string rs, rt, rd;
	void montaRegistradoresR(string& saida) throw (runtime_error*);
};

class OperacaoJump:public Operacao {
public:
	OperacaoJump (list<string> tokens, int Endereco) throw (runtime_error*);
	//Verifica se o nome da operacao e igual ao da entrada
	bool verificaNome(string nomeOperacao);
	//Verifica se o label da operacao e igual ao da entrada
	bool verificaLabel(string label);
	void prettyPrinter();
	string conversaoBinaria() throw (runtime_error*);
	void setEndereco(const string& endereco) {this->endereco = endereco;}

private:
	string conversaoIntBinario(int Endereco);
	string endereco;
};

ItemOperacao encontraOperacao(string nomeOperacao);

#endif  //_OPERACOES_H
