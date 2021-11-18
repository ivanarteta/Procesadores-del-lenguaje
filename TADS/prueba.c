#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilaDinamica.h"

int main(){
    tipoPila pila;
    nuevaPila(&pila);
    apilar(&pila, "aux");
    apilar(&pila, "i");
    apilar(&pila, "var");
    while (!esNulaPila(pila)) {
        char* identificador = cima(pila);
        desapilar(&pila);
        printf("identificador: %s \n", identificador);
    }

}