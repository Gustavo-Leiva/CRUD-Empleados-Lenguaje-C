#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sector.h"






//funcion que carga en ese vector la descripcion del sector.
int cargarDescripcionSector (eSector sectores [], int tams, int id, char desc[])
{
    int todoOk = 0;

    if(sectores != NULL && tams > 0 && desc != NULL)
    {

        for(int i = 0; i < tams ; i++)
        {

            if(sectores[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, sectores[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}


int listarSectores (eSector sectores[], int tam)
{
    int todoOk = 0;

    if(sectores != NULL && tam > 0)
    {
        printf("********listado de sectores *********\n");
        printf("      Id            Descripcion      \n");
        printf("-------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            printf("      %4d    %20s\n", sectores[i].id, sectores[i].descripcion);


        }

        todoOk = 1;
    }



    return todoOk;
}


int buscarSector(eSector vec[], int tams, int id, int* pIndex)
{
    int todoOk = 0;

    if( vec !=NULL && tams > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i= 0; i < tams; i++)
        {
            if( vec[i].id== id)
            {
                *pIndex = i;
                break;
            }
        }

        todoOk= 1;
    }


    return todoOk;
}


int validarSector(eSector vec[], int tams, int id)
{
    int esValido = 0;
    int indice;

    if(buscarSector(vec, tams, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;

}
