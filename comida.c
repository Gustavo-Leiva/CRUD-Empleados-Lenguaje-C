#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comida.h"



//funcion que carga en ese vector la descripcion del sector.
int cargarDescripcionComida (eComida comidas[], int tamc, int id, char desc[])
{
    int todoOk = 0;

    if(comidas != NULL && tamc > 0 && desc != NULL)
    {

        for(int i = 0; i < tamc ; i++)
        {

            if(comidas[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, comidas[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}


int listarComidas (eComida comidas[], int tamc)
{
    int todoOk = 0;

    if(comidas != NULL && tamc > 0)
    {
        printf("********listado de Comidas *********\n");
        printf("      Id            Descripcion     Precio  \n");
        printf("-------------------------------------\n");
        for(int i = 0; i < tamc; i++)
        {
            printf("      %4d    %20s     %5.2f\n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);


        }

        todoOk = 1;
    }



    return todoOk;
}


int buscarComida(eComida comidas[], int tamc, int id, int* pIndex)
{
    int todoOk = 0;

    if( comidas !=NULL && tamc > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i= 0; i < tamc; i++)
        {
            if(comidas[i].id== id)
            {
                *pIndex = i;
                break;
            }
        }

        todoOk= 1;
    }


    return todoOk;
}


int validarComida(eComida comidas[], int tamc, int id)
{
    int esValido = 0;
    int indice;

    if(buscarComida(comidas, tamc, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;

}
