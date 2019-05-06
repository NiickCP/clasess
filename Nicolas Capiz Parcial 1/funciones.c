#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void  nuevoVector(ESocio lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
       estadoCero(lista,i);
    }

}
//Tal vez este mal el for y solo tengo que mandar directamente a todo el array un cero.
void estadoCero(ESocio lista[], int i)
{
    strcpy(lista[i].nombre,"\0");
    strcpy(lista[i].apellido,"\0");
    strcpy(lista[i].email,"\0");
    lista[i].estado=0;
    lista[i].codigoSocio=0;
    lista[i].edad=0;
    lista[i].telefono=0;
}

void recorridoCero(ESocio lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        estadoCero(lista,i);
    }
}
int obtenerEspacioLibre(ESocio lista[], int tam)
{
    int i;
    int flag=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            lista[i].estado=1;
            break;
        }
    }
    return flag;
}

void mostrarSociosTotal(ESocio lista[], int tam)
{
    int flag=-1;
    int i, j, k;
    ESocio aux;
    printf("\nNOMBRE\t\tEDAD\t\tDNIn");
    printf("---------------------------------------------------\n");
    for(j=0 ; j < tam-1 ; j++)
    {
        for(k=j+1 ; k < tam ; k++)
        {
            if((strcmp(lista[j].nombre , lista[k].nombre) > 0))
            {
                aux = lista[j];
                lista[j] = lista[k];
                lista[k] = aux;
            }
        }
    }
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1&&lista[i].edad>0&&lista[i].edad<99)
        {
            printf("%s\t\t%d\t\t%d\n", lista[i].nombre,lista[i].edad,lista[i].dni);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("\nNo hay personas para mostrar.\n ");
        getch();
    }
}

void altaSocio(ESocio lista[],int tam)
{
    int aux;
    ESocio nuevoSocio;
    int libreCODIGO;
    int libre;
    int CODIGO;
    libre=obtenerEspacioLibre(lista,tam);
    if (libre==-1)
    {
        printf("\nNo hay espacio libre\n");
    }
    else
    {
        printf("\nIngrese su CODIGO: ");
        scanf("%d",&CODIGO);
        while(CODIGO>100000000||CODIGO<0)
        {
            printf("\nEl CODIGO ingresado no existe, intente nuevamente: ");
            scanf("%d",&CODIGO);
        }
        libreCODIGO=buscarCodigo(lista,CODIGO,tam);
       }
       if(libreCODIGO!=-1)
        {
            printf("\nEl CODIGO ingresado ya esta registrado.");
            getch();
        }
        else
        {
            nuevoSocio.codigoSocio=CODIGO;
            printf("\nIngrese su nombre: ");
            fflush(stdin);
            scanf("%s",&nuevoSocio.nombre);
            aux=esSoloLetras(nuevoSocio.nombre);
            if(aux!=0)
            {   printf("Ingrese nuevamente el dato: ");
                scanf("%s",&nuevoSocio.nombre);
                aux=esSoloLetras(nuevoSocio.nombre);
            }
            esSoloLetras(nuevoSocio.nombre);
            printf("\nIngrese su apellido: ");
            fflush(stdin);
            scanf("%s",&nuevoSocio.apellido);
            aux=esSoloLetras(nuevoSocio.apellido);
            if(aux!=0)
            {
                printf("Ingrese nuevamente el dato: ");
                scanf("%s",&nuevoSocio.apellido);
                aux=esSoloLetras(nuevoSocio.apellido);
            }
            nuevoSocio.apellido=esSoloLetras(nuevoSocio.apellido);
            printf("\nIngrese su telefono: ");
            scanf("%d",&nuevoSocio.telefono);
            telefono=esTelefono(telefono);
            printf("\nIngrese su genero: ");
            scanf("%c",&nuevoSocio.sex);
            aux=validarGenero(nuevoSocio.sex);
            if(aux!=0)
            {
                printf("El dato insgresado es incorrecto vuelva a intentarlo: ");
                scanf("%c",&nuevoSocio.sex);
                aux=validarGenero(nuevoSocio.sex);
            }
            printf("\nIngrese su eMail: ");
            fflush(stdin);
            scanf("%d",&nuevoSocio.email);
            aux=esSoloLetras(nuevoSocio.email);
            if(aux!=0)
            {
                printf("Ingrese nuevamente el dato: ");
                scanf("%s",&nuevoSocio.email);
                aux=esSoloLetras(nuevoSocio.email);
            }
            printf("\nIngrese su fecha de asociado: ");
            scanf("%d",&nuevoSocio.fechaAsociado);
            nuevoSocio.estado=1;
            lista[libre]=nuevoSocio;
        }

}
int buscarCodigo(ESocio lista[],int CODIGO, int tam)
{

    int flagCodigo=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if (lista[i].codigo==CODIGO)
        {
            flagCodigo=i;
            break;
        }
    }
    return flagCodigo;
}

void bajaSocio(ESocio lista[], int tam)
{
    char respuesta = 'n';
    int lugar;
    int CODIGO;
    printf("Ingrese CODIGO: ");
    scanf("%d",&CODIGO);
    lugar=buscarCodigo(lista,CODIGO,tam);
    if(lugar!=-1)
    {
        printf("%s\t\t%d\t\t%d\n", lista[lugar].nombre,lista[lugar].edad,lista[lugar].codigoSocio);
        printf("\nSi quiere confirmar la baja presion la tecla s .\n");
        respuesta = getch();
        if(respuesta=='s')
        {
            lista[lugar].estado=0;
            printf("\nLa baja a sido exitosa.");
        }
        else
            {
                printf("\nNo se pudo realizar la baja.");
            }

    }

int esTelefono(int telefono)
{
   if (telefono>99999999||telefono<10000000)
   {
       printf("El telefono ingresado es incorrecot. Vuelva a intentarlo");
       scanf("%d",&telefono);
   }
   return telefono;
}
int esSoloLetras(char str[])
{
   int i=0;
   int asist=0;
   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           asist=1;
       i++;
   }
    return asist;
}
int validarGenero(char sex)
{
    if(sex!='m'||sex!='M'||sex!='f'||sex!='F')
        return 1;
    return 0;
}

}
