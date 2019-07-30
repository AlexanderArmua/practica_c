/* 
    Operations Done:
    - enqueue(int)
    - dequeue()
    - peek()   
    - size()   
    - isEmpty()
    - isFull() 
    
    Todo:
    - InitQueue (More than one Queue at the same time).
    - Change Array for Pointers
    - Change all the functions for Pointers
    - Resize
    - Free Memory
    - PrintMenu (It could be for all types)
    - Read data from keyboard.
    - Display all the Queue or all the Queues
*/
#include "00_helper.c"
#define SIZE_QUEUE 5
#define VALUE_INIT -1

int rear = VALUE_INIT;
int front = VALUE_INIT;
int elementos[SIZE_QUEUE] = {VALUE_INIT};

int itsNew();
void enqueue(int); 
int dequeue();
int peek();
int size();
int isEmpty();
int isFull();

int main(int argc, char const *argv[])
{
    return 0;
}

int itsNew() {
    return front == VALUE_INIT;
}

void enqueue(int value) {
    // Si hay espacio, agregamos un elemento.
    if (isFull()) {
        // Esta lleno
        imprimirError();
        printf("El Queue está lleno, no se puede agregar elementos.\n");
    } else {
        if (itsNew()) {
            // Es el primer elemento que se agrega a la queue, cambio el front.
            front = 0;
        }
        rear++;
        elementos[rear] = value;
    }
}

int dequeue() {
    if (itsNew()) {
        imprimirError();
        printf("No hay elementos para obtener.\n");
    } else {
        const int primerElemento = elementos[front];
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
    if (itsNew()) {
        imprimirError();
        printf("No hay elementos para obtener.\n");
    } else {
        const int primerElemento = elementos[front];
        return primerElemento;
    }
}

int size() {
    // front = -1 ; rear = -1 ; ==> 0 (Initlialized)
    // front = 0 ; rear = 0 ;   ==> 1 (First Element)
    // front = 0 ; rear = 1 ;   ==> 2
    // front = 0 ; rear = 2 ;   ==> 3
    // front = 0 ; rear = 3 ;   ==> 4
    // front = 0 ; rear = 4 ;   ==> 5

    int size;
    if (rear == -1) {
        size = 0;
    } else if (rear == 0) {
        size = 1;
    } else {
        size = (rear - front) + 1;
    }

    return size;
}

int isEmpty() {
    // 0 es false, != 0 es true.
    return size();
}

int isFull() {
    // const int espacioLibre = (SIZE_QUEUE - size());
    // (5 - 0) = 5 ==> return 0;
    // (5 - 1) = 4 ==> return 0;
    // (5 - 2) = 3 ==> return 0;
    // (5 - 3) = 2 ==> return 0;
    // (5 - 4) = 1 ==> return 0;
    // (5 - 5) = 0 ==> return 1; 
    
    return !(SIZE_QUEUE - size());
}
