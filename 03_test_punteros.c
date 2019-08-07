#include "00_helper.c"
#include<stdlib.h>

struct Nodo {
    int valor;
    int id;
    int haySgt;
    struct Nodo *sgt;
};

void printDataNodo(const struct Nodo *nodo);

int main(int argc, char const *argv[]) {
    struct Nodo head;
    struct Nodo *tail = &head;

    int valor = 0;

    // Antes pedia en un do, while peeero en mi desesperacion probé limitarlo.
    for (int i = 0; i < 5; i++) {
        printf("---Ingrese el valor nº %d: ", i);
        scanf("%d", &valor);

        tail->valor = valor;
        tail->id = i;
        
        if ((i+1) < 5) {
            tail->haySgt = 1;
            tail = (struct Nodo*) &tail->sgt;
            tail->sgt = malloc(sizeof(struct Nodo));
        } else {
            tail->haySgt = 0;
            tail->sgt = NULL;
        }
    }


    struct Nodo *actual = &head;
    int contador = 0;
    printf("\t| VALUE\t\t|   ID\t|   SIGUIENTE\t|\n");
    while(actual != NULL) {
        printDataNodo(actual);
        
        if (actual->haySgt) {
            actual = (struct Nodo*) &actual->sgt;
        } else {
            actual = NULL;
        }
    }

    // Esto nunca se ejecuta...
    printf("Fin del programa");

    return 0;
} 

void printDataNodo(const struct Nodo *nodo) {
    printf("\t| Valor: %d ", nodo->valor);
    printf("\t| Id: %d", nodo->id);
    printf("\t| Sgt: ");
    if (nodo->haySgt) {
        printf(ANSI_COLOR_GREEN "True\t" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "False\t" ANSI_COLOR_RESET);
    }
    printf("|\n");
}