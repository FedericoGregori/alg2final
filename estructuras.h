#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_

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
    struct Nodo * sgte;
} Nodo;

typedef struct Lista {
    Nodo * inicio;
    int longitud;
} Lista;

#endif // _ESTRUCTURAS_H_