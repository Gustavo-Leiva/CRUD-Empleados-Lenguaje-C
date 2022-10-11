#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

#endif // SECTOR_H_INCLUDED


int cargarDescripcionSector (eSector sectores[], int tam, int id, char desc[]);
int listarSectores (eSector sectores [], int tam);
int buscarSector(eSector vec[], int tams, int id, int* pIndex);
int validarSector(eSector vec[], int tams, int id);
