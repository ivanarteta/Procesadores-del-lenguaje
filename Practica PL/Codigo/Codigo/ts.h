#ifndef TS_H
#define TS_H
#include "eaux.h"

    
struct FILA_TS {
    char*               nombre;
    enum enum_tipo      tipo;
    //int                 tipo;
    int                 id;
    /*int               ambito*/
    struct FILA_TS*     p; /* Puntero a la siguiente fila de la tabla */
};

void inicializar_TS(struct FILA_TS** cabeza, struct FILA_TS** cola);
struct FILA_TS* insertar_id_TS(char* nombre, enum enum_tipo tipo, struct FILA_TS** ultimo);
void guardar_TS(char* ruta, struct FILA_TS* cabeza, int errorFlag);
int TS_consultar_id(char* nombre, struct FILA_TS* cabeza);
char* TS_consultar_nombre(int id, struct FILA_TS* cabeza);
enum enum_tipo TS_consultar_tipo(int id, struct FILA_TS* cabeza);
int TS_crear_variable_temporal(struct FILA_TS** ultimo);
int TS_modificar_tipo(struct FILA_TS** cabeza, int id, enum enum_tipo tipo);
#endif

                                                