#include "00_helper.c"
#include<stdlib.h>

struct LinkedList {
    struct Node *front;
    struct Node *tail;
};

struct Node {
    int value;
    unsigned int index;
    struct Node *next;
};

void printDataNodo(const struct Node *node);

int isEmpty(const struct LinkedList *list) {
    return list->front == NULL;
}

int getLastIndex(const struct LinkedList *list) {
    return list->tail->index;
}

struct LinkedList* newLinkedList() {
    struct LinkedList *temp = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    temp->front = NULL;
    temp->tail = NULL;

    return temp;
}

struct Node* newNode(const int value) {
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->value = value;
    
    return temp;
}

void enQueue(struct LinkedList *list, const int value) {
    struct Node* node = newNode(value);
    
    if (isEmpty(list)) {
        node->index = 0;
        list->front = node;
        list->tail = node;
        return;
    }

    node->index = getLastIndex(list) + 1;
    list->tail->next = node;
    list->tail = node;
}

struct Node* deQueue(struct LinkedList *list) {
    if (isEmpty(list)) {
        return NULL;
    }

    struct Node* firstElement = list->front;
    list->front = firstElement->next;

    if (isEmpty(list)) {
        list->tail = NULL;
    }

    return firstElement;
}

int deQueueValue(struct LinkedList *list) {
    struct Node* deQueued = deQueue(list);
    int const valueReturn = deQueued->value;
    free(deQueued);

    return valueReturn;
}

struct Node* peek(const struct LinkedList *list) {
    if (isEmpty(list)) {
        return NULL;
    }

    return list->front;
}

struct Node* getTail(const struct LinkedList *list) {
    return list->tail;
}

int size(const struct LinkedList *list) {
    if (isEmpty(list)) {
        return 0;
    }

    int length = 0;
    struct Node* elem = list->front;

    do {
        length++;
        elem = elem->next;
    } while(elem != NULL);

    return length;
}

void freeAll(struct LinkedList *list) {
    while (list->front != NULL) {
        free(deQueue(list));
    }

    free(list);
}

/*
int main(int argc, char const *argv[]) {
    struct LinkedList* list1 = newLinkedList();
    
    return 0;
}*/

void callToAddNumbers(struct LinkedList* lista) {
    int index = 0;
    int value = 0;
    do {
        printf("--- Write the number Nº %d: ", ++index);
        scanf("%d", &value);
        if (value) {
            enQueue(lista, value);
        }
    } while(value);
}

void showAllLinkedList(struct LinkedList* lista) {
    struct Node* deQueued; 
    do {
        deQueued = deQueue(lista);
        printDataNodo(deQueued);
        free(deQueued);
    } while(deQueued->next);
}

void callWhatDoYouWant(struct LinkedList* lista) {
    int value = 0;
    int index = 0;
    struct Node* deQueued; 
    int opcion = 0;
    do {
        printf("Choose: \n");
        printf("\t-00: exit\n");
        printf("\t-01: peek\n");
        printf("\t-02: deQueue\n");
        printf("\t-03: enQueue\n");
        printf("\t-04: deQueueAll\n");
        printf("\t-05: size\n");
        printf("¿What do you want?:\t");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printDataNodo(peek(lista));
                break;
            case 2:
                deQueued = deQueue(lista);
                printDataNodo(deQueued);
                free(deQueued);
                break;
            case 3:
                printf("--- Write the number Nº %d: ", ++index);
                scanf("%d", &value);
                if (value) {
                    enQueue(lista, value);
                }
                break;
            case 4:
                showAllLinkedList(lista);
                break;
            case 5:
                printf("- Size: %d\n", size(lista));
                break;
            default:
                freeAll(lista);
                break;
        }

    } while (opcion);
}

void printDataNodo(const struct Node *node) {
    if (node == NULL) {
        return;
    }
    printf("\t| Valor: %d ", node->value);

    printf("\t| Id: ");
    if (node->index < 10) {
        printf("0");
    }
    printf("%d", node->index);

    printf("\t\t| Sgt: ");
    if (node->next != NULL) {
        printf(ANSI_COLOR_GREEN "True\t" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "False\t" ANSI_COLOR_RESET);
    }
    printf("|\n");
}
