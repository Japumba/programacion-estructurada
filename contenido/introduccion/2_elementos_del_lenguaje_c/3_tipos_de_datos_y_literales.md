# Literales y Tipos de datos

## Literales
Distinto a las variables y las palabras reservadas, las literales son símbolos o conjuntos de símbolos que usamos en nuestro programa para acceder a valores constantes.

Por ejemplo, cuando asignamos un `31` a una variable, estamos accediendo al valor `31` a través de una literal decimal.

```c
// El identificador de la variable es 'edad', y se le asigna el valor de la literal decimal 31.
int edad = 31;
```

Además de literales decimales, tenemos de otros tipos: hexadecimal, octal, binaria, de caracter, de texto...

```c
// Estas son asignaciones a una variable, con distintos tipos de literales.

int edad;

edad = 65;       // literal decimal
edad = 0x41;     // literal hexadecimal
edad = 0b1000001 // literal binaria
edad = 'A'       // literal de caracter

// 🔥 Todas las literales anteriores representan el valor 65 decimal 🔥
```

## Tipos de datos
Los tipos de datos nos dicen cómo se _interpreta_ la información guardada en la memoria asociada a una variable.

Podemos decir que existen dos clasificaciones de tipos de datos: Primitivos y Estructurados.

- Los **Primitivos** son aquellos simples, atómicos, que representan datos que no pueden dividirse en partes conservando razonablemente el significado de cada una. Estos son: char, int, float y double.

- Los **Estructurados** son aquellos que están compuestos por varios tipos de datos, primitivos y estructurados. Algunos ejemplos son los arreglos, las matrices, los `struct` y `union`.

### Int
También conocido como enteros o integers, representan datos numéricos sin parte fraccionaria, es decir, números enteros.

Normalmente una variable de tipo int ocupa un espacio en la memoria de 32 bits (4 bytes). Esto lo podemos saber usando el operador de tamaño en C con el tipo de dato: `sizeof(int)`.

Por el tamaño que ocupan en memoria, los ints pueden representar números entre `-2,147,483,648` y `2,147,483,647`.

```c
// Programa ejemplo para conocer los ints
#include <stdio.h>
#include <limits.h> // Librería que contiene los límites de los tipos de datos

int main() {
    printf("Un int ocupa %lu bytes en memoria.\n", sizeof(int));
    printf("El valor mínimo que puede representar un int es %d.\n", INT_MIN);

    // Ejercicio para ti: Imprime el valor máximo que puede representar un int. En lugar de escribir directamente el valor, usa la constante disponible en la librería limits.h

    return 0;
}

```

