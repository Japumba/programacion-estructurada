#include <stdio.h>
#include <stdlib.h>

/**
 * INTRODUCTION:
 * Las estructuras de bits nos permiten reducir el uso de memoria para ciertos casos.
 * 
 * En el siguiente ejercicio, debes modificar el código para usar como máximo
 * la memoria indicada en User, manteniendo la información de la estructura.
 * 
 * INSTRUCCIONES:
 */

#define MAX_DESIRED_STRUCT_SIZE 1

typedef struct {
  unsigned char es_admin; // 0 = false, 1 = true
  unsigned char departamento_id; // 0 = DESI, 1 = DPTI, 2 = DMAF, 3 = DIA, 4 = DEAM, 5 = DFIH
  unsigned char estatus_academico; // 0 = NO INSCRITO, 1 = ACTIVO, 2 = SUSPENDIDO, 3 = DADO DE BAJA
  unsigned char tiene_acceso_estacionamiento; // 0 = false, 1 = true
  unsigned char tiene_acceso_laboratorios; // 0 = false, 1 = true
} User;

int main()
{
  /* validate struct size for exercise */
  unsigned long size = sizeof(User);

  if(size > MAX_DESIRED_STRUCT_SIZE){
    printf("Error en el ejercicio!\nDebe ser un tamano menor a %i byte, pero es de %lu bytes.", MAX_DESIRED_STRUCT_SIZE, size);
    exit(-1);
  }
}