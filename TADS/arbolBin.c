void nuevoArbolBin(tipoArbolBin *a){
	*a = NULL;
}

tipoArbolBin construir(tipoElementoArbolBin elemento, tipoArbolBin izq, tipoArbolBin der){
	tipoArbolBin *nuevo;
	nuevo = (tipoArbolBin*)malloc(sizeof(tipoArbolBin));
	nuevo->elem = elemento;
	nuevo->izda = izq;
	nuevo->dcha = der;
	return nuevo;
}

tipoElementoArbolBin devolverRaiz(tipoArbolBin a){
	return a->elem;
}

void preorden(tipoArbolBin a){
	printf("%d",a->elem);
	preorden((*a)->izda);
	preorden((*a)->dcha);
}

void inorden(tipoArbolBin a){
	preorden((*a)->izda);
	printf("%d",a->elem);
	preorden((*a)->dcha);
}

void postorden(tipoArbolBin a){
	preorden((*a)->izda);
	preorden((*a)->dcha);
	printf("%d",a->elem);
}