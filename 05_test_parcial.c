#include "04_LinkedList.c"

/**
 * Defina la funcion que recibe como parametro dos listas ordenadas de numeros enteros.
 * Como resultado retorna la lista ordenada que resulta de combinar, las listas pasadas por parametro.
 * Declaracion: Nodo* merge(Nodo* c1, Nodo* c2)
 * Funciones Auxiliares:
 *  void insertar(Nodo **, Nodo*)
 *  Nodo * newNodo(int) ==> Aca es enQueue
 */

struct LinkedList* merge(const struct LinkedList* c1, const struct LinkedList* c2);

int main(int argc, char const *argv[]) {
    struct LinkedList* lista1 = newLinkedList();
    struct LinkedList* lista2 = newLinkedList();
    enQueue(lista1, 10);
    enQueue(lista1, 20);
    enQueue(lista1, 30);
    enQueue(lista2, 15);
    enQueue(lista2, 25);
    enQueue(lista2, 35);

    struct LinkedList* listaOrdenada = merge(lista1, lista2);

    printf("\t-Lista 1: \n");
    showAllLinkedList(lista1);
    printf("----------------------------\n");
    printf("\t-Lista 2: \n");
    showAllLinkedList(lista2);
    printf("----------------------------\n");
    printf("\t-Lista Ordenada: \n");
    showAllLinkedList(listaOrdenada);
    printf("----------------------------\n");

    return 0;
} 

// Este merge, crea una nueva lista en memoria. No utiliza los punteros a las listas por parametro. De ese modo se podrian borrar en el futuro.
struct LinkedList* merge(const struct LinkedList* c1, const struct LinkedList* c2) {
    struct LinkedList* listaOrdenada = newLinkedList();
    struct Node* firstC1 = c1->front;
    struct Node* firstC2 = c2->front;

    while(firstC1 != NULL && firstC2 != NULL) {
        if (firstC1->value <= firstC2->value) {
            // Haciendo esto de aca abjo, estaria agregando los mismos elementos que envio por parametro si ncrear memoria nueva
            //listaOrdenada->tail->next = firstC1;
            //listaOrdenada->tail = listaOrdenada->tail->next;
            enQueue(listaOrdenada, firstC1->value);
            firstC1 = firstC1->next;
        } else {
            enQueue(listaOrdenada, firstC2->value);
            firstC2 = firstC2->next;
        }
    }

    if (firstC1 != NULL) {
        enQueue(listaOrdenada, firstC1->value);
        firstC1 = firstC1->next;
    }

    if (firstC2 != NULL) {
        enQueue(listaOrdenada, firstC2->value);
        firstC2 = firstC2->next;
    }

    // TODO: Falta agregar control para cuando una lista es mas corta que otro.
    return listaOrdenada;
}