#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "almuerzo.h"



//incializa el vector de empleados en cero eliminando la basura.
int inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    int todoOk= 0;

    if(vec != NULL && tam > 0)
    {

        for(int i = 0; i< tam; i++)
        {

            vec[i].isEmpty =1;
        }


    }


    return todoOk;
}


//busca el primer almuerzo libre y carga en ese puntero el indice.
int buscarLibreAlmuerzo (eAlmuerzo vec[], int tamc, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tamc > 0)
    {
        for(int i = 0; i < tamc ; i++)
        {
            *pIndex = -1;
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }

        }

        todoOk = 1;

    }

    return todoOk;

}


//recorre el array le asigna el Id proximo libre
int altaAlmuerzo (eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tams, eComida comidas[], int tamc,  int* pNextId)
{

    int todoOk = 0;
    int indice;
    eAlmuerzo nuevoAlmuerzo;
    eFecha fecha;
    int idEmpleado;
    int idComida;


    if(almuerzos != NULL  && sectores != NULL   && pNextId != NULL && comidas != NULL && empleados != NULL  && tam > 0  && tams > 0 && tama > 0 && tamc > 0)

    {
        system("cls");
        printf("********Alta Almuerzo********\n");
        buscarLibreAlmuerzo(almuerzos, tama, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoAlmuerzo.id = *pNextId;

            listarEmpleados(empleados, tam, sectores, tams);
            printf("ingrese Id Empleado: \n");
            scanf("%d", &idEmpleado);

            while(validarEmpleado(empleados, tam, idEmpleado)==0)
            {
                printf("Empleado invalido. ingrese Id Empleado: \n");
                scanf("%d", &idEmpleado);
            }

            nuevoAlmuerzo.idEmpleado = idEmpleado;

            listarComidas(comidas,tamc);

            printf("ingrese Id Comida: \n");
            scanf("%d", &idComida);

            while(validarComida(comidas, tamc, idComida)==0)
            {
                printf("Comida invalido. ingrese Id Comida: \n");
                scanf("%d", &idComida);
            }

            nuevoAlmuerzo.idComida = idComida;


            printf("ingrese fecha  dd/mm/aaaa:");
            scanf("%d/%d/%d",
                  &fecha.dia,
                  &fecha.mes,
                  &fecha.anio);

            nuevoAlmuerzo.fecha = fecha;

            nuevoAlmuerzo.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            almuerzos[indice] = nuevoAlmuerzo;
            //aca lo inyecto en la lista de empleados

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1


            todoOk = 1;

        }




    }

    return todoOk;
}




int listarAlmuerzos (eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tams, eComida comidas[], int tamc)
{
    int todoOk = 0;
    int flag = 1;

    if(almuerzos != NULL  && sectores != NULL   && comidas != NULL && empleados != NULL  && tam > 0  && tams > 0 && tama > 0 && tamc > 0)
    {
        system("cls");
        printf("**************Listado    de    Almuerzos***********\n");
        printf(" ID        NOMBRE              COMIDA                    FECHA  \n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i< tama; i++)
        {
            if(!almuerzos[i].isEmpty )//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarAlmuerzoFila(almuerzos[i], empleados, tam, comidas, tamc);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("     no hay almuerzo en el sistema\n");
        }
    }


    return todoOk;
}


int mostrarAlmuerzoFila(eAlmuerzo almuerzo, eEmpleado empleados[], int tam, eComida comidas[], int tamc)
{

    int todoOk = 0;
    char nombreEmpleado[20];
    char descComida[20];

    if(empleados != NULL  && comidas != NULL && tam > 0  && tamc > 0)
    {


            cargarDescripcionComida(comidas, tamc, almuerzo.idComida, descComida);
            cargarNombreEmpleado(empleados, tam, almuerzo.idEmpleado, nombreEmpleado);

            printf("%d  %10s       %10s            %02d/%02d/%d\n",
                   almuerzo.id,
                   nombreEmpleado,
                   descComida,
                   almuerzo.fecha.dia,
                   almuerzo.fecha.mes,
                   almuerzo.fecha.anio
                  );



        todoOk = 1;
    }

    return todoOk;
}




int harcodearAlmuerzos(eAlmuerzo vec[], int tam, int canta, int* pNextId)
{
    int todoOk = 0;

    eAlmuerzo almuerzos [11]=
    {
        {20000, 1000, 7000, {2,5,2022},0},
        {20001, 1001, 7001, {2,5,2022},0},
        {20002, 1002, 7000, {3,5,2022},0},
        {20003, 1003, 7002, {2,10,2022},0},
        {20004, 1004, 7000, {2,5,2022},0},
        {20005, 1005, 7000, {2,12,2022},0},
        {20006, 1006, 7004, {4,5,2022},0},
        {20007, 1000, 7000, {2,5,2022},0},
        {20008, 1008, 7002, {8,5,2022},0},
        {20009, 1009, 7000, {2,5,2022},0},
        {20010, 1000, 7002, {2,5,2022},0}



    };

    if(vec != NULL && pNextId != NULL && tam> 0 && canta <= tam)
    {
        for (int i = 0; i<canta; i++)
        {
            vec[i]= almuerzos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}



int totalAPagarEmpleado(eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eComida comidas[], int tamc, eSector sectores[], int tams)
{

    int todoOk = 0;
    int idEmpleado;
    float total= 0;


    if(empleados != NULL  && comidas != NULL && tam > 0  && tamc > 0 )
    {

        system("cls");
        printf("  ****Total a Pagar Empleados por almuerzos********\n");
        printf("-----------------------------------------------------");


        listarEmpleados(empleados, tam, sectores, tams);
        printf("ingrese Id empleado:\n");
        scanf("%d", &idEmpleado);
        while(validarEmpleado(empleados, tam, idEmpleado==0))
        {
            printf("Empleado Invalido. Reingrese Id empleado:\n");
            scanf("%d", &idEmpleado);
        }


        //recorro porque debo sumar los totales de almuerzo
        for(int i = 0; i< tama; i++)
        {
            if(!almuerzos[i].isEmpty && almuerzos[i].idEmpleado == idEmpleado)//busca almuerzos que sean de ese empleado.
            {
                for(int j= 0; j < tamc; j++) //recorro el array de comidas para que?
                {

                    if(comidas[j].id == almuerzos[i].idComida) //prque quiero encontrar la estructura comida que tiene el id igual al id del almuerzo.
                    {
                        total+= comidas[j].precio; //cuando lo encuentra el precio de la comida lo acumula en la variable total.
                    }
                }

            }

        }


        printf("El total a pagar es $ %.2f\n", total);




        todoOk = 1;

    }

    return todoOk = 1;

}








