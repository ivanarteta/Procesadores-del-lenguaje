#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void borraChar(char *cadena, char elemento) {
    char *origen, *destino;
    for (origen = destino = cadena; *origen != '\0'; origen++) {
        *destino = *origen;
        if (*destino != elemento) destino++;
    }
    *destino = '\0';
}

void separar(char * lista){
    char* token = strtok(lista, ",");
    while (token) {
        while(strstr(token, " ")){
            borraChar(token, ' ');
        }
        printf("token: %s\n", token);
        token = strtok(NULL, ",");
    }
}

int main(){
    char s[256];
    strcpy(s, "a , b,c : entero");
    char* token = strtok(s, ":");
    while(strstr(token, " ")){
        borraChar(token, ' ');
    }
    printf("lista: %s\n", token);
    char* tipo = strtok(NULL, ":");
    while(strstr(tipo, " ")){
        borraChar(tipo, ' ');
    }
    printf("tipo: %s\n", tipo);
    // Aqui ya tenemos tipo

    ///

    char* identificador = strtok(token, ",");
    while (identificador) {
        printf("identificador: %s\n", identificador);
        // Aqui habria que ir metiendo los identificadores
        identificador = strtok(NULL, ",");
    }

}