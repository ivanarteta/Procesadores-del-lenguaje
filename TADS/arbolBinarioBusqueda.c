void nuevoArbolBB(tipoArbolBB *a){
	*a = NULL;
}

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda elemento){
	celdaArbolBusqueda *nuevo;
	nuevo = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
	nuevo->elem = elemento;
	if(esVacio(*a)){
		nuevo->izda = NULL;
		nuevo->dcha = NULL;
		*a = nuevo;
	}else{
		if((*a)->elem == elemento){
			printf("Ya existe ese elemento \n");
		}else if((*a)->elem > elemento){
			insertar((*a)->izda, elemento);
		}else{
			insertar((*a)->dcha, elemento);
		}
	}
}

void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda elemento){
	if(esVacio(*a)){
		printf("El arbol esta vacio por lo que no puedes borrar nada\n");
	}else{
		if((*a)->elem > elemento){
			borrar(&(*a)->izda, elemento);
		}else if((*a)->elem < elemento){
			borrar(&(*a)->dcha, elemento);
		}else if((*a)->elem == elemento){
			if((*a)->izda == NULL && (*a)->dcha == NULL){
				*a = NULL;
				free(*a);
			}else if((*a)->izda != NULL && (*a)->dcha == NULL){
				(*a) = (*a)->izda;
			}else if((*a)->izda == NULL && (*a)->dcha != NULL){
				(*a) = (*a)->dcha;
			}else if((*a)->izda != NULL && (*a)->dcha != NULL){
				tipoArbolBB *aux;
				aux = *a;
				while(aux->izda != NULL){
					aux = aux->izda;
				}
				(*a)->elem = aux->elem;
				borrar(&(*a)->dcha, aux->elem);
			}
		}
	}
}

void mostrarPreorden(tipoArbolBB);

void mostrarInorden(tipoArbolBB);

void mostrarPostorden(tipoArbolBB);

bool esVacio(tipoArbolBB);