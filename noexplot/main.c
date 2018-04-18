#include <stdio.h>
#include <stdlib.h>

int main()
{
    //atof cadena a float
    //atoi cadema a un entero
    // atol cadena a un entero mas grande
    int flag=0;
    char dato[15];
    printf("Ingrese un numero ");
    fflush(stdin);
    scanf("%s",dato);
    for (int i=0; i<strlen(dato);i++)
    {
        int isdigit(char);
        if(!isdigit(dato)[i])
        {
            flag=1;
            break;
        }
    }
}
