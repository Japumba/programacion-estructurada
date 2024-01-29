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

Dependiendo del tipo de dato de una variable o una literal, se podrán realizar distintas operaciones y se le podrá asignar valores diferentes.

### Char
El tipo de dato char representa un caracter. Un caracter es un símbolo que puede ser impreso en pantalla, como una letra, un número, un signo de puntuación, un espacio, etc.

```c
#include <stdio.h>

int main() {
    char letra = 'A'; // asignamos a la variable letra, de tipo char, el valor de la literal 'A'.

    printf("La letra es %c\n", letra); // imprimimos un caracter con %c (la c de char)

    return 0;
}
```

En la memoria de la computadora todo son unos y ceros, en binario; por lo tanto, un caracter como `'A'` es la interpretación de un número como una letra del alfabeto. ¿Que número es el que representa la letra `'A'`? Averiguemos con código cuál es el número que representa la letra `'A'` en la codificación ASCII.

```c
#include <stdio.h>

int main() {
    char letra = 'A'; // asignamos a la variable letra, de tipo char, el valor de la literal 'A'.

    printf("La letra es %c\n", letra); // imprimimos un caracter con %c (la c de char)

    // Imprimimos el valor de la variable letra, pero con %d (la d de decimal) para ver su valor numérico.
    printf("El valor de la variable letra es %d\n", letra);

    return 0;
}
```

En C, el tipo de codificación que se usa por defecto es **ASCII**, y en ASCII la letra `'A'` se representa con el número `65`. Otras codificaciones que existen son UTF-8 y UTF-16, por mencionar algunas.

ASCII tiene caracteres imprimibles, como la 'A' y el espacio (' ') y otros no imprimibles como NULL o NEW_LINE.

[Ver toda la tabla ASCII](https://www.asciitable.com/)

### Int
También conocido como enteros o integers, representan datos numéricos sin parte fraccionaria, es decir, números enteros.

Normalmente una variable de tipo int ocupa un espacio en la memoria de 32 bits (4 bytes). Esto lo podemos saber usando el operador de tamaño en C con el tipo de dato: `sizeof(int)`.

Por el tamaño que ocupan en memoria, los ints pueden representar números entre `-2,147,483,648` y `2,147,483,647`.

```c
// Programa ejemplo para conocer los ints
#include <stdio.h>
#include <limits.h> // Librería que contiene los límites de los tipos de datos

int main() {
    printf("Un int ocupa %d bytes en memoria.\n", sizeof(int));
    printf("El valor mínimo que puede representar un int es %d.\n", INT_MIN);

    return 0;
}

```

### Float
Los números de punto flotante, o floats, son números que tienen parte entera y parte decimal. Por ejemplo, `3.1416` es un float. Normalmente una variable de tipo float ocupa un espacio en la memoria de 32 bits (4 bytes):

```c
// Programa ejemplo para conocer los floats
#include <stdio.h>

int main() {
    printf("Un float ocupa %lu bytes en memoria.\n", sizeof(float));

    float pi = 3.1416;
    printf("El valor aproximado de pi es %f.\n", pi);

    return 0;
}

```

El valor mínimo que puede representar un float es `1.175494e-38` y el valor máximo es `3.402823e+38`.

Por la forma en que se representan en memoria, los numeros con punto flotante no son exactos, sino que tienen un grado de precisión que se especifica en posiciones decimales. Un float tiene una precisión de 6 o 7 posiciones decimales. Esta precisión nos deja confiar en una cantidad de posiciones decimales, y a partir de ahí podría haber erroes de redondeo.

```c
// Programa ejemplo para conocer los floats
#include <stdio.h>

int main() {
    printf("Un float ocupa %lu bytes en memoria.\n", sizeof(float));

    float pi = 3.14159265358979323846;
    printf("El valor aproximado de pi es %f\n", pi);

    return 0;
}

```

### Double
Los números de punto flotante de doble precisión, o doubles, son números que tienen parte entera y parte decimal. Por ejemplo, `3.14159265358979323846` es un double. Normalmente una variable de tipo double ocupa un espacio en la memoria de 64 bits (8 bytes).

Se les llama double porque tienen el doble de precisión que los floats, es decir, 15 posiciones decimales.

```c
// Programa ejemplo para conocer los doubles
#include <stdio.h>

int main() {
    printf("Un double ocupa %lu bytes en memoria.\n", sizeof(double));

    double pi = 3.14159265358979323846;
    printf("El valor aproximado de pi es %f\n", pi);
    printf("El valor aproximado de pi a 10 decimales es %.10f\n", pi); // si queremos que imprima más decimales, podemos usar %.10f, cambiando el 10 por la cantidad que queremos.

    return 0;
}

```

