#include <assert.h>
#include <stdio.h>

/**
 * INSTRUCCIONES
 * 
 * Declara un arreglo de 5 elementos que se llame mi_arrelgo,
 * que tenga los siguientes valores, en este orden:
 *   31,000
 *   12,324
 *   0
 *   30
 *   -4
 * 
 * usa el tipo de dato mas pequeño posible.
 */

int main()
{
    // declara tu arreglo aqui

    assert(sizeof(mi_arreglo) == 10);
    printf("OK: Elegiste el tipo correcto y el numero de elementos adecuado.\n");

    
    // assert es una herramienta que podemos utilizar para agregar pruebas a nuestros programas.
    // lo que hace es comprobar si una condición es verdadera.
    //   si la condición es verdadera, el código continúa sin nada
    //   si no es cierta, el programa termina con un mensaje de Abort.
    
    // assert nos funciona para probar cosas pequeñas, veremos cómo hacer pruebas más complejas.
    assert(mi_arreglo[0] == 31000);
    assert(mi_arreglo[1] == 12324);
    assert(mi_arreglo[2] == 0);
    assert(mi_arreglo[3] == 30);
    assert(mi_arreglo[4] == -4);
    printf("OK: Los elementos estan en el orden adecuado\n");

    printf("Ejercicio terminado correctamente!\n");
    return 0;
}
