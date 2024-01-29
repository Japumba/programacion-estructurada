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

ASCII tiene caracteres imprimibles, como la 'A' y el espacio (' ') y otros no imprimibles como NULL o 

| Decimal | Binario    | Hexadecimal | Carácter | Imprimible | Descripción                |
|---------|------------|-------------|----------|------------|----------------------------|
| 0       | 00000000   | 00          |       | No         | Null char (NUL) |
| 1       | 00000001   | 01          |       | No         | Start of Header (SOH) |
| 2       | 00000010   | 02          |       | No         | Start of Text (STX) |
| 3       | 00000011   | 03          |       | No         | End of Text (ETX) |
| 4       | 00000100   | 04          |       | No         | End of Transmission (EOT) |
| 5       | 00000101   | 05          |       | No         | Enquiry (ENQ) |
| 6       | 00000110   | 06          |       | No         | Acknowledge (ACK) |
| 7       | 00000111   | 07          |       | No         | Bell (BEL) |
| 8       | 00001000   | 08          |       | No         | Backspace (BS) |
| 9       | 00001001   | 09          |       | No         | Horizontal Tab (HT) |
| 10       | 00001010   | 0A          |       | No         | Line Feed (LF) |
| 11       | 00001011   | 0B          |       | No         | Vertical Tab (VT) |
| 12       | 00001100   | 0C          |       | No         | Form Feed (FF) |
| 13       | 00001101   | 0D          |       | No         | Carriage Return (CR) |
| 14       | 00001110   | 0E          |       | No         | Shift Out / X-On (SO) |
| 15       | 00001111   | 0F          |       | No         | Shift In / X-Off (SI) |
| 16       | 00010000   | 10          |       | No         | Data Line Escape (DLE) |
| 17       | 00010001   | 11          |       | No         | Device Control 1 (oft. XON) (DC1) |
| 18       | 00010010   | 12          |       | No         | Device Control 2 (DC2) |
| 19       | 00010011   | 13          |       | No         | Device Control 3 (oft. XOFF) (DC3) |
| 20       | 00010100   | 14          |       | No         | Device Control 4 (DC4) |
| 21       | 00010101   | 15          |       | No         | Negative Acknowledge (NAK) |
| 22       | 00010110   | 16          |       | No         | Synchronous Idle (SYN) |
| 23       | 00010111   | 17          |       | No         | End of Transmit Block (ETB) |
| 24       | 00011000   | 18          |       | No         | Cancel (CAN) |
| 25       | 00011001   | 19          |       | No         | End of Medium (EM) |
| 26       | 00011010   | 1A          |       | No         | Substitute (SUB) |
| 27       | 00011011   | 1B          |       | No         | Escape (ESC) |
| 28       | 00011100   | 1C          |       | No         | File Separator (FS) |
| 29       | 00011101   | 1D          |       | No         | Group Separator (GS) |
| 30       | 00011110   | 1E          |       | No         | Record Separator (RS) |
| 31       | 00011111   | 1F          |       | No         | Unit Separator (US) |
| 32       | 00100000   | 20          |        | Sí         | Space (SP) |
| 33       | 00100001   | 21          | !      | Sí         |  |
| 34       | 00100010   | 22          | "      | Sí         |  |
| 35       | 00100011   | 23          | #      | Sí         |  |
| 36       | 00100100   | 24          | $      | Sí         |  |
| 37       | 00100101   | 25          | %      | Sí         |  |
| 38       | 00100110   | 26          | &      | Sí         |  |
| 39       | 00100111   | 27          | '      | Sí         |  |
| 40       | 00101000   | 28          | (      | Sí         |  |
| 41       | 00101001   | 29          | )      | Sí         |  |
| 42       | 00101010   | 2A          | *      | Sí         |  |
| 43       | 00101011   | 2B          | +      | Sí         |  |
| 44       | 00101100   | 2C          | ,      | Sí         |  |
| 45       | 00101101   | 2D          | -      | Sí         |  |
| 46       | 00101110   | 2E          | .      | Sí         |  |
| 47       | 00101111   | 2F          | /      | Sí         |  |
| 48       | 00110000   | 30          | 0      | Sí         |  |
| 49       | 00110001   | 31          | 1      | Sí         |  |
| 50       | 00110010   | 32          | 2      | Sí         |  |
| 51       | 00110011   | 33          | 3      | Sí         |  |
| 52       | 00110100   | 34          | 4      | Sí         |  |
| 53       | 00110101   | 35          | 5      | Sí         |  |
| 54       | 00110110   | 36          | 6      | Sí         |  |
| 55       | 00110111   | 37          | 7      | Sí         |  |
| 56       | 00111000   | 38          | 8      | Sí         |  |
| 57       | 00111001   | 39          | 9      | Sí         |  |
| 58       | 00111010   | 3A          | :      | Sí         |  |
| 59       | 00111011   | 3B          | ;      | Sí         |  |
| 60       | 00111100   | 3C          | <      | Sí         |  |
| 61       | 00111101   | 3D          | =      | Sí         |  |
| 62       | 00111110   | 3E          | >      | Sí         |  |
| 63       | 00111111   | 3F          | ?      | Sí         |  |
| 64       | 01000000   | 40          | @      | Sí         |  |
| 65       | 01000001   | 41          | A      | Sí         |  |
| 66       | 01000010   | 42          | B      | Sí         |  |
| 67       | 01000011   | 43          | C      | Sí         |  |
| 68       | 01000100   | 44          | D      | Sí         |  |
| 69       | 01000101   | 45          | E      | Sí         |  |
| 70       | 01000110   | 46          | F      | Sí         |  |
| 71       | 01000111   | 47          | G      | Sí         |  |
| 72       | 01001000   | 48          | H      | Sí         |  |
| 73       | 01001001   | 49          | I      | Sí         |  |
| 74       | 01001010   | 4A          | J      | Sí         |  |
| 75       | 01001011   | 4B          | K      | Sí         |  |
| 76       | 01001100   | 4C          | L      | Sí         |  |
| 77       | 01001101   | 4D          | M      | Sí         |  |
| 78       | 01001110   | 4E          | N      | Sí         |  |
| 79       | 01001111   | 4F          | O      | Sí         |  |
| 80       | 01010000   | 50          | P      | Sí         |  |
| 81       | 01010001   | 51          | Q      | Sí         |  |
| 82       | 01010010   | 52          | R      | Sí         |  |
| 83       | 01010011   | 53          | S      | Sí         |  |
| 84       | 01010100   | 54          | T      | Sí         |  |
| 85       | 01010101   | 55          | U      | Sí         |  |
| 86       | 01010110   | 56          | V      | Sí         |  |
| 87       | 01010111   | 57          | W      | Sí         |  |
| 88       | 01011000   | 58          | X      | Sí         |  |
| 89       | 01011001   | 59          | Y      | Sí         |  |
| 90       | 01011010   | 5A          | Z      | Sí         |  |
| 91       | 01011011   | 5B          | [      | Sí         |  |
| 92       | 01011100   | 5C          | \      | Sí         |  |
| 93       | 01011101   | 5D          | ]      | Sí         |  |
| 94       | 01011110   | 5E          | ^      | Sí         |  |
| 95       | 01011111   | 5F          | _      | Sí         |  |
| 96       | 01100000   | 60          | `      | Sí         |  |
| 97       | 01100001   | 61          | a      | Sí         |  |
| 98       | 01100010   | 62          | b      | Sí         |  |
| 99       | 01100011   | 63          | c      | Sí         |  |
| 100       | 01100100   | 64          | d      | Sí         |  |
| 101       | 01100101   | 65          | e      | Sí         |  |
| 102       | 01100110   | 66          | f      | Sí         |  |
| 103       | 01100111   | 67          | g      | Sí         |  |
| 104       | 01101000   | 68          | h      | Sí         |  |
| 105       | 01101001   | 69          | i      | Sí         |  |
| 106       | 01101010   | 6A          | j      | Sí         |  |
| 107       | 01101011   | 6B          | k      | Sí         |  |
| 108       | 01101100   | 6C          | l      | Sí         |  |
| 109       | 01101101   | 6D          | m      | Sí         |  |
| 110       | 01101110   | 6E          | n      | Sí         |  |
| 111       | 01101111   | 6F          | o      | Sí         |  |
| 112       | 01110000   | 70          | p      | Sí         |  |
| 113       | 01110001   | 71          | q      | Sí         |  |
| 114       | 01110010   | 72          | r      | Sí         |  |
| 115       | 01110011   | 73          | s      | Sí         |  |
| 116       | 01110100   | 74          | t      | Sí         |  |
| 117       | 01110101   | 75          | u      | Sí         |  |
| 118       | 01110110   | 76          | v      | Sí         |  |
| 119       | 01110111   | 77          | w      | Sí         |  |
| 120       | 01111000   | 78          | x      | Sí         |  |
| 121       | 01111001   | 79          | y      | Sí         |  |
| 122       | 01111010   | 7A          | z      | Sí         |  |
| 123       | 01111011   | 7B          | {      | Sí         |  |
| 124       | 01111100   | 7C          | |      | Sí         |  |
| 125       | 01111101   | 7D          | }      | Sí         |  |
| 126       | 01111110   | 7E          | ~      | Sí         |  |
| 127       | 01111111   | 7F          |       | No         | Delete (DEL) |


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

