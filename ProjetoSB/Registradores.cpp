#include "Registradores.h"

ItemRegistrador encontraRegistrador(string nomeRegistrador) {
	map<string,ItemRegistrador>::const_iterator temp = listaRegistradores.find(nomeRegistrador);
	return temp != listaRegistradores.end() ? temp->second : none;
}

