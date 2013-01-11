/*
 * main.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: willian
 */


#include <iostream>
#include "Registradores.h"
#include "CodigoIn.h"


using namespace std;

int main () {
	cout << "hello" << endl << s0.nome << endl;

	CodigoIn* codIn = new CodigoIn();
	cout<< codIn->pegaLinha() << endl;

	cout << "bye" << endl;

}
