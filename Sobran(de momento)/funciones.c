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
    strcpy(s, "a , b,c : entero;\n f,d: booleano;\n aux: real;\n");
    //linea
    char* linea = strtok(s,"\n");
    char* resto = strtok(NULL,"");
    while(resto){
        //Quitar semicolon
        while(strstr(linea, ";")){
            borraChar(linea, ';');
        }
        //Split por nombres/tipo
        char* token = strtok(linea, ":");
        char* tipo = strtok(NULL, ":");
        //Quitar espacios
        while(strstr(token, " ")){
            borraChar(token, ' ');
        }
        printf("token: %s\n", token);
        //lista ids
        char* identificadores = strtok(token, ",");
        
        printf("tipo: %s\n",tipo);

        while(identificadores){
            printf("id: %s\n", identificadores);
            identificadores = strtok(NULL, ",");
        }
        linea = strtok(resto,"\n");
        resto = strtok(NULL,"");
    }

    while(strstr(linea, ";")){
        borraChar(linea, ';');
    }
    //Split por nombres/tipo
    char* token = strtok(linea, ":");
    char* tipo = strtok(NULL, ":");
    //Quitar espacios
    while(strstr(token, " ")){
        borraChar(token, ' ');
    }
    printf("token: %s\n", token);
    //lista ids
    char* identificadores = strtok(token, ",");
    printf("tipo: %s\n",tipo);
    while(identificadores){
        printf("id: %s\n", identificadores);
        identificadores = strtok(NULL, ",");
    }

    return 0;
    

}