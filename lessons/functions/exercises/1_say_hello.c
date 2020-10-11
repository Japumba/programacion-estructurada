#include <stdio.h>

/** –– INSTRUCCIONES ––
 *
 * 1) Ejecuta el código y compara lo esperado contra lo obtenido.
 * 
 * 2) Completa la función sayHello para que coincida el resultado.
 */


/**
 * Imprime "Hello!" en la consola con un salto de linea
 * 
 * No recibe ningun parametro, ni regresa ningun valor.
 * No es necesario tener un return al final, porque es de tipo void.
 */
void sayHello()
{
}

int main()
{
    printf("--[ Salida esperada ]--\n");
    printf("Hola!\nHola!\nHola!\nHola!\n");
    printf("\n");

    printf("--[ Resultado obtenido ]--\n");
    sayHello();
    sayHello();
    sayHello();
    sayHello();
}