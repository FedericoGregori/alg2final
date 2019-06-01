#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------
//
//    Estructuras
//
// -----------------------------------------

typedef struct Amigo {
    char apellido[50];
    char nombre[50];
} Amigo;

typedef struct Nodo {
    Amigo amigo;
    struct Nodo * next;
} Nodo;

typedef struct Lista {
    Nodo * head;
} Lista;


// -----------------------------------------
//
//    Operaciones con Nodos
//
// -----------------------------------------

Nodo * crearNodo(Amigo * amigo) {
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));

    strncpy(nodo->amigo.apellido, amigo->apellido, 50);
	strncpy(nodo->amigo.nombre, amigo->nombre, 50);
	
    nodo->next = NULL;

    return nodo;
}

void destruirNodo(Nodo * nodo) {
    free(nodo);
}

// -----------------------------------------
//
//    Operaciones con Listas
//
// -----------------------------------------

