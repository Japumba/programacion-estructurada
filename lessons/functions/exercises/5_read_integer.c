#include <stdio.h>

/**
 * –– INSTRUCCIONES ––
 *
 * 1) Ejecuta el código; nota cómo no se pide nada al usuario.
 * 
 * 2) Completa la funcion readInteger(), para que lea el numero
 *    del usuario y lo regrese.
 * 
 * 3) Ejecuta nuevamente el programa y asegúrate que se está
 *    leyendo bien el dato.
 */


/**
 * Escribe un mensaje pidiendo al usuario introducir un
 * valor entero, lo lee de la consola y lo regresa.
 * 
 * No recibe ningun parametro.
 * 
 * @returns el valor introducido por el usuario.
 */
int readInteger()
{
    int number = 42;

    return number;
}

int main()
{
    int my_number = readInteger();

    printf("Se ha introducido: %i\n", my_number);
}