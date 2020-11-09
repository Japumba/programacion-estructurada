#include <stdio.h>

/**
 * INTRODUCTION:
 * En este ejercicio trabajarás con estructuras y funciones diseñadas
 * para representar horas y fechas.
 * 
 * INSTRUCCIONES:
 * 
 * 1. Primero que nada, este código base tiene un bug al imprimir la fecha.
 * 
 *    Lee el código y compílalo. Apunta aqui los warnings que obtengas y trata de explicarlos.
 *    =
 * 
 *   Luego, corrige el bug de la impresión de la fecha.
 * 
 * 
 * 2. Agrega un typedef a struct_date de tal forma que podamos referirnos y usarlo como Date;
 *   
 * 3. Modifica el programa para que use Date en lugar de struct struct_date.
 *    A partir de ahora, procura usar typedefs para tus estructuras y enums.
 * 
 * 4. Crea un tipo estructura con el typedef Time, que contenga los siguientes campos:
 *    – hora,    entero de [0 a 23]
 *    – minuto,  entero de [0 a 59]
 *    – segundo, real   de [0 a 60), con al menos 8 decimales de precision por favor.
 *    – timezone, strings de hasta 6 caracteres con el codigo de la zona horaria
 *      (ejemplos aqui: https://www.timeanddate.com/time/zones/)
 * 
 *    Nota: Usa el tipo de dato que ocupe menos espacio.
 * 
 * 5. Crea una función void printTime(Time hora),
 *    que reciba un valor de tipo Time y lo imprima en la consola
 *    en formato hh:mm:ss.ssss (TMZ)
 *    donde TMZ son las 3 letras de la zona horaria
 * 
 *    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *    Agrega al main varios ejemplos
 *    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 * 6. Crea un tipo estructura con el typedef DateTime, que tenga dos campos:
 *    – Date fecha
 *    – Time hora
 * 
 *    observa como estos dos campos son cada una de un tipo estructura (structs anidados)
 * 
 * 7. Crea una funcion void printDateTime(DateTime fechahora)
 *    que reciba un valor de tipo DateTime y lo imprima en
 *    la consola con el siguiente formato:
 *    
 *    dd/mm/yyyy hh:mm:ss.ssss (TMZ)
 * 
 *    Asegúrate que la función printDateTime() mande llamar a las otras dos funciones, pasando
 *    correctamente como parámetro los campos.
 *    – printDate()
 *    – printTime()
 * 
 *    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *    Agrega al main varios ejemplos
 *    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 */

/**
 * EJERCICIO 2:
 * Agrega el typedef a esta estructura
 */
struct struct_date
{
    int day, month, year;
};

void printDate(struct struct_date date);

/**
 * EJERCICIO 4:
 * Crea aqui tu estructura con typedef Time,
 * que contenga todos los campos requeridos
 */

/**
 * EJERCICIO 5:
 * Declara e implementa aquí la función printTime
 */

/**
 * EJERCICIO 6:
 * Crea aqui tu estructura con typedef DateTime,
 * que contenga todos los campos requeridos
 */

/**
 * EJERCICIO 5:
 * Declara e implementa aquí la función printDateTime
 */

int main()
{
    struct struct_date today = {9, 10, 2020};
    printf("Today is ");
    printDate(today);
    printf("\n");

    struct struct_date christmas = {25, 12, 2020};
    printf("Christmas is on ");
    printDate(christmas);
    printf("\n");

    /**
     * EJERCICIO 5:
     * Agrega aqui ejemplos de horas con tu funcion printTime
     */

    /**
     * EJERCICIO 7:
     * Agrega aqui ejemplos de fechahoras con tu funcion printDateTime
     */
}

// Imprime una fecha en formato
// dd/mm/yyyy
void printDate(struct struct_date date)
{
    printf("%i/%2i/%i", date);
}