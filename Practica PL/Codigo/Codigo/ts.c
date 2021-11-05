#include "ts.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void inicializar_TS(struct FILA_TS** cabeza, struct FILA_TS** cola) {
  struct FILA_TS* nueva;
  nueva = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
  nueva->nombre = NULL;
  nueva->tipo = -1; /* Redundante porque luego se sobrescribe pero bueno */
  nueva->p = NULL;
  (*cabeza) = nueva;
  (*cola) = nueva;
}

struct FILA_TS* insertar_id_TS(char* nombre, enum enum_tipo tipo, struct FILA_TS** ultimo) {
    if ((*ultimo)->nombre == NULL) {
      (*ultimo)->nombre = strdup(nombre);
      (*ultimo)->tipo = tipo;
      (*ultimo)->p = NULL;
      (*ultimo)->id = 0;
      return *ultimo;
    } else {
      struct FILA_TS* nueva;
      nueva = (struct FILA_TS*) malloc(sizeof(struct FILA_TS));
      if(strcmp(nombre,"-") == 0){
          char x[10];
          sprintf(x, "%d", (*ultimo)->id + 1);
          nueva->nombre = strdup(x);
          
      }else{
          nueva->nombre = strdup(nombre);
      }
      nueva->tipo = tipo;
      nueva->p = NULL;
      (*ultimo)->p = nueva;
      nueva->id = (*ultimo)->id + 1;
      (*ultimo) = nueva;
      return *ultimo;
    }
}

int TS_consultar_id(char* nombre, struct FILA_TS* cabeza){
    while (cabeza->p != NULL && strcmp(nombre,cabeza->nombre) != 0) {
        cabeza = cabeza->p;
    }
    //Sale porque ha encontardo el nombre.
    if(strcmp(nombre,cabeza->nombre) == 0){
        return cabeza->id;
    // Sale porque ya no hay más filas
    }else{
        //Error no se ha encontardo esa variable.
        return -1;
    }
}

char* TS_consultar_nombre(int id, struct FILA_TS* cabeza) {
    while (cabeza->p != NULL && id!=cabeza->id) {
        cabeza = cabeza->p;
    }
    //Sale porque ha encontardo el id.
    if(id==cabeza->id){
        if ((int)cabeza->nombre[0] >= 48 && (int)cabeza->nombre[0] <= 57) {
            char* nombre;
            nombre = strdup("_TEMP_");
            return strcat(nombre, cabeza->nombre);
        } else {
            return cabeza->nombre;
        }
    // Sale porque ya no hay más filas
    }else{
        //Error no se ha encontardo esa variable.
        return "_ERR_";
    }
}

enum enum_tipo TS_consultar_tipo(int id, struct FILA_TS* cabeza){
    while (cabeza->p != NULL && (cabeza->id != id)) {
        cabeza = cabeza->p;
    }
    //Sale porque ha encontardo el id.
    if(cabeza->id == id){
        return cabeza->tipo;
    // Sale porque ya no hay más filas
    }else{
        //Error no se ha encontardo esa variable con esa id.
        return TIPO_ERROR;
    }
    
    
}

int TS_crear_variable_temporal(struct FILA_TS** ultimo){
    // No incilizamos valores de tipo ni nombre. Los dejamos "vacios".
    // Generar un nombre que no se haya metido: 
    //podemos utilizar el id como nombre, ya que el usuario nunca pondrá como nombre un numero ya que no está permitido.
    // Le pasamos "-" para que sepa la funcion insertar que tiene que generar un nombre con el id corresodiente.
    
    struct FILA_TS* fila_creada;
    fila_creada = insertar_id_TS("-", TIPO_ERROR, ultimo);
    return fila_creada->id;
}

int TS_modificar_tipo(struct FILA_TS** cabeza, int id, enum enum_tipo tipo){
    struct FILA_TS* cabeza_aux;
    cabeza_aux = (*cabeza);
    while (cabeza_aux->p != NULL && (cabeza_aux->id != id)) {
        cabeza_aux = cabeza_aux->p;
    }
    //Sale porque ha encontardo el id.
    if(cabeza_aux->id == id){
        cabeza_aux->tipo = tipo;
        return 1;
    // Sale porque ya no hay más filas
    }else{
        //Error no se ha encontardo esa variable con esa id.
        return -1;
    }
}

void guardar_TS(char* ruta, struct FILA_TS* cabeza, int errorFlag) {
    FILE* f = fopen(ruta, "w");
    if (errorFlag == 1) {
        fprintf(f, "Se ha producido un error en la compilación, por lo que la tabla de símbolos puede no haberse generado correctamente.\n");
        fprintf(f, "Consulte la salida para obtener más información sobre el error.\n\n");
    }
    fprintf(f, "Tipos:\n");
    for (int i=TIPO_ENTERO; i<=TIPO_CADENA; i++) {
        switch (i) {
            case TIPO_ENTERO:
                fprintf(f, "%d\t\tEntero\n", i);
                break;
            case TIPO_REAL:
                fprintf(f, "%d\t\tReal\n", i);
                break;
            case TIPO_BOOLEANO:
                fprintf(f, "%d\t\tBooleano\n", i);
                break;
            case TIPO_CARACTER:
                fprintf(f, "%d\t\tCaracter\n", i);
                break;
            case TIPO_CADENA:
                fprintf(f, "%d\t\tCadena\n", i);
                break;
        }
    }
    fprintf(f, "--------------------------------------------------\n\n");
    fprintf(f, "ID\t\t\tNombre\t\t\tTipo\n");
    if (cabeza->nombre != NULL){
        while (cabeza->p != NULL) {
            fprintf(f, "%d\t\t\t%s\t\t\t%d\n", cabeza->id, cabeza->nombre, cabeza->tipo);
            cabeza = cabeza->p;
        }
        // Cuando apunta a NULL quiere decir que es la última fila de la tabla, pero también hay que escribirla
        fprintf(f, "%d\t\t\t%s\t\t\t%d\n", cabeza->id, cabeza->nombre, cabeza->tipo);
    }
    fclose(f);
}
