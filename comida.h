#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eComida;

#endif // COMIDA_H_INCLUDED
int cargarDescripcionComida (eComida comidas[], int tamc, int id, char desc[]);
int listarComidas (eComida comidas[], int tamc);
int buscarComida(eComida comidas[], int tamc, int id, int* pIndex);
int validarComida(eComida comidas[], int tamc, int id);
