#include <stdio.h>
#include <stdlib.h>

const int MAX_ELEMENTOS = 10;

int RevisaFinCarga()
{
    char respuesta;
    printf("Desea cargar un dato?");
    scanf("%c", &respuesta);

    if (respuesta == 's')
        return 1;
    else
        return 0;
}

int IngresaDato()
{
    int dato;
    printf("Ingrese entero:");
    scanf("%i", &dato);
    fflush(stdin);
    return dato;
}

int CargaArreglo(int mtx[])
{
    int continua;
    int ce = 0;
    int dato;

    continua = RevisaFinCarga();

    while (ce < MAX_ELEMENTOS && continua)
    {
        dato = IngresaDato();
        mtx[ce] = dato;
        ce++;
        continua = RevisaFinCarga();
    }

    if (continua)
        printf("Error en carga de datos.");

    return ce;
}

void MuestraArreglo(int mtx[], int ce)
{
    for (int i = 0; i < ce; i++)
        printf("\n [%i] : %i", i, mtx[i]);
}

int main(int argc, char **argv)
{
    int arreglo[MAX_ELEMENTOS];
    int ce;
    ce = CargaArreglo(arreglo);
    printf("\nElementos cargados: %i", ce);
    MuestraArreglo(arreglo, ce);
}