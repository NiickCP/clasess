#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define tam 20

int main()
{
    ESocio lista[20];
    nuevoVector(lista,20);
    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        system("cls");
        printf("----------Lista de Socios---------------\n");
        printf("+1- Alta socio                       +\n");
        printf("+2- Borrar socio                        +\n");
        printf("+3- Imprimir lista ordenada por  nombre   +\n");
        printf("+4- Modificar            +\n");
        printf("+5- Salir                                 +\n");
        printf("-------------------------------------------\n\n\n");
        printf("Ingrese opcion: ");

        scanf("%d",&opcion);

        while(opcion<1||opcion>5)
        {
            printf("Error. El numero ingresado es incorrecto.");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
        case 1:
            system("cls");
            altaSocio(lista,tam);
            break;
        case 2:
            system("cls");
            bajaSocio(lista,tam);
            getch();
            break;
        case 3:
            system("cls");
            mostrarSociosTotal(lista,tam);
            getche();
            break;
        case 4:

            getch();
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
