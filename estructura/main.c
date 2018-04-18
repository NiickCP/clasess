#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cant 100

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    char nombre[21];
    int legajo;
    float sueldo;
    char sexo;
    eFecha fn;
} eEmpleado;


int main()
{
    eEmpleado unEmpleado[cant];
    eEmpleado aux; //porque el auxiliar tiene que ser el mismo tipo de dato, es decir, estructura

    //eEmpleado unEmpleado[unEmpleado.cantidad];
    for(int i=0;i<cant;i++)
    {
        for(int j=i++;j<cant;j++)
        {
            if(unEmpleado[i].sueldo<unEmpleado[j].sueldo)
            {
                aux=unEmpleado[i];
                unEmpleado[i]=unEmpleado[j];
                unEmpleado[j]=aux;
            }
            else
            {
                if(unEmpleado[i].sueldo==unEmpleado[j].sueldo)
                {
                    if(strcmp(unEmpleado[i].nombre,unEmpleado[j].nombre)>0)
                    {
                        aux=unEmpleado[i];
                        unEmpleado[i]=unEmpleado[j];
                        unEmpleado[j]=aux;
                    }
                }
            }
        }
    }

    printf("ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &unEmpleado.sexo);
    system("cls");

    printf("Nombre\tLegajo\tSueldo\t\tSexo\n\n");
    printf("-------------------------------------------\n");
    printf("%s\t%d\t$%.2f\t%c\n", unEmpleado.nombre, unEmpleado.legajo, unEmpleado.sueldo, unEmpleado.sexo);


}
