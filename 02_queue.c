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
    - ```enqueue()``` (Nuevo elemento al final)             -- OK
    - ```dequeue()``` (Remover y retornar primer elemento)  -- OK
    - ```peek()``` (Primer elemento sin removerlo)          -- OK
    - ```size()```                                          -- OK
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

void enqueue(int value) {
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

int dequeue() {
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

int peek() {
    if (noFueIniciada()) {
        imprimirError();
        printf("No hay elementos para obtener.\n");
    } else {
        imprimirInfo();
        const int primerElemento = elementos[front];
        printf("Se toma el primer elemento sin eliminar %d\n", primerElemento);
        return primerElemento;
    }
}

int size() {
    int size;
    if (rear == -1) {
        size = 0;
    } else if (rear == 0) {
        size = 1;
    } else {
        size = (rear - front) + 1;
    }

    imprimirInfo();
    printf("El tamaño es %d\n", size);
    
    return size;
}

int main(int argc, char const *argv[])
{
    size();
    enqueue(1);
    size();
    enqueue(1);
    size();
    enqueue(1);
    size();
    enqueue(2);
    size();
    enqueue(3);
    size();
    enqueue(4);
    size();
    enqueue(5);
    size();
    dequeue();
    size();
    enqueue(6);
    size();
    dequeue();
    peek();
    peek();
    peek();
    size();
    return 0;
}
