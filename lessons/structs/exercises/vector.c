#include <stdio.h>

void testMagnitudeV3D();
void testDotProductV3D();

/**
 * INTRODUCTION:
 * 
 * INSTRUCCIONES:
 * 1. Define una estructura struct structVector3D
 *    que almacene 3 numeros reales de 64 bits.
 * 
 * 2. Asignale un nuevo nombre, usando typedef,
 *    para que se llame Vector3D
 * 
 * 3. Implementa la funcion double magnitudeV3D()
 *    que recibe un Vector3D y devuelve la magnitud de este vector.
 * 
 *    Modifica los valores del vector en la funcion testMagnitudeV3D
 *    y comprueba los resultados con esta calculadora:
 *    https://onlinemschool.com/math/assistance/vector/length/
 * 
 * 4. Declara e implementa una funcion double dotProductV3D()
 *    que reciba dos Vector3D y devuelva el producto punto de estos vectores.
 * 
 *    Modifica los valores del vector en la funcion testDotProductV3D
 *    y comprueba los resultados con esta calculadora:
 *    https://onlinemschool.com/math/assistance/vector/multiply/
 */

/**
 * EJERCICIO 1 y 2:
 * Define aqui el struct y luego asignale el nombre con typedef
 */


// Calcula y devuelve la magnitud del Vector3D
double magnitudeV3D(Vector3D v)
{
    /**
     * EJERCICIO 3:
     * Implementa la funcion para obtener la magnitud de v
     */
}

/**
 * EJERCICIO 4:
 * declara e implementa la funcion DotProduct
 */

int main()
{
    testMagnitudeV3D();
    testDotProductV3D();
}

void testMagnitudeV3D()
{
    printf("-- Magnitude Vector 3D--\n");
    printf("    El resultado obtenido podria variar un poco, por la precision\n");

    Vector3D v1 = {3, 2, -4};
    double magnitudeV1 = magnitudeV3D(v1);

    printf("    obtenido:            %lf\n", magnitudeV1);
    printf("    esperado aproximado: %lf\n", 5.385164807134504);
    printf("\n");
}

void testDotProductV3D()
{
    printf("-- Dot Product Vector 3D --\n");
    printf("    El resultado obtenido podria variar un poco, por la precision\n");

    Vector3D v1 = {4, 5, 6};
    Vector3D v2 = {-3, 10, 2};
    double dotProduct = dotProductV3D(v1, v2);

    printf("    obtenido:            %lf\n", dotProduct);
    printf("    esperado aproximado: %lf\n", 50.0);
    printf("\n");
}