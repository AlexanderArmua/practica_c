#include<stdio.h>
#include<stdlib.h>

struct Nodo {
    int valor;
    int id;
    int haySgt;
    struct Nodo *sgt;
};

int main(int argc, char const *argv[]) {
/*
    int valorA = 20;
    int *pValorA = &valorA;

    struct Nodo *pila;

    pila->valor = 1;
    pila->sgt = malloc(sizeof(struct Nodo));

    pila->sgt->valor = 2;

    printf("Valor 01: %d \n", pila->valor);
    printf("Valor 02: %d \n", pila->sgt->valor);
*/
    struct Nodo head;
    struct Nodo *tail = &head;

    int valor = 0;

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
    printf("\t| VALUE\t\t|   ID\t|   SIGUIENTE\t|\n");
    while(actual != NULL) {
        printf("\t| Valor: %d ", actual->valor);
        printf("\t| Id: %d", actual->id);
        printf("\t| Sgt: ");
        if (actual->haySgt) {
            printf("True\t|\n");
        } else {
            printf("False\t|\n");
        }
        
        if (actual->haySgt) {
            actual = (struct Nodo*) &actual->sgt;
        } else {
            actual = NULL;
        }
    }

    printf("Fin del programa");

    return 0;
} 