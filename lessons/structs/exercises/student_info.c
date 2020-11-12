/**
 * INTRODUCTION:
 * Imagina una base de datos. No haremos realmente una, pero tomaremos conceptos de ahi.
 * 
 * Este es un sistema de Estudiantes, en el que hay dos tablas:
 * Estudiante: es la informacion de cada uno de los estudiantes
 * 
 * Materias: son todas las materias, relacionadas con el estudiante
 * 
 * INSTRUCCIONES:
 * 1. Declara una estructura con typedef Student, que tenga la siguiente informacion:
 *    - id: numero entero
 *    – nombre: string de 30 caracteres
 *    – matricula: string de 9 caracteres, ejemplo: "IS-677549"
 * 
 * 2. Crea un arreglo de Student, global, e inicialízalos con esta informacion:
 * 
 * | id | nombre            | matricula |
 * |  1 | Javier de la Mora | IS-677549 |
 * |  2 | Raquel Fernandez  | AE-278554 |
 * |  3 | Andros Garcia     | IE-456832 |
 * |  4 | Estefany Cruz     | DN-579264 |
 * 
 * 3. Escribe una funcion mostarUsuario(id), que reciba el id del usuario y
 *    muestre su informacion y sus materias:
 *
 *    Ejemplo:
 *    mostrarEstudiante(1) // imprime
 *    
 *    Javier de la Mora (IS-677549)
 *    - Matematicas [7]
 *    - Algebra [8]
 *    - Logica [7]
 */

#include <stdio.h>

// Una materia cursada por un usuario
typedef struct student_materia
{
    int student_id;
    char materia[20];
    int calificacion;
} Student_Materia;

#define TABLA_STUDENT_MATERIAS_LENGTH 10
// GLOBAL: lista de materias llevadas por estudiantes
Student_Materia tabla_student_materias[TABLA_STUDENT_MATERIAS_LENGTH] = {
    {1, "Matematicas", 7},
    {2, "Historia", 10},
    {3, "Geografia", 8},
    {4, "Matematicas", 9},

    {1, "Algebra", 8},
    {2, "Arte", 10},
    {3, "Taller", 9},
    {4, "Filosofia", 9},

    {1, "Logica", 7},
    {2, "Ciencias", 5},
};

void printAllStudentMaterias();

int main()
{
    printAllStudentMaterias();
}

void printAllStudentMaterias()
{
    printf("user_id : materia : calificacion\n");
    for (size_t i = 0; i < TABLA_STUDENT_MATERIAS_LENGTH; i++)
    {
        printf("%i : %s : %i\n", tabla_student_materias[i].student_id, tabla_student_materias[i].materia, tabla_student_materias[i].calificacion);
    }
}