#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "empleado.h"
#include "almuerzo.h"
#include "sector.h"
#include "comida.h"



#include <string.h>


#define TAM 10
#define TAMS 5
#define TAMC 5
#define TAMA 50
#define CANT 10
#define CANTA 11




int main()
{
    char salir = 'n';
    int proximoId = 1000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eAlmuerzo almuerzos[TAMA];

    //harcodeo un array de sectores
    eSector sectores[TAMS] =
    {

        {1000, "sistemas"},
        {1001, "RRHH"},
        {1002, "Legales"},
        {1003, "Contables"},
        {1004, "Ventas"}
    };


    //harcodeo un array de comida
    eComida comidas[TAMC] =
    {

        {7000, "Milanesa", 500},
        {7001, "Ensalada", 700},
        {7002, "Pizza", 350},
        {7003, "Lasagna", 450},
        {7004, "Sopa", 400}
    };


    inicializarEmpleados(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMA);


    harcodearEmpleados(lista, TAM, CANT, &proximoId);
    harcodearAlmuerzos(almuerzos, TAMA, CANTA, &proximoIdAlmuerzo);

    //int indice;



    //buscarLibre(lista, TAM, &indice);

    //printf("Indice %d\n", indice);

    do
    {

        switch(menuEmpleados())
        {
        case 1:
            if(altaEmpleado(lista, TAM, sectores, TAMS, &proximoId))
            {
                printf("Empleado cargado con exito!!!\n");

            }

            else
            {
                printf("No se pudo cargar el empleado\n");
            }
            break;

        case 2:
            bajaEmpleado(lista, TAM, sectores, TAMS);
            break;

        case 3:
            modificarEmpleado(lista, TAM, sectores, TAMS);
            break;

        case 4:
            printf("Ordenar Empleado\n");
            break;

        case 5:
            system("cls");
            listarEmpleados(lista, TAM, sectores, TAMS);
            break;

        case 6:
            listarEmpleadas(lista, TAM, sectores, TAMS);
            break;

        case 7:
            promedioSueldos(lista, TAM);
            break;


        case 8:
            informeEmpleadosMayor(lista, TAM, sectores, TAMS);
            break;

        case 9:
            system("cls");
            listarSectores(sectores, TAMS);
            break;

        case 10:
            system("cls");
            empleadosSector(lista, TAM, sectores, TAMS);
            break;

        case 11:
            system("cls");
            empleadosXSector(lista, TAM, sectores, TAMS);
            break;

        case 12:
            system("cls");
            totalSueldosSector(lista, TAM, sectores, TAMS);
            break;

        case 13:
            system("cls");
            sectorMasSueldos(lista, TAM, sectores, TAMS);
            break;


        case 14:
            system("cls");
            sectorEmpleadoMasGana(lista, TAM, sectores, TAMS);
            break;

        case 15:
            system("cls");
            sectorMasMujeres(lista, TAM, sectores, TAMS);
            break;


        case 16:
            system("cls");
            empleadosVaronesSector(lista, TAM, sectores, TAMS);
            break;

        case 17:
            system("cls");
            sexoEmpleadoMenor(lista, TAM, sectores, TAMS);
            break;

        case 18:
            system("cls");
            listarComidas(comidas, TAMC);
            break;



        case 19:
            if(altaAlmuerzo(almuerzos, TAMA, lista, TAM, sectores, TAMS,comidas, TAMC, &proximoIdAlmuerzo))
            {
                printf("Almuerzo cargado con exito!!!\n");

            }

            else
            {
                printf("No se pudo cargar el Almuerzo\n");
            }
            break;



        case 20:
            system("cls");
            listarAlmuerzos(almuerzos, TAMA, lista, TAM, sectores, TAMS, comidas, TAMC);
            break;

        case 21:
            totalAPagarEmpleado(almuerzos,TAMA,lista, TAM,comidas, TAMC, sectores, TAMS);
            break;




        case 30:
            salir = 's';
            break;

        }

        system("pause");

    }
    while(salir != 's');




    //eEmpleado unEmpleado = {1234, "juan", 'm', 34, 100};
    //eEmpleado unEmpleado;



    //cargarEmpleado(&unEmpleado);
    //mostrarEmpleado(unEmpleado);

    //harcodearEmpleados(lista, TAM, CANT);
    //cargarEmpleados(lista, TAM);
    //listarEmpleados(lista, TAM);
    //ordenarEmpleadosSexoId(lista, TAM);
    //listarEmpleados(lista, TAM);

    return 0;
}

