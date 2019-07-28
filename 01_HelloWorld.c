#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct Client {
    char Name[20];
    char Id[10];
    float Credit; // 4 bytes en win 32
    char Addres[100];
};

int main(int argc, char const *argv[]) {
    struct Client cliente1 = {0}; // Inicializo todos los valores como 0;
    strcpy(cliente1.Name, "Nombre de Cliente 1");
    strcpy(cliente1.Id, "0000000001");
    strcpy(cliente1.Addres, "Direccion de Cliente 1");
    cliente1.Credit = 1000000;

    printf("\t- Name: %s,\n", cliente1.Name);
    printf("\t- Id: %s,\n", cliente1.Id);
    printf("\t- Address: %s,\n", cliente1.Addres);
    printf("\t- Credit: %f.\n", cliente1.Credit);

    return 0;
}

