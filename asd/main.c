#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void miFuncion(char[][40],int);
int main()
{
    char nombres[5][40]= {"el brian perro","luis","ana","marco","mario"};
    miFuncion(nombres,5);
    return 0;
}
void miFuncion(char vec[][40],int filas)
{
    for(int i=0; i<filas; i++)
    {
        strlwr(vec[i]);
        for(int k=0; k<40; k++)
        {
            if(vec[i][k]==' ')
            {
                vec[i][k+1]=toupper(vec[i][k+1]);
            }
        }
        vec[i][0]=toupper(vec[i][0]);
        printf("%s \n",vec[i]);
    }



}

