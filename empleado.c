#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "empleado.h"


#define TAMS 5

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tams)
{
    char descripcion [20];
    cargarDescripcionSector(sectores, tams, emp.idSector, descripcion);

    printf("Legajo: %d\n", emp.id);
    printf("Nombre: %s\n", emp.nombre);
    printf("Sexo: %c\n", emp.sexo);
    printf("Edad: %d\n", emp.edad);
    printf("Sueldo: %.2f\n", emp.sueldo);
    printf("Fecha de Ingreso: %02d/%02d/%d\n", emp.fIngreso.dia, emp.fIngreso.mes, emp.fIngreso.anio);
    printf("Sector: %s\n", descripcion);
}




void mostrarEmpleadoFila (eEmpleado emp, eSector sectores[], int tams)
{

    char descripcion [20];

    cargarDescripcionSector(sectores, tams, emp.idSector, descripcion);

    printf("%4d %10s     %c     %2d       %7.2f    %02d/%02d/%d      %10s\n",
           emp.id,
           emp.nombre,
           emp.sexo,
           emp.edad,
           emp.sueldo,
           emp.fIngreso.dia,
           emp.fIngreso.mes,
           emp.fIngreso.anio,
           descripcion);

}

//cargar empleados
int cargarEmpleado (eEmpleado* pEmpleado)
{
    int todoOk = 0;

    if(pEmpleado != NULL )
    {
        printf("Ingrese el id:\n");
        scanf("%d", &pEmpleado->id);

        printf("Ingrese el nombre:\n");
        fflush(stdin);
        gets(pEmpleado->nombre);

        printf("Ingrese el sexo:\n");
        fflush(stdin);
        scanf("%c", &pEmpleado->sexo);

        printf("Ingrese el edad:\n");
        scanf("%d", &pEmpleado->edad);

        printf("Ingrese el sueldo:\n");
        scanf("%f", &pEmpleado->sueldo);


        todoOk = 1;

    }
    return todoOk;

}


int cargarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            cargarEmpleado(&vec[i]);
        }

        todoOk = 1;
    }

    return todoOk;

}


//lista los empleados
int listarEmpleados (eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int flag = 1;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("**************Listar**Empleados***********\n");
        printf(" ID     NOMBRE   SEXO    EDAD       SUELDO  F. Ingreso  Sector\n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i< tam; i++)
        {
            if(!vec[i].isEmpty )//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarEmpleadoFila(vec[i], sectores, tams);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("     no hay empleados en el sistema\n");
        }
    }


    return todoOk;
}


int harcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;

    eEmpleado empleados [10]=
    {
        {0, "Juan", 'm', 34, 377,{2,5,2022},1000,0},
        {0, "Alicia", 'f', 38, 200, {17,8,2012},1001,0},
        {0, "Manuela", 'f', 40, 290, {11,7,2002},1000,0},
        {0, "Pedro", 'm', 59, 230, {29,5,2019},1002,0},
        {0, "Maria", 'f', 20, 143, {15,3,2021},1004,0},
        {0, "Paula", 'f', 43, 290,{23,5,6015},1003,0},
        {0, "Monica", 'f', 29, 277, {12,9,2010},1001,0},
        {0, "Jorge", 'm', 54, 320, {10,11,2005},1004,0},
        {0, "Julian", 'f', 32, 180,{30,6,2016},1003,0},
        {0, "Federico", 'm', 59, 377, {24,12,2014},1001,0}

    };

    if(vec != NULL && pNextId != NULL && tam> 0 && tam <=10 && cant <= tam)
    {
        for (int i = 0; i<cant; i++)
        {
            vec[i]= empleados[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


//incializa el vector de empleados en cero eliminando la basura.
int inicializarEmpleados(eEmpleado vec[], int tam)
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


int ordenarEmpleados(eEmpleado vec[], int tam)

{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if (vec != NULL && tam > 0)
    {

        for (int i = 0; i < tam-1 ; i++)
        {
            for (int j = i+1; j < tam; j++)
            {
                //ordenar por nombre
                if(strcmp(vec[i].nombre, vec[j].nombre)>0)   //ordenar por sexo if(vec[i].sexo > vec[j].sexo)
                {
                    auxEmpleado = vec[i];
                    vec[i]= vec[j];
                    vec[j]= auxEmpleado;
                }
            }
        }


        todoOk = 1;
    }


    return todoOk;
}

/*

//funcion larga
int ordenarEmpleadosSexoId(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i +1; j < tam; j++)
            {
                if(vec[i].sexo == vec[j].sexo)
                {
                    if(vec[i].id > vec[j].id)
                    {
                        auxEmpleado = vec[i];
                        vec[i]= vec[j];
                        vec[j]= auxEmpleado;

                    }


                }

                //aca caigo cuando son empleados de distinto sexo

                else
                {
                    if(vec[i].sexo > vec[j].sexo)
                    {
                        auxEmpleado = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmpleado;

                    }


                }


            }
        }

        int todoOk = 1;
    }


    return todoOk;
}

*/

//funcion corta
int ordenarEmpleadosSexoId(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i +1; j < tam; j++)
            {
                if(((vec[i].sexo == vec[j].sexo) && (vec[i].id > vec[j].id))

                        ||((vec[i].sexo != vec[j].sexo) && (vec[i].sexo > vec[j].sexo)))
                {

                    auxEmpleado = vec[i];
                    vec[i]= vec[j];
                    vec[j]= auxEmpleado;

                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}



//int ordenarEmpleadosSexoNombre (eEmpleado vec[], int tam) pendiente para hacer.



int menuEmpleados()
{
    int opcion;

    system("cls");
    printf("********** ABM Empleados*******\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Baja Empleado\n");
    printf("3. Modificar Empleado\n");
    printf("4. Ordenar Empleados\n");
    printf("5. Listar Empleados\n");
    printf("6. Listar Empleadas\n");
    printf("7. Informe promedio de sueldos\n");
    printf("8. Informes Empleados mayor Edad\n");
    printf("9. Listar sectores\n");
    printf("10. Listar empleados de un sector\n");
    printf("11. Listar empleados cada sector\n");
    printf("12. Total sueldos sector\n");
    printf("13. Sector\es que cobras mas sueldos\n");
    printf("14. Empleado del sector que mas gana\n");
    printf("15. Sector mas mujeres\n");
    printf("16. Total hombres de un sector\n");
    printf("17. Sexo empleado menor\n");
    printf("18. Listar comidas\n");
    printf("19. Alta Almuerzo\n");
    printf("20. Listar Almuerzos\n");
    printf("21. Total a pagar empleado\n");
    printf("30. Salir\n");
    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}


//carga por referencia la variable cuya direccion de memoria me pasen como tercer paramentro con el indice
// de la primer estructura libre o la va a cargar con el -1 en caso que no tenga libre.
int buscarLibre (eEmpleado vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
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
int altaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams, int* pNextId)
{

    int todoOk = 0;
    int indice;
    eEmpleado nuevoEmpleado;
    eFecha fecha;
    int idSector;

    if(vec != NULL  && tam > 0  && sectores != NULL  && tams > 0 && pNextId != NULL)

    {
        system("cls");
        printf("********Alta Empleado********\n");
        buscarLibre(vec, tam, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoEmpleado.id = *pNextId;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);


            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);


            nuevoEmpleado.sexo = tolower(nuevoEmpleado.sexo);//es para guardar en minuscula.

            printf("Ingrese edad: ");
            scanf("%d", &nuevoEmpleado.edad);

            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);



            printf("ingrese fecha de Ingreso dd/mm/aaaa:");
            scanf("%d/%d/%d",
                  &fecha.dia,
                  &fecha.mes,
                  &fecha.anio);

            nuevoEmpleado.fIngreso = fecha;

            //otra forma de asignar fecha.
            //&nuevoEmpleado.fIngreso.dia,
            //&nuevoEmpleado.fIngreso.mes,
            //&nuevoEmpleado.fIngreso.anio);


            listarSectores(sectores, tams);

            printf(" Ingrese Id Sector: ");
            scanf("%d", &idSector);

            //validar si existe ese idSector
            while(validarSector(sectores, tams, idSector) == 0)
            {
                printf(" Id Invalido, Reingrese Id Sector: ");
                scanf("%d", &idSector);
            }

            nuevoEmpleado.idSector = idSector;

            nuevoEmpleado.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoEmpleado;
            //aca lo inyecto en la lista de empleados

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1


            todoOk = 1;

        }




    }

    return todoOk;
}


//busca el empleado,
int buscarEmpleado (eEmpleado vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {

            //aca busco que la estructura no este vacia y que el id que busco coincida con ese lugar.
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}



//le tiro el array empleados y el id y me dice 0 sino existe un empleado con ese id y 1 si existe.
int validarEmpleado (eEmpleado empleados[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarEmpleado(empleados, tam, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}



int bajaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {
        listarEmpleados(vec, tam, sectores, tams);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarEmpleado(vec, tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un empleado con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarEmpleado(vec[indice], sectores, tams);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }



    }


    return todoOk;

}





int modificarEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    char sexo;
    float sueldo;
    int edad;
    char confirma;
    eFecha fecha;
    int idSector;


    if(vec != NULL && tam > 0 && sectores != NULL && tams >0)
    {
        listarEmpleados(vec, tam, sectores, tams);
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Empleado a Modificar*******\n");

        if(buscarEmpleado(vec, tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un empleado con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarEmpleado(vec[indice], sectores, tams);

                switch(menuModificarEmpleado())
                {
                case 1:
                    printf("Ingrese el nuevo nombre: \n");
                    fflush(stdin);
                    gets(auxCad);
                    //valido
                    if(confirmarCarga(&confirma))
                    {
                        strcpy(vec[indice].nombre, auxCad);
                    }




                    break;

                case 2:
                    printf("Ingrese el sexo \n");
                    fflush(stdin);
                    scanf("%c", &sexo);
                    //validar
                    vec[indice].sexo = sexo;
                    //printf("sexo modificado!");
                    break;

                case 3:
                    printf("Ingrese la edad: \n");
                    fflush(stdin);
                    scanf("%d", &edad);
                    //validar
                    vec[indice].edad = edad;
                    //printf("edad modificada");
                    break;

                case 4:
                    printf("Ingrese el sueldo: \n");
                    fflush(stdin);
                    scanf("%f", &sueldo);
                    //validar
                    vec[indice].sueldo = sueldo;
                    //printf("sueldo modificado");
                    break;

                case 5:
                    printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
                    scanf("%d/%d/%d", &fecha.dia, &fecha.mes,&fecha.anio);
                    //validar indice es el empleado que quiero modificar
                    vec[indice].fIngreso = fecha;
                    //printf("fecha modificado");
                    break;



                case 6:
                    listarSectores(sectores, tams);

                    printf(" Ingrese Id Sector: ");
                    scanf("%d", &idSector);

                    //validar si existe ese idSector
                    while(validarSector(sectores, tams, idSector) == 0)
                    {
                        printf(" Id Invalido, Reingrese Id Sector: ");
                        scanf("%d", &idSector);
                    }

                    vec[indice].idSector = idSector;

                    break;

                }

            }

            todoOk = 1;

        }

    }

    return todoOk;
}


int menuModificarEmpleado()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Nombre\n");
    printf("2. Sexo\n");
    printf("3. Edad\n");
    printf("4. Sueldo\n");
    printf("5. Fecha Ingreso:\n");
    printf("6. Sector:\n");
    printf("7. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}


int confirmarCarga (char* x)
{
    int todoOk = 0;

    if( x != NULL)
    {
        printf("confirma carga? (S/N): ");
        fflush(stdin);
        scanf("%c", x );
        *x=toupper(*x);

        while(!(*x =='S' || *x =='N'))
        {
            printf("Error!! Ingrese 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",x);
            *x = toupper(*x);
        }

        if(*x == 's' || *x == 'S')
        {
            printf("Carga exitosa\n");
            todoOk = 1;

        }

        else
        {
            printf("Carga cancelada por usuario\n");
        }

    }

    return todoOk;
}


int listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int flag = 1;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("**************Listar**Empleadas***********\n");
        printf(" ID     NOMBRE   SEXO    EDAD       SUELDO  F. Ingreso    Sector\n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i< tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].sexo == 'f')//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarEmpleadoFila(vec[i], sectores, tams);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("     no hay empleados en el sistema\n");
        }
    }


    return todoOk;
}




int promedioSueldos(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    int acumSueldo = 0;
    int contEmpleados = 0;
    float promedio;


    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                acumSueldo += vec[i].sueldo;
                contEmpleados++;
            }
        }



        if(contEmpleados != 0)
        {
            promedio = acumSueldo/contEmpleados;

        }

        system("cls");
        printf("****Promedios de sueldos******\n");


        printf("El promedio de los sueldos es %.2f\n", promedio);


        todoOk =1;

    }


    return todoOk;

}


int informeEmpleadosMayor(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk= 0;
    int mayorEdad;
    int flag = 0;
    //eEmpleado mayoresEdades ;



    if(vec!=NULL && tam > 0)
    {
        system("cls");
        printf("**************Informes Empleados Mayor Edad********************\n");
        printf(" ID     NOMBRE   SEXO    EDAD       SUELDO  F. Ingreso   Sector\n");
        printf("---------------------------------------------------------------\n");


        for(int i = 0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                if(flag == 0 || vec[i].edad >= mayorEdad)
                {
                    mayorEdad = vec[i].edad;
                    flag = 1;
                }
            }

        }



        for(int i = 0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                if(vec[i].edad == mayorEdad)
                {
                    mostrarEmpleadoFila(vec[i], sectores, tams);
                }

            }

        }



        if(!flag)
        {
            printf(" No hay empleados cargados en el sistema\n");

        }


        todoOk = 1 ;

    }

    return todoOk;

}



//segunda forma de hacerlo. filtra un sector especifico introducido el ID por el usuario.
int empleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int idSector;


    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {

        system("cls");
        printf("      ***Informe Empleados de un sector***      \n");
        printf("------------------------------------------------\n");

        listarSectores(sectores, tams);

        printf("ingrese el id del sector: \n");
        scanf("%d", &idSector);

        while(!validarSector(sectores, tams, idSector))
        {
            printf("id Invalido. Reingrese el id del sector: \n");
            scanf("%d", &idSector);
        }

        empleadosXIdSector(vec, tam, sectores, tams, idSector);

        todoOk = 1;

    }


    return todoOk;
}



/*

//primera forma de hacerlo. filtra un sector especifico introducido el ID por el usuario.

int empleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int idSector;
    char descripcion [20];
    int flag = 1;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {

        system("cls");
        printf("      ***Informe Empleados de un sector***      \n");
        printf("------------------------------------------------\n");

        listarSectores(sectores, tams);

        printf("ingrese el id del sector: \n");
        scanf("%d", &idSector);

        while(!validarSector(sectores, tams, idSector))
        {
            printf("id Invalido. Reingrese el id del sector: \n");
            scanf("%d", &idSector);
        }

        cargarDescripcionSector(sectores, tams, idSector, descripcion);

        printf("Empleados Sector %s\n\n", descripcion);


        printf("**************Informes Empleados De un Sector********************\n");
        printf(" ID     NOMBRE   SEXO    EDAD       SUELDO  F. Ingreso   Sector\n");
        printf("---------------------------------------------------------------\n");



        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idSector == idSector)
            {
                mostrarEmpleadoFila(vec[i], sectores, tams);
                flag = 0;
            }


        }

        if(flag)
        {

            printf("no hay empleados cargado en el sector %s\n", descripcion);
        }


        todoOk = 1;

    }


    return todoOk;
}






//primera forma de hacerlo. Muestra todos los empleados por sector.

int empleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int flag;
    //char descripcion [20];




    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {

        //strcpy(descripcion, sectores[i].descripcion);

        system("cls");
        printf("                 ***Informe Empleados de cada sector***      \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tams; i++)
        {
            printf("sector: %s\n\n", sectores[i].descripcion);
            flag = 1;

            for(int j= 0; j < tam; j++)
            {
                if(!vec[j].isEmpty && vec[j].idSector == sectores[i].id)
                {
                    mostrarEmpleadoFila(vec[j], sectores, tams);
                    flag = 0;

                }

            }

            if(flag)
            {
                printf("no hay empleados en ese sector cargado en el sistema\n");
            }

            printf("------------------------------------------------------------------------\n");

        }

        todoOk = 1;
    }

    return todoOk;
}

*/




//2da forma de hacerlo llamando a la funcion empleadosXIdSector();
int empleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;


    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {


        system("cls");
        printf("                 ***Informe Empleados de cada sector***      \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tams; i++)
        {

            empleadosXIdSector(vec, tam, sectores, tams, sectores[i].id);
        }



        todoOk = 1;
    }


    return todoOk;
}








int empleadosXIdSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector)
{
    int todoOk = 0;
    char descripcion [20];
    int flag = 1;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {
        cargarDescripcionSector(sectores, tams, idSector, descripcion);

        printf("\nEmpleados Sector %s\n\n", descripcion);

        printf(" ID     NOMBRE   SEXO    EDAD       SUELDO  F. Ingreso            Sector\n");
        printf("------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idSector == idSector)
            {
                mostrarEmpleadoFila(vec[i], sectores, tams);
                flag = 0;
            }
        }

        if(flag)
        {

            printf("no hay empleados en ese sector cargado en el sistema\n");
        }


        todoOk = 1;

    }

    return todoOk;

}



/*
//1er forma
//me pide un idSector y me muestra el total de los sueldos de los empleados de ese sector.
int totalSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int idSector;
    char descripcion [20];
    float acumSueldos = 0;

    int flag = 1;
    if(vec != NULL && tam > 0 && sectores != NULL)
    {

        system("cls");
        printf("              ***Total sueldos Empleados de un sector***      \n");
        printf("-----------------------------------------------------------\n");

        listarSectores(sectores, tams);

        printf("ingrese el id del sector: \n");
        scanf("%d", &idSector);

        while(!validarSector(sectores, tams, idSector))
        {
            printf("id Invalido. Reingrese el id del sector: \n");
            scanf("%d", &idSector);
        }

        cargarDescripcionSector(sectores, tams, idSector, descripcion);


        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idSector == idSector)
            {
                acumSueldos +=vec[i].sueldo;
                flag = 0;
            }
        }

        if(flag)
        {

            printf("no hay empleados en ese sector %s\n", descripcion);
        }


        else
        {
            printf("El total de sueldos del sector %s es %.2f\n", descripcion, acumSueldos);
        }


        todoOk = 1;

    }

    return todoOk;
}

*/



//2da forma llamando a otra funcion.
int totalSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int idSector;
    char descripcion [20];
    float acumSueldos;


    if(vec != NULL && tam > 0 && sectores != NULL)
    {

        system("cls");
        printf("              ***Total sueldos Empleados de un sector***      \n");
        printf("-----------------------------------------------------------\n");

        listarSectores(sectores, tams);

        printf("ingrese el id del sector: \n");
        scanf("%d", &idSector);

        while(!validarSector(sectores, tams, idSector))
        {
            printf("id Invalido. Reingrese el id del sector: \n");
            scanf("%d", &idSector);
        }

        cargarDescripcionSector(sectores, tams, idSector, descripcion);

        totalSueldosxIdSector(vec, tam, sectores, tams, idSector, &acumSueldos);

        if(acumSueldos == 0)
        {

            printf("no hay empleados en el sector %s\n", descripcion);
        }

        else
        {
            printf("El total de sueldos del sector %s es %.2f\n", descripcion, acumSueldos);

        }




        todoOk = 1;

    }

    return todoOk;
}





int totalSueldosxIdSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector, float* pTotal)
{
    int todoOk = 0;
    float acumSueldos = 0;


    if(vec != NULL && tam > 0 && sectores != NULL)
    {

        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idSector == idSector)
            {
                acumSueldos +=vec[i].sueldo;
            }
        }

        *pTotal = acumSueldos;

        todoOk = 1;

    }

    return todoOk;
}

//funcion que dice en que sectores es el que mas se paga sueldos.
int sectorMasSueldos(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    //float totales[5]= {0}; // una forma de hacerlo. vector de flotante del mismo tamaño del vector de sectores.
    float totales[tams]; //segunda forma de hacerlo es por extension.
    int flag = 1;
    float mayor;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {
        for(int i = 0; i < tams; i++)
        {
            totales[i]=0;
        }

        for(int i = 0; i < tams; i++)//recoorro el vector de los sectores
        {
            totalSueldosxIdSector(vec, tam, sectores, tams, sectores[i].id, &totales[i]); //cargando en el vector de totales el total de los sueldos.
        }

        for( int i = 0; i<tams; i++) //recorro el vector buscando el mayor.
        {
            if(flag || totales[i]> mayor)
            {
                mayor = totales[i];
                flag= 0;
            }

        }

        printf("sectores/res donde mas total de sueldos se paga: \n");

        for(int i = 0; i <tams; i++)//cuando conozco el mayor recorro el vector de totales y cuando encuentro una posicion donde se
            //guarda el mayor en la misma posicion del sector esta la descripcion del sector que cobra eso entonces lo muestro.
        {

            if(totales[i]==mayor)
            {
                printf("%s\n", sectores[i].descripcion);
            }
        }
        printf("\n\n");
        todoOk = 1;

    }

    return todoOk;
}


//Busca el empleado que mas gana e indica de que sector es
int sectorEmpleadoMasGana(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int flag = 1;
    float sueldoMayor;
    char descripcion[20];

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {
        system("cls");
        printf("   ****Empleado/os y sector que mas gana*****  \n");
        printf("-----------------------------------------------------------\n");

        //hago toda la recorrida para cargar el mayor sueldo quede registrado en la variable sueldoMayor.
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && (flag == 1|| vec[i].sueldo > sueldoMayor))
            {
                sueldoMayor = vec[i].sueldo;
                flag = 0;
            }

        }

        if(flag)
        {
            printf("no hay empleados registrados en el sistema\n");

        }

        else
        {

            printf("El mayor sueldo es $ %.2f y es ganado por: \n", sueldoMayor);
        }

        for(int i = 0; i < tam; i++)
        {
            //recorro el array de empleados para ver que el sueldo mayor guardado se encuentre en ese array.
            if(!vec[i].isEmpty && vec[i].sueldo == sueldoMayor)
            {

                cargarDescripcionSector(sectores, tams, vec[i].idSector, descripcion);
                printf("Nombre %s sector %s\n", vec[i].nombre, descripcion);
            }

        }

        todoOk = 1;

    }

    return todoOk;
}



//no es para se usada directamente sino ayudante de otra funcion. dice el sector donde trabaja mas mujeres.
//recorra el array de empleados de ese sector que tengan ese sexo y cargue por referencia en la variable totaolcuenta el total de empleados por sexo y sector.
int totalEmpleadosXSexoXIdSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector, int* pTotal, char sexo)
{

    int todoOk = 0;
    int contEmpleados = 0;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0 && pTotal != NULL && (sexo == 'm'|| sexo == 'M' || sexo == 'f' || sexo == 'F'))
    {
        system("cls");
        printf("   ****Sector/res donde trabajan mas mujeres*****  \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tam; i++)//recorro el array de empleados
        {

            if(!vec[i].isEmpty && vec[i].idSector == idSector && vec[i].sexo == sexo)//si el empleado no esta vacio y es un empleado que trabaja en el sector que me mandaron a buscar.

            {
                contEmpleados++; //que hago? lo cuento

            }

        }

        *pTotal = contEmpleados;//lo envio por referencia

        todoOk = 1;


    }



    return todoOk;
}





int sectorMasMujeres(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    //int totales[5]= {0}; // una forma de hacerlo. vector de flotante del mismo tamaño del vector de sectores.
    int cantMujeres[tams]; //segunda forma de hacerlo es por extension.
    int flag = 1;
    int mayor;

    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0)
    {
        for(int i = 0; i < tams; i++)
        {
            cantMujeres[i]=0;
        }

        for(int i = 0; i < tams; i++)//recoorro el vector de los sectores
        {
            totalEmpleadosXSexoXIdSector(vec, tam, sectores, tams, sectores[i].id, &cantMujeres[i], 'f'); //tengo la cantidad de mujeres cargadas en mi vector paralelo.
        }

        for( int i = 0; i<tams; i++) //recorro el vector buscando el mayor.
        {
            if(flag || cantMujeres[i]> mayor)
            {
                mayor = cantMujeres[i];
                flag= 0;
            }

        }

        printf("sectores/res donde trabajan %d  mujeres es : \n", mayor);

        for(int i = 0; i <tams; i++)//cuando conozco el mayor recorro el vector de totales y cuando encuentro una posicion donde se
            //guarda el mayor en la misma posicion del sector esta la descripcion del sector que cobra eso entonces lo muestro.
        {

            if(cantMujeres[i]==mayor)
            {
                printf("%s\n", sectores[i].descripcion);
            }
        }
        printf("\n\n");
        todoOk = 1;

    }

    return todoOk;
}




//informa la cantidad de sectores
int empleadosVaronesSector(eEmpleado vec[], int tam, eSector sectores[], int tams)
{
    int todoOk= 0;
    int idSector;
    int total;
    char descripcion [20];

    if( vec != NULL && tam > 0 && sectores != NULL && tams)
    {

        system("cls");
        printf("      ***Informe Empleados Hombres de un sector***      \n");
        printf("------------------------------------------------\n");

        listarSectores(sectores, tams);

        printf("ingrese el id del sector: \n");
        scanf("%d", &idSector);

        while(!validarSector(sectores, tams, idSector))
        {
            printf("id Invalido. Reingrese el id del sector: \n");
            scanf("%d", &idSector);
        }

        totalEmpleadosXSexoXIdSector(vec, tam, sectores, tams, idSector,  &total, 'm');

        cargarDescripcionSector(sectores, tams, idSector, descripcion);

        printf("Total empleados varones sector %s:  %d\n", descripcion, total);



        todoOk = 1;



    }

    return todoOk;
}



int cargarNombreEmpleado(eEmpleado empleados[], int tam, int id, char nombre[])
{
    int todoOk = 0;

    if(empleados != NULL && tam> 0 && nombre != NULL)
    {

        for(int i = 0; i < tam ; i++)
        {

            if(!empleados[i].isEmpty && empleados[i].id == id)//repasar que hace esto.
            {
                strcpy(nombre, empleados[i].nombre);
                todoOk = 1;
                break;

            }
        }

        todoOk = 1;

    }

    return todoOk;
}



//funcion auxiliar de contadores de hombres.//sirve pero falta otra funcion que muestre los empleados.
int cantidadVaronesXSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector, int* pCont)
{
    int todoOk = 0;
    int contadorVarones = 0;


    if(vec != NULL && tam > 0 && sectores != NULL && tams > 0 && pCont != NULL)
    {
        for(int i = 0; i <  tam ; i ++)
        {

            if(!vec[i].isEmpty && (vec[i].idSector == idSector && (vec[i].sexo == 'm' || vec[i].sexo == 'M')))//si el empleado no esta vacio y es un empleado que trabaja en el sector que me mandaron a buscar.

            {
                contadorVarones++; //que hago? lo cuento

            }
        }

        *pCont = contadorVarones;
        todoOk = 1;

    }

    return todoOk;
}



int sexoEmpleadoMenor(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int menorEdad;
    int flag = 1;
    char descripcion[20];

    if( vec != NULL && tam > 0 && sectores != NULL && tam > 0)
    {
        system("cls");
        printf("        *** Sexo empleado menor  ***\n");
        printf("-------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && ( flag || vec[i].edad < menorEdad))
            {
                menorEdad = vec[i].edad;
                flag = 0;
            }
        }

        if(flag)
        {
            printf("No hay empleados registrados en el sistema\n\n");
        }
        else
        {
            printf("La edad del empleado/s menor es: %d \n", menorEdad);


            for(int i=0; i < tam; i++)
            {
                if( !vec[i].isEmpty && vec[i].edad == menorEdad)
                {
                    cargarDescripcionSector(sectores, tamSec, vec[i].idSector, descripcion);
                    printf("Nombre: %s  Sector: %s  Sexo: %c\n", vec[i].nombre, descripcion, vec[i].sexo);
                }
            }
            printf("\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
