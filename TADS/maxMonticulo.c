void nuevoMaxMonticulo(tipoMaxMonticulo*m,int numero){
	m->array = (tipoElementoMaxMonticulo*)malloc(sizeof(tipoElementoMaxMonticulo*numero));
	m->pos = -1;
	m->numEl = numero;
}

void insertarMaxMonticulo(tipoMaxMonticulo *m, tipoElementoMaxMonticulo elemento){
	if(esVacio){
		m->pos = 0;
		m->array[0] = elemento;
	}else{
		tipoMaxMonticulo *aux;
		aux = m;
		m->pos = m->pos+1;
		m->array[m->pos] = elemento;
		int posmodif = m->pos;
		while(posmodif != 0){
			if(aux->array[(posmodif-1)/2] > m->array[posmodif]){
				tipoElementoMaxMonticulo *aux2;
				aux2 = aux->array[(posmodif-1)/2];
				aux->array[(posmodif-1)/2] = aux->array[posmodif]
				aux->array[posmodif] = aux2;
				*m = aux;
			}
			posmodif = (posmodif-1)/2;
		}
	}
}

void eliminarElemento(tipoMaxMonticulo *m, tipoElementoMaxMonticulo elemento){
	if(esVacio(*m)){
		printf("error pork esta vacio\n");
	}else{
		tipoMaxMonticulo *aux;
		aux = m;
		int i = 0;
		while(aux->array[i] != elemento){
			i++;
		}
		aux->array[i] = m->array[m->pos];
		aux->array[aux->pos] = NULL;
		aux->pos = aux->pos -1;
		m = aux;

		while(i <= m->pos){
			if((2*(i+1)+1) <= m->pos){
				if(aux->array[(2*i)+1] > aux->array[2*(i+1)]){
					tipoMaxMonticulo *aux2;
					aux2 = aux->array[(2*i)+1];
					aux->array[(2*i)+1] = aux->array[i];
					aux->array[i] = aux2;
					*m = aux;
				}
				if(aux->array[(2*i)+1] < aux->array[2*(i+1)]){
					tipoMaxMonticulo *aux2;
					aux2 = aux->array[2*(i+1)];
					aux->array[2*(i+1)] = aux->array[i];
					aux->array[i] = aux2;
					*m = aux;
				}
			}
			i = 2*(i+1);

		}

	}
}