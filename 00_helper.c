#include<stdio.h> // Para imprimir en pantalla
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// const char *__restrict mensaje, ...
void imprimirError() {
    printf(ANSI_COLOR_RED     "ERROR: "     ANSI_COLOR_RESET);
}

void imprimirInfo() {
    printf(ANSI_COLOR_BLUE     "INFO: "     ANSI_COLOR_RESET);
}

void imprimirOk() {
    printf(ANSI_COLOR_GREEN     "OK: "     ANSI_COLOR_RESET);
}