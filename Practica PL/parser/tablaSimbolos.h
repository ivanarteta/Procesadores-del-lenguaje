#ifndef DPIS_TS_H
#define DPIS_TS_H

	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	
#define TENTERO -1
#define TREAL -2
#define TBOOLEANO -3
#define TCARACTER -4
#define TCADENA -5
#define TREF -6
#define TIDENTIFICADOR -7
#define TSUBRANGO -8


  
typedef struct celda{
	char* nombre;
	int type;
	int id;
	struct celda *sig,*ant; 
} celda;
        
typedef struct lista{
	struct celda *primero, *ultimo;
    int cont;
}lista;	

void iniciarTS(lista *l);
bool vacia(lista l);
int insertarElemento(lista *l, celda* nuevo);
celda* buscarElemento(lista l, int idE);
celda* buscarT(lista l, char* nombre);
void modifica_tipo_TS(lista* l, int id, int tipo);
void imprimirTablaSimbolos(lista l);
int newTemp(lista* l, char* nombre);

	
#endif

