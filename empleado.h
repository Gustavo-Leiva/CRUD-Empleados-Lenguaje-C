#include "fecha.h"
#include "sector.h"
#include "comida.h"


#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED




typedef struct
{
    int id;
    char nombre [20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;


#endif // EMPLEADO_H_INCLUDED


//ordenamiento
int ordenarEmpleadosSexoId(eEmpleado vec[], int tam);
int ordenarEmpleados(eEmpleado vec[], int tam);
//int ordenarEmpleadosSexoNombre (eEmpleado vec[], int tam);  pendiente hacer




//abm Empleados
int altaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams, int* pNextId);
int bajaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams);
int modificarEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tams);




//prototipos informes
int listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tams);
int promedioSueldos(eEmpleado vec[], int tam);
int informeEmpleadosMayor(eEmpleado vec[], int tam, eSector sectores[], int tams);
int listarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tams);
int empleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tams);
int empleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tams);
int empleadosXIdSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector);
int totalSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tams);
int totalSueldosxIdSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector, float* pTotal);
int sectorMasSueldos (eEmpleado vec[], int tam, eSector sectores[], int tams);
int sectorEmpleadoMasGana(eEmpleado vec[], int tam, eSector sectores[], int tams);
int sectorMasSueldos (eEmpleado vec[], int tam, eSector sectores[], int tams);
int sectorMasMujeres(eEmpleado vec[], int tam, eSector sectores[], int tams);
int cantidadVaronesXSector(eEmpleado vec[], int tam, eSector sectores[], int tams, int idSector, int* pCont);
int empleadosVaronesSector(eEmpleado vec[], int tam, eSector sectores[], int tams);
int sexoEmpleadoMenor(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

//de que sector es el empleado que mas gana.
//sector donde trabajan mas mujeres.
//cantidad de varones de un sector.



int harcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pNextId);
int cargarEmpleado(eEmpleado* pEmpleado);
int inicializarEmpleados(eEmpleado vec[], int tam);
int cargarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tams);
void mostrarEmpleadoFila(eEmpleado emp, eSector sectores[], int tams);


int menuEmpleados();
int buscarLibre (eEmpleado vec[], int tam, int* pIndex);
int buscarEmpleado (eEmpleado vec[], int tam, int id, int* pIndex);
int menuModificarEmpleado();
int confirmarCarga (char* x);

int validarEmpleado (eEmpleado empleados[], int tam, int id);
int cargarNombreEmpleado(eEmpleado empleados[], int tam, int id, char nombre[]);



