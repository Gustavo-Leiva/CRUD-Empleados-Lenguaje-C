#include "fecha.h"
#include "empleado.h"


#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{

int id;
int idEmpleado;
int idComida;
eFecha fecha;
int isEmpty;




}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED


int inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int buscarLibreAlmuerzo (eAlmuerzo vec[], int tamc, int* pIndex);
int altaAlmuerzo (eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tams, eComida comidas[], int tamc,  int* pNextId);
int mostrarAlmuerzoFila(eAlmuerzo almuerzos, eEmpleado empleados[], int tam, eComida comida[], int tamc);
int listarAlmuerzos (eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eSector sectores[], int tams, eComida comidas[], int tamc);
int harcodearAlmuerzos(eAlmuerzo vec[], int tam, int cant, int* pNextId);
int totalAPagarEmpleado(eAlmuerzo almuerzos[], int tama, eEmpleado empleados[], int tam, eComida comidas[], int tamc, eSector sectores[], int tams);
