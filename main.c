#include <stdio.h>
#include <stdlib.h>

typedef struct Amigo {
    char apellido[50];
    char nombre[50];
    int num;
} Amigo;

typedef struct Nodo {
    Amigo amigo;
    struct Nodo * next;
} Nodo;

typedef struct Lista {
    
};

