#include "listaCircularDobleOrdenada.h"
#include <stdlib.h>
#include <stdio.h>
void errorLista(char s[]){
	printf("\n\n\nERROR en el modulo listas:  %s\n", s);
	while (true)
		exit(-1);
}

void nuevaLista(tipoLista *l){
	l->ini = NULL;
	l->fin = NULL;
}

void insertar(tipoLista *l, tipoElementoLista e){ 
	celdaLista *celda;
	celda = (celdaLista*)malloc(sizeof(celdaLista));
    celda->elem = e;
	if (esNulaLista(*l)){
        celda->sig = celda;
        celda->ant = celda;
        l->ini = celda;
        l->fin = celda;
    }else{
        celdaLista *aux;
        aux = l->ini;
        while (aux->elem < e && aux->sig != l->ini){
			aux = aux->sig;
		}
		if (aux->elem == e){
			printf("El elemento ya existe en la lista\n");
		}else{
			if(aux->elem < e && aux->sig == l->ini){
				celda->sig = l->ini;
				celda->ant = l->fin;
				celda->ant->sig = celda;
				l->fin = celda;
			}else{
				celda->sig = aux;
				celda->ant = aux->ant;
				if(aux == l->ini){
					aux->ant = celda;
					l->ini = celda;
				}else{
					aux->ant->sig = celda;
					aux->ant = celda;
				}
			}
    	}
	}
}

void eliminarMenor(tipoLista *l){
	if(esNulaLista(*l)){
		printf("La lista esta vacia\n");
	}else{
		celdaLista *aux;
		aux = l->ini;
		if (l->ini == l->fin){
			free(aux);
			l->ini = NULL;
			l->fin = NULL;
		}else {
			aux->sig->ant = l->fin;
    		(l -> fin) -> sig = aux -> sig;
    		l -> ini = aux -> sig;
			free(aux);
		}
		
	}
}

void eliminarMayor(tipoLista *l){
	if(esNulaLista(*l)){
		printf("La lista esta vacia\n");
	}else{
		celdaLista *aux;
		aux = l->fin;
		if (l->ini == l->fin){
			free(aux);
			l->ini = NULL;
			l->fin = NULL;
		} else{
			(aux -> ant) -> sig = l -> ini;
    		(l -> ini) -> ant = aux -> ant;
    		l -> fin = aux -> ant;
			free(aux);
		}
	} 
}

tipoElementoLista consultarMenor(tipoLista l){
	return l.ini->elem;
}

tipoElementoLista consultarMayor(tipoLista l){
	return l.fin->elem;
}

bool estaElemento(tipoLista l, tipoElementoLista e){
    if (esNulaLista(l)) {
        printf("La lista esta vacia\n");
        return false;
    }else{
		celdaLista *aux;
    	aux = l.ini;
    
		if (aux->elem == e){
			return true;
		}else{
			while (aux->elem != e && aux->sig != NULL){
				aux = aux->sig;
			}
			if (aux->elem != e)
				return false;
			else
				return true; 
		}
	}
    

}

bool esNulaLista(tipoLista l){
	return ((l.ini == NULL) & (l.fin ==NULL));
}

void concatenar(tipoLista *l1, tipoLista *l2)
{
    if (esNulaLista(*l1) || esNulaLista(*l2))
        printf("Alguna o ambas listas estan vacias\n");

    else
    {
		while (!esNulaLista(*l2))
		{
			tipoElementoLista e = consultarMenor(*l2);
			insertar(l1, e);
			eliminarMenor(l2);
		}
	}
}

//Funciona bien
/*void imprimirLista (tipoLista l){
	celdaLista *aux;
	aux = l.ini;
	while(aux->ant){
		aux = aux->ant;
	}
	while(aux){
		printf("%d ",aux->elem );
		aux = aux->sig;
	}
	printf("\n");
}*/

void imprimirLista(tipoLista l) {

    if(esNulaLista(l)) {
        printf("La lista esta vacia!\n");
    } else {
        celdaLista *aux;
        aux = (l.ini);
        while(aux != l.fin) {
            printf("%d ", (aux -> elem));
            aux = aux -> sig;
        }

        printf("%d ", (aux -> elem));

        printf("\n");
    }

}
