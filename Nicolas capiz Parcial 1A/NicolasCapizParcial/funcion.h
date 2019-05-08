#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct {

    char nombre[32];
    char apellido[32];
    EFecha fechaAsociado;
    int estado;
    int codigoSocio;
    char sex;
    int telefono;
    char email[32];

}ESocio;

typedef struct{
    int codigoAutor;
    char apellido[32];
    char nombre[32];
}EAutor;

typedef struct{
    int codigoLibro;
    char titulo[51];
    int codigoAutor;
}ELibro;

typedef struct{
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    EFecha  fechaDePrestamo;
}EPrestamo;



void bajaSocio(ESocio lista[], int tam);
void nuevoVector(ESocio lista[], int tam);
void recorridoCero(ESocio lista[], int tam);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ESocio lista[],int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarCodigo(ESocio lista[], int CODIGO,int tam);
int esTelefono(int telefono);
int esSoloLetras(char str[]);
int esNumerico(int str[]);
int validarEmail(char email[]);
int validarFecha(EFecha fecha);

void estadoCero(ESocio lista[], int tam);
void altaSocio(ESocio lista[], int tam);
void mostrarSociosTotal(ESocio lista[], int tam);
#endif // FUNCIONES_H_INCLUDED
