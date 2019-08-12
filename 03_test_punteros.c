#include "00_helper.c"
#include<stdlib.h>

struct Nodo {
    int valor;
    unsigned int id;
    int haySgt;
    struct Nodo *sgt;
};

void printDataNodo(const struct Nodo *nodo);

int main(int argc, char const *argv[]) {
    struct Nodo *head = malloc(sizeof(struct Nodo)); //= {0, 0, 0, NULL};
    head->valor = 0;
    head->id = 0;
    head->haySgt = False;
    head->sgt = NULL;

    struct Nodo *tail = head;

    int valor = 0;

    unsigned int id = 0;
    do {
        printf("---Ingrese el valor nº %d: ", ++id);
        scanf("%d", &valor);

        // Corte del do-while
        if (!valor) {
            tail->haySgt = False;
            tail->sgt = NULL;
            break;
        }

        if (tail->id) {
            tail->haySgt = True;
            tail->sgt = malloc(sizeof(struct Nodo));
            
            tail = tail->sgt;
            tail->haySgt = False;
        }
        
        tail->id = id; // 01
        tail->valor = valor; // 1
    } while(valor);

    struct Nodo *actual = head;
    int contador = 0;
    printf("\t| VALUE\t\t|   ID\t\t|   SIGUIENTE\t|\n");
    while(actual != NULL) {
        printDataNodo(actual);

        if (actual->haySgt) {
            struct Nodo *sgt = actual->sgt;
            actual = (struct Nodo*) sgt;
            //free(sgt);
        } else {
            // actual = NULL;
            break;
        }
    }

    // Esto nunca se ejecuta...
    printf("Fin del programa.\n");

    return 0;
} 

void printDataNodo(const struct Nodo *nodo) {
    printf("\t| Valor: %d ", nodo->valor);

    printf("\t| Id: ");
    if (nodo->id < 10) {
        printf("0");
    }
    printf("%d", nodo->id);
    printf("\t\t| Sgt: ");
    if (nodo->haySgt) {
        printf(ANSI_COLOR_GREEN "True\t" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "False\t" ANSI_COLOR_RESET);
    }
    printf("|\n");
}