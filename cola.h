#include "includes.h"

typedef struct Nodo {
    int n;
    Nodo * sgte;
} Nodo;

typedef struct Cola {
    Nodo * salida;
    Nodo * entrada;
} Cola;

/* Crear Nodo */

Nodo * crearNodo(int n) {
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->n = n;
    nodo->sgte = NULL;

    return nodo;
}

/* Borrar Nodo */

void borrarNodo(Nodo * nodo) {
    nodo->n = NULL;
    nodo->sgte = NULL;
    free(nodo);
}

/* Crear una Cola */

Cola * crearCola(){
    Cola * cola = (Cola *) malloc(sizeof(Cola));

    cola->entrada = cola->salida = NULL;

    return cola;
}

/* Encolar */

void encolar(Cola * cola, int n) {

	Nodo * nodo = crearNodo(n);

	if (!cola->salida) {
		cola->salida = nodo;
		cola->entrada = nodo;
	} else { 
		cola->entrada->sgte = nodo;
		cola->entrada = nodo;
	}	
}


/* Consular */

int consultar(Cola * cola) {
	if (cola->salida) {
		return cola->salida->n; // 
	} else {
		return NULL;
	}
}

/* Eliminar */

void eliminar(Cola * cola) {
	if (cola->salida) { 
		Nodo * eliminado = cola->salida;
		cola->salida = cola->salida->sgte; 		
		borrarNodo(eliminado);

		if (!cola->salida) 
			cola->entrada = NULL;
	}
}

/* Eliminar cola completa */

void destruirCola(Cola * cola) {

	while (cola->salida) {
		eliminar(cola);
	}

	free(cola);
}