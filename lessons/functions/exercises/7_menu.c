#include <stdio.h>

/**
 * –– INSTRUCCIONES ––
 * 
 * 1) Crea una función void printMenu() que contenga el código que imprime el menú,
 *    y modifica el programa para que la use.
 * 
 * 2) Agrega una opción al menu, que sea Elevar a una potencia
 * 
 * 3) Agrega el manejo de esa opción, luego del if que ya existe, lea dos numeros
 *    e imprima el resultado del primero elevado a la potencia del segundo
 *    Para esto, utiliza la función double pow(double x, double y) de la libreria math.h
 *       https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm
 * 
 * 4) Agrega una opción al menu que sea Salir. Esta opción no hace nada todavia.
 * 
 * 5) Envuelve el código en un do–while, para que se pidan opciones hasta que
 *    el usuario eliga la opción Salir.
 *    
 *    ¡Que el Adios quede fuera del ciclo!
 * 
 * 6) Agrega el código necesario para que, si el usuario ingresa una opción inválida,
 *    le imprima un mensaje y no haga nada, simplemente pasando a preguntar nuevamente.
 * 
 * 7) Crea una función int pedirOpcion(), que tenga el código de seleccionar una opción,
 *    y modifica el programa para que, en main, se utilice esta función.
 *    tip: revisa el ejercicio 5_read_integer.c
 */

int main()
{
    printf("--[ Opciones ]--\n");
    printf("  1) Decir hola\n");

    printf("\n");

    int opcion;
    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    if (opcion == 1)
    {
        printf("Wololo!\n");
    }

    printf("\nAdios!\n");
}