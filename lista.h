#ifndef _LISTA_H_
#define _LISTA_H_

#include "includes.h"

// -----------------------------------------
//
//    Operaciones con Listas
//
// -----------------------------------------

// -- Inserción

void insertarPrincipio(Lista * lista, Amigo * amigo) {
    Nodo * nodo = crearNodo(amigo);
    
    nodo->sgte = lista->inicio;
    lista->inicio = nodo;
    lista->longitud++;
}

void insertarFinal(Lista * lista, Amigo * amigo) {
    Nodo * nodo = crearNodo(amigo);

    if (lista->inicio == NULL) {
        
        lista->inicio = nodo;
        lista->longitud++;

    } else {

        Nodo * p = lista->inicio;

        while (p->sgte) {
            p = p->sgte;
        }

        p->sgte = nodo;
        lista->longitud++;
    }
}

void insertarDespues(int n, Lista * lista, Amigo * amigo) {
    Nodo * nodo = crearNodo(amigo);

    if (lista->inicio == NULL) {
        
        lista->inicio = nodo;
        lista->longitud++;
    
    } else {

        Nodo * p = lista->inicio;
        
        int i = 0;
        while (i < n && p->sgte) {
            p = p->sgte;
            i++;
        }

        nodo->sgte = p->sgte;
        p->sgte = nodo;
        lista->longitud++;    
    }
}

// -- Manipulación situacional

Amigo * obtener(int n, Lista * lista){
    if (lista->inicio == NULL) {
        
        return NULL;
    
    } else {

        Nodo * p = lista->inicio;

        int i = 0;
        while (i < n && p->sgte) {
            p = p->sgte;
            i++;
        }

        if (i != n) {

            return NULL;

        } else {
            
            return &p->amigo;
        
        }
    }
}

int cantidad(Lista * lista) {
    return lista->longitud;
}

int estaVacia(Lista * lista) {
    return lista->inicio == NULL;
}

// -- Eliminar

void eliminarUltimo( Lista * lista ) {

	if ( lista->inicio ) {

		if ( lista->inicio->sgte ) {

			Nodo * p = lista->inicio; 

			while ( p->sgte->sgte ) {
				p = p->sgte; 
			}

			Nodo * eliminado = p->sgte;
			p->sgte = NULL;
			destruirNodo(eliminado);
			lista->longitud--;

		} else { 

			Nodo * eliminado = lista->inicio;
			lista->inicio = NULL;
			destruirNodo(eliminado);
			lista->longitud--; 
	    }
    }
}

void eliminarElemento( int n, Lista * lista) {

	if ( lista->inicio ) {

		if ( n == 0 ) {

			Nodo * eliminado = lista->inicio; 
			lista->inicio = lista->inicio->sgte; 
			destruirNodo(eliminado);
			lista->longitud--;

		} else {

			Nodo * puntero = lista->inicio; 

			int posicion = 0;
			while (posicion < (n-1)) {
				puntero = puntero->sgte; 
				posicion++;
			}

			Nodo * eliminado = puntero->sgte; 
			puntero->sgte = eliminado->sgte; 
			destruirNodo(eliminado);
			lista->longitud--; 
		}
	}
}

#endif // _LISTA_H_