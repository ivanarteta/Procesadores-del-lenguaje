#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaCuadruplas.h"

//Funciones de la tabla
void iniciarTC(tC *t){
    t->nextquad = 0;
}

void gen(int opr, int op1 ,int op2 ,int sol, tC *t){ 
	t->cuadruplas[t->nextquad][0] = opr;
    t->cuadruplas[t->nextquad][1] = op1;
    t->cuadruplas[t->nextquad][2] = op2;
    t->cuadruplas[t->nextquad][3] = sol;
    t->nextquad++;
}

//Mostrar la tabla por cuadruplas
void imprimirTablaCuadruplas(tC t){
    for (int i=0;i<t.nextquad;i++){
        printf("Fila %d, valores: %d, %d, %d, %d\n",i,t.cuadruplas[i][0],t.cuadruplas[i][1],t.cuadruplas[i][2],t.cuadruplas[i][3]);
    }
}

 /*void makelist(){
}

void merge(){
}

void backpatch(){
	
}*/

