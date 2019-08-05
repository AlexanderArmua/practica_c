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
    int contador = 0;
    do {
        printf("Ingrese el valor nº %d: ", ++contador);
        scanf("%d", &valor);

        if (valor) {
            tail->valor = valor;
            tail->id = contador;
            tail->haySgt = 1;
            tail->sgt = malloc(sizeof(struct Nodo));

            tail = (struct Nodo*) &tail->sgt;
        } else {
            tail->haySgt = 0;
        }

    } while(valor);

    struct Nodo *actual = &head;
    while(actual->haySgt) {
        printf("\t- Valor: %d \t Id: %d\n", actual->valor, actual->id);
        actual = (struct Nodo*) &actual->sgt;
    }

    return 0;
} 