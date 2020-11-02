/**
 * INTRODUCTION:
 * Siempre batallamos con crear equipos en el salón.
 * Ahí anda el profesor viendo quien sí y quien no, buscando en google dos numeros
 * aleatorios para hacer parejas.
 * 
 * Su objetivo es hacer un programa que tome dos nombres distintos de una lista de
 * nombres y los imprima, de tal forma que nos de un equipo aleatorio.
 * 
 * INSTRUCCIONES:
 * 1. Inicializa la variable alumnos con al menos 10 nombres distintos.
 *    Cada nombre podrá tener como máximo 20 letras.
 *
 * 2. Crea una función para obtener un número en rango; puedes usar o basarte
 *    en la de la actividad anterior: 5_random_name.c
 * 
 * 3. Crea una función que, usando la funcion del paso 2, imprima en la pantalla
 *    un equipo de dos personas distintas de la lista.
 * 
 *    Esta función deberá recibir:
 *      – la lista de nombres de la que puede elegir
 *      – la cantidad de nombres que tiene la lista
 * 
 *    ¡Asegúrate que sean dos alumnos distintos! La función de aleatorio podría
 *    regresarte dos veces el mismo valor, ¿cómo harás para que no sea repetido?
 * 
 *    Para probar este escenario, puedes poner solamente dos nombres en la lista;
 *    esto dará una probabilidad alta de que se repita el número aleatorio y apareza
 *    un equipo como:
 *    - Gandalf the white
 *    - Gandalf the white
 */

#include <stdio.h>

unsigned int randomIntegerFromZeroUpTo(unsigned int max)
{
    return 42;
}

int main()
{
    char alumnos[][21] = {};

    return 0;
}