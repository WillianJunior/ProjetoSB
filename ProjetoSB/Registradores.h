#ifndef _REGISTRADORES_H
#define _REGISTRADORES_H

#include "ItemRegistrador.h"
#include <map>
#include <iterator>

static const map<string,ItemRegistrador> montaRegistradores () {
	map<string,ItemRegistrador> mapOp;
//	mapOp["$2"] = {"$2", "00010"};
//	mapOp["$4"] = {"$4", "00100"};
//	mapOp["$8"] = {"$8", "01000"};
//	mapOp["$9"] = {"$9", "01001"};
//	mapOp["$16"] = {"$16", "10000"};
//	mapOp["$17"] = {"$17", "10001"};
//	mapOp["$v0"] = {"$v0", "00010"};
//	mapOp["$a0"] = {"$a0", "00100"};
//	mapOp["$t0"] = {"$t0", "01000"};
//	mapOp["$t1"] = {"$t1", "01001"};
//	mapOp["$s0"] = {"$s0", "10000"};
//	mapOp["$s1"] = {"$s1", "10001"};
//Registradores Float
	mapOp["$f0"] = {"$f0", "00000"};
	mapOp["$f1"] = {"$f1", "00001"};
	mapOp["$f2"] = {"$f2", "00010"};
	mapOp["$f3"] = {"$f3", "00011"};
	mapOp["$f4"] = {"$f4", "00100"};
	mapOp["$f5"] = {"$f5", "00101"};
	mapOp["$f6"] = {"$f6", "00110"};
	mapOp["$f7"] = {"$f7", "00111"};
	mapOp["$f8"] = {"$f8", "01000"};
	mapOp["$f9"] = {"$f9", "01001"};
	mapOp["$f10"] = {"$f10", "01010"};
	mapOp["$f11"] = {"$f11", "01011"};
	mapOp["$f12"] = {"$f12", "01100"};
	mapOp["$f13"] = {"$f13", "01101"};
	mapOp["$f14"] = {"$f14", "01110"};
	mapOp["$f15"] = {"$f15", "01111"};
	mapOp["$f16"] = {"$f16", "10000"};
	mapOp["$f17"] = {"$f17", "10001"};
	mapOp["$f18"] = {"$f18", "10010"};
	mapOp["$f19"] = {"$f19", "10011"};
	mapOp["$f20"] = {"$f20", "10100"};
	mapOp["$f21"] = {"$f21", "10101"};
	mapOp["$f22"] = {"$f22", "10110"};
	mapOp["$f23"] = {"$f23", "10111"};
	mapOp["$f24"] = {"$f24", "11000"};
	mapOp["$f25"] = {"$f25", "11001"};
	mapOp["$f26"] = {"$f26", "11010"};
	mapOp["$f27"] = {"$f27", "11011"};
	mapOp["$f28"] = {"$f28", "11100"};
	mapOp["$f29"] = {"$f29", "11101"};
	mapOp["$f30"] = {"$f30", "11110"};
	mapOp["$f31"] = {"$f31", "11111"};
	return mapOp;
}

static const map<string,ItemRegistrador> listaRegistradores = montaRegistradores();

//static const struct ItemRegistrador n2 = listaRegistradores.find("$2")->second;
//static const struct ItemRegistrador n4 = listaRegistradores.find("$4")->second;
//static const struct ItemRegistrador n8 = listaRegistradores.find("$8")->second;
//static const struct ItemRegistrador n9 = listaRegistradores.find("$9")->second;
//static const struct ItemRegistrador n16 = listaRegistradores.find("$16")->second;
//static const struct ItemRegistrador n17 = listaRegistradores.find("$17")->second;
//
//static const struct ItemRegistrador v0 = listaRegistradores.find("$v0")->second;
//static const struct ItemRegistrador a0 = listaRegistradores.find("$a0")->second;
//static const struct ItemRegistrador t0 = listaRegistradores.find("$t0")->second;
//static const struct ItemRegistrador t1 = listaRegistradores.find("$t1")->second;
//static const struct ItemRegistrador s0 = listaRegistradores.find("$s0")->second;
//static const struct ItemRegistrador s1 = listaRegistradores.find("$s1")->second;

static const struct ItemRegistrador f0 = listaRegistradores.find("$f0")->second;
static const struct ItemRegistrador f1 = listaRegistradores.find("$f1")->second;
static const struct ItemRegistrador f2 = listaRegistradores.find("$f2")->second;
static const struct ItemRegistrador f3 = listaRegistradores.find("$f3")->second;
static const struct ItemRegistrador f4 = listaRegistradores.find("$f4")->second;
static const struct ItemRegistrador f5 = listaRegistradores.find("$f5")->second;
static const struct ItemRegistrador f6 = listaRegistradores.find("$f6")->second;
static const struct ItemRegistrador f7 = listaRegistradores.find("$f7")->second;
static const struct ItemRegistrador f8 = listaRegistradores.find("$f8")->second;
static const struct ItemRegistrador f9 = listaRegistradores.find("$f9")->second;
static const struct ItemRegistrador f10 = listaRegistradores.find("$f10")->second;
static const struct ItemRegistrador f11 = listaRegistradores.find("$f11")->second;
static const struct ItemRegistrador f12 = listaRegistradores.find("$f12")->second;
static const struct ItemRegistrador f13 = listaRegistradores.find("$f13")->second;
static const struct ItemRegistrador f14 = listaRegistradores.find("$f14")->second;
static const struct ItemRegistrador f15 = listaRegistradores.find("$f15")->second;
static const struct ItemRegistrador f16 = listaRegistradores.find("$f16")->second;
static const struct ItemRegistrador f17 = listaRegistradores.find("$f17")->second;
static const struct ItemRegistrador f18 = listaRegistradores.find("$f18")->second;
static const struct ItemRegistrador f19 = listaRegistradores.find("$f19")->second;
static const struct ItemRegistrador f20 = listaRegistradores.find("$f20")->second;
static const struct ItemRegistrador f21 = listaRegistradores.find("$f21")->second;
static const struct ItemRegistrador f22 = listaRegistradores.find("$f22")->second;
static const struct ItemRegistrador f23 = listaRegistradores.find("$f23")->second;
static const struct ItemRegistrador f24 = listaRegistradores.find("$f24")->second;
static const struct ItemRegistrador f25 = listaRegistradores.find("$f25")->second;
static const struct ItemRegistrador f26 = listaRegistradores.find("$f26")->second;
static const struct ItemRegistrador f27 = listaRegistradores.find("$f27")->second;
static const struct ItemRegistrador f28 = listaRegistradores.find("$f28")->second;
static const struct ItemRegistrador f29 = listaRegistradores.find("$f29")->second;
static const struct ItemRegistrador f30 = listaRegistradores.find("$f30")->second;
static const struct ItemRegistrador f31 = listaRegistradores.find("$f31")->second;

static const struct ItemRegistrador none = {"x", "x"};

ItemRegistrador encontraRegistrador(string nomeRegistrador);

#endif  //_REGISTRADORES_H
