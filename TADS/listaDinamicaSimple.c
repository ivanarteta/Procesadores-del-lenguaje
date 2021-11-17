void nuevaLista(tipoLista *l){
	l->ini = NULL;
	l->fin = NULL;
}

void insertar(tipoLista *l, tipoElementoLista e){ 
	celdaLista *celda;
	celda = (celdaLista*)malloc(sizeof(celdaLista));
    celda->elem = e;
	if (esNulaLista(*l)){
        celda->sig = NULL;
        l->ini = celda;
        l->fin = celda;
    }else{
        celda->sig = NULL;
		celda->ant = l->fin;
		celda->ant->sig = celda;
		l->fin = celda;
    }
}