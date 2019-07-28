/* 
    Pasos:
    1- Crear pointer para saber que hay en front y rear.
    2- Colocar todo en -1 al iniciar.
    3- Incrementar en 1 el valor de "rear" cuando se agrega elemento.
    4- Retornar el valor de front al quitar un elemento e incrementar 
    en 1 elvalor de front al usar dequeue.
    5- Antes de agregar un elemento revisar si hay espacio.
    6- Antes de remover un elemento revisar si existen elementos.
    7- Asegurarnos de que al remover todos los elementos resetear el 
    front y rear a -1 y agregar el valor de 0 a Front al hacer primer 
    enqueue

    Operaciones:
    - ```enqueue()``` (Nuevo elemento al final)
    - ```dequeue()``` (Remover y retornar primer elemento)
    - ```peek()``` (Primer elemento sin removerlo)
    - ```size()```
    - ```isEmpty()```
    - ```isFull()```
*/
#include "00_helper.c"
#define SIZE_QUEUE 5
#define VALUE_INIT -1

int rear = VALUE_INIT; // Posicion del ultimo elemento en la Queue
int front = VALUE_INIT; // Posicion primer elemento a tomar
int elementos[SIZE_QUEUE] = {VALUE_INIT};

int estaLlena() {
    return rear == SIZE_QUEUE - 1;
}

int noFueIniciada() {
    return front == VALUE_INIT;
}

void enQueue(int value) {
    // Si hay espacio, agregamos un elemento.
    if (estaLlena()) {
        // Esta lleno
        imprimirError();
        printf("El Queue está lleno, no se puede agregar elementos.\n");
    } else {
        if (noFueIniciada()) {
            // Es el primer elemento que se agrega a la queue, cambio el front.
            front = 0;
        }
        rear++;
        elementos[rear] = value;
        imprimirOk();
        printf("Se agrego el \"%d\" correctamente.\n", value);
    }
}

int deQueue() {
    if (noFueIniciada()) {
        imprimirError();
        printf("No hay elementos para obtener.\n");
    } else {
        const int primerElemento = elementos[front];
        imprimirInfo();
        printf("Se eliminó el valor \"%d\".\n", primerElemento);
        // El front es siempre 0, pero el ultimo elemento varia
        rear--;
        if (front > rear) {
            front = VALUE_INIT;
            rear = VALUE_INIT;
        }  else {
            for (int i = 0; i < SIZE_QUEUE - 1; i++) {
                elementos[i] = elementos[i + 1];
            }
        }
        
        return primerElemento;
    }
}

int main(int argc, char const *argv[])
{
    enQueue(1);
    enQueue(1);
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    deQueue();
    enQueue(6);
    deQueue();
    return 0;
}
