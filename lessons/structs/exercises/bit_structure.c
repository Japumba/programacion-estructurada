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
 * 1. Compila y ejecuta el codigo. Observa el tamaño actual de la estructura User.
 * 
 * 2. Modifica la estructura, usando campos de bits, para que no pase del tamaño deseado
 * 
 * 3. 
 */

#define MAX_DESIRED_STRUCT_SIZE 5

enum ESTATUS_ACADEMICO
{
  NO_INSCRITO,
  ACTIVO,
  SUSPENDIDO,
  DADO_DE_BAJA
};

typedef struct
{
  unsigned char es_admin;        // 0 = false, 1 = true
  unsigned char departamento_id; // 0 = DESI, 1 = DPTI, 2 = DMAF, 3 = DIA, 4 = DEAM, 5 = DFIH
  unsigned char estatus_academico;
  unsigned char tiene_acceso_estacionamiento; // 0 = false, 1 = true
  unsigned char tiene_acceso_laboratorios;    // 0 = false, 1 = true
  unsigned int matricula;
} User;

void printUser(User u);

int main()
{
  User user1 = {
      0, // false
      2, // DMAF
      ACTIVO,
      0, // false
      1, // true
      677549};

  printUser(user1);

  /* validate struct size for exercise */
  unsigned long size = sizeof(User);

  if (size <= MAX_DESIRED_STRUCT_SIZE)
  {
    printf("\nExcelente!\nTu estructura tiene %lu byte(s), no pasa de %i byte(s).", size, MAX_DESIRED_STRUCT_SIZE);
  }
  else
  {
    printf("\nError en el ejercicio!\nDebe ser un tamano menor a %i byte, pero es de %lu bytes.", MAX_DESIRED_STRUCT_SIZE, size);
    exit(-1);
  }
}

void printUser(User u)
{
  printf("usuario [%u]\n", u.matricula);
}