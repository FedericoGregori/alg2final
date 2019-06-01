#ifndef _NODO_H_
#define _NODO_H_

#include "includes.h"

// -----------------------------------------
//
//    Operaciones con Nodos
//
// -----------------------------------------

Nodo * crearNodo(Amigo * amigo) {
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));

    strncpy(nodo->amigo.apellido, amigo->apellido, 50);
	strncpy(nodo->amigo.nombre, amigo->nombre, 50);
	
    nodo->sgte = NULL;

    return nodo;
}

void destruirNodo(Nodo * nodo) {
    free(nodo);
}

#endif // _NODO_H_