#include "funcion.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int esTelefono(int telefono)
{
    if (telefono>99999999||telefono<10000000)
        return 1;
    return 0;
}
int esSoloLetras(char str[])
{
    int i=0;
   while(str[i]!='\0')
   {
    if (str[i]<'a'||str[i]>'z')
        return 1;
    i++;
   }
    return 0;
}
int esNumerico(int str[])
{
    int i=0;
   while(str[i]!='\0')
   {
    if (str[i]<'0'||str[i]>'9')
        return 1;
    i++;
   }
    return 0;
}
int validarGenero(char sex)
{
    if(sex=='m'||sex=='M'||sex=='f'||sex=='F')
        return 0;
    return 1;
}
int validarEmail(char email[])
{
    for(int i=0;i<email[31];i++)
    {
        if(email[i]=='@')
            return 1;
    }
    return 0;
}
int validarFecha(EFecha fecha)
{
    if(fecha.dia>31||fecha.dia<1)
        return 1;
    if(fecha.mes>31||fecha.mes<1)
        return 1;
    if(fecha.anio>31||fecha.anio<1)
        return 1;
    return 0;
}
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
    lista[i].sex='n';
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
    printf("\nAPELLIDO\t\tNOMBRE\t\tCODIGO\t\tTELEFONO\t\tEMAIL\t\tSEXOn");
    printf("---------------------------------------------------\n");
    for(j=0 ; j < tam-1 ; j++)
    {
        for(k=j+1 ; k < tam ; k++)
        {
            if((strcmp(lista[j].apellido , lista[k].apellido) > 0))
            {
                aux = lista[j];
                lista[j] = lista[k];
                lista[k] = aux;
            }
        }
    }
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%c\n", lista[i].apellido,lista[i].nombre,lista[i].codigoSocio,lista[i].telefono,lista[i].email,lista[i].sex);
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
    int auxA=1;
    int auxB=1;
    int auxC=1;
    int auxD=1;
    int auxF=1;
    int auxG=1;
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
        system("cls");
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
            printf("\nIngrese su nombre: ");
            fflush(stdin);
            scanf("%s",&nuevoSocio.nombre);
            auxA=esSoloLetras(nuevoSocio.nombre);
            while(auxA!=0)
            {
                printf("El nombre ingresado es incorrecto intente nuevamente: ");
                scanf("%s",&nuevoSocio.nombre);
                auxA=esSoloLetras(nuevoSocio.nombre);
            }
            system("cls");
            printf("Ingrese su apellido: ");
            scanf("%s",&nuevoSocio.apellido);
            auxB=esSoloLetras(nuevoSocio.apellido);
            while(auxB!=0)
            {
                printf("El apellido ingresado es incorrecto intente nuevamente: ");
                scanf("%s",&nuevoSocio.apellido);
                auxB=esSoloLetras(nuevoSocio.apellido);
            }
            system("cls");
            printf("\nIngrese su telefono: ");
            scanf("%d",&nuevoSocio.telefono);
            auxC=esTelefono(nuevoSocio.telefono);
            while(auxC!=0)
            {
                    printf("\nEl numero de telefono ingresado es incorrecto: ");
                    scanf("%d",&nuevoSocio.telefono);
                    auxC=esTelefono(nuevoSocio.telefono);
            }
            system("cls");
            printf("\nIngrese su sexo: ");
            getrer("%c",&nuevoSocio.sex);
            auxD=validarGenero(nuevoSocio.sex);
            while(auxD!=0)
            {
                printf("El sexo ingresado es incorrecto: ");
                scanf("%c",&nuevoSocio.sex);
                auxD=validarGenero(nuevoSocio.sex);
            }
            system("cls");
            printf("\nIngrese su eMail: ");
            fflush(stdin);
            scanf("%s",&nuevoSocio.email);
            auxF=validarEmail(nuevoSocio.email);
            while(auxF!=0)
            {
                printf("El email ingresado es incorrecto: ");
                scanf("%s",&nuevoSocio.email);
                auxF=validarEmail(nuevoSocio.email);
            }
            system("cls");
            printf("\nIngrese su fecha de asociado: ");
            scanf("%d",&nuevoSocio.fechaAsociado);
            while(auxG!=0)
            {
                printf("Ingrese nuevamente el dato: ");
                scanf("%d",&nuevoSocio.fechaAsociado);
                auxG=validarFecha(nuevoSocio.fechaAsociado);
            }
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
        if (lista[i].codigoSocio==CODIGO)
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
        printf("%s\t\t%s\t\t%d\n", lista[lugar].apellido,lista[lugar].nombre,lista[lugar].codigoSocio);
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
}
