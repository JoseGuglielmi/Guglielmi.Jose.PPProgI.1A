#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;


int reemplazarCaracteres(char cadena[],char seg, char ter);
float calcularAumento(float numero, float aumento);
int ordenarEstructura(eVacuna *lista, int tam);

int main()
{
    eVacuna lista [4] = {{1,"Jose",'a',321},{3, "juan",'b',299},{2,"alesso", 'c', 332}, {4, "matias",'b',199}};

    ordenarEstructura(lista,4);

    printf(" id  nombre  tipo  efectividad\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%04d  %-5s  %c %-3.2f\n",lista[i].id,lista[i].nombre,lista[i].tipo,lista[i].efectividad);
    }
    system("pause");

    return 0;
}
float calcularAumento(float numero, float aumento)
{
    float precioConDescuento;
    float precioOriginal, porcentajeAumento;

    if (numero > 0)
    {
        aumento = precioOriginal * (porcentajeAumento / 100);
        precioConDescuento = precioOriginal + aumento;
    }
    return precioConDescuento;
}

int reemplazarCaracteres(char *cadena,char seg, char ter)
{
    int contR = 0;
    int i;

    for (i = 0; i <= strlen(cadena) - 1; i++)
    {
        if (cadena[i] == seg)
        {
            cadena[i] = ter;
            contR++;
        }
    }

    return contR;
}

int ordenarEstructura(eVacuna *lista, int tam){
    eVacuna auxLista;
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if((lista[i].tipo > lista[j].tipo) || (lista[i].tipo == lista[j].tipo && lista+i > lista+j))
                {
                    auxLista = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxLista;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
