#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;

}eEmpleado;

int main()
{
    eEmpleado unEmpleado;

    unEmpleado.legajo = 1234;
    unEmpleado.sueldo = 10000.13;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';

    printf("ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &unEmpleado.sexo);
    system("cls");

    printf("Nombre\tLegajo\tSueldo\t\tSexo\n\n");
    printf("-------------------------------------------\n");
    printf("%s\t%d\t$%.2f\t%c\n", unEmpleado.nombre, unEmpleado.legajo, unEmpleado.sueldo, unEmpleado.sexo);


}

