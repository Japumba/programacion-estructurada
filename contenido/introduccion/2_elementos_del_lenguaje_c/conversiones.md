# Conversiones entre tipos
Al existir distintos tipos de datos, invariablemente nos toparemos con la necesidad de convertir de uno a otro, o de al menos saber cómo se comportan al interactuar entre ellos.

Hay dos tipos de conversión: implícita y explícita.

## Conversión implícita
La conversión implícita es la que realiza el compilador de forma automática, sin que el programador tenga que indicárselo.

Cuando vemos la conversión implícita en una operación, ésta sucede en orden de jerarquía, es decir, el tipo de dato con jerarquía menor es convertido al tipo de dato con jerarquía mayor.

A continuación se muestra la jerarquía de los tipos de datos en C:

| Jerarquía, de mayor a menor |
|-----------------------------|
| `long double`               |
| `double`                    |
| `float`                     |
| `unsigned long long`        |
| `(signed) long long`        |
| `unsigned long`             |
| `(signed) long`             |
| `unsigned int`              |
| `(signed) int`              |
| `unsigned short`            |
| `(signed) short`            |
| `unsigned char`             |
| `(signed) char`             |

Ejemplos:
```c
int a = 5;
float b = 5.14;

float c = a + b; // el int se promociona a float.
```

La conversión implícita podemos también verla en una **asignación**. Este caso, el tipo de dato del lado derecho se convierte al tipo de dato del lado izquierdo, haciendo lo que sea necesario entre una promoción y una degradación.

```c
int a = 5.0; // el double de la derecha se degrada a int.
float b = 5; // el int de la derecha se promociona a float.
```

Luego, podemos verlas combinadas! En una operación, y luego en una asignación.

```c
#include <stdio.h>

int main()
{
    int a = 5;
    long double b = 5.123456789012345;

    float c = a + b; // primero, el int se promociona a float, y luego el resultado se degrada a float, perdiendo presición.

    printf("b: %0.15Lf\n", b);
    printf("c: %0.15f\n", c);
}
```

## Conversión explícita
En esta conversión, quien programa indica al compilador que se quiere realizar una conversión de un tipo de dato a otro. Esto se hace mediante el uso de **casting**, con esta sintaxis:

```txt
(<nuevo_tipo_de_dato>) <expresion>;
```

La conversión explícita es indispensable en algunos casos, como la división:
```c
#include <stdio.h>

int main()
{
    int a = 5;
    int b = 2;

    // Aun cuando estamos asignando el resultado a un float, y la division claramente es un resultado decimal, C toma esta operación como una división entera: entero entre entero resulta en entero.
    float c = a / b;
    printf("sin cast: c = %f\n", c);

    // si queremos un resultado decimal, tenemos que convertir al menos unode los operandos a float
    float d = (float) a / b;
    printf("con cast en un operando: d = %f\n", d);

    //es preferible, por claridad, hacerlo con ambos operandos.
    float e = (float) a / (float) b;
    printf("con cast en ambos operandos: e = %f\n", e);
}
```

Podemos usarlo también, por ejemplo, para truncar los decimales de un número:
```c
#include <stdio.h>

int main()
{
    float a = 3.1416;

    float b = (int) a; // primero, degradamos a int y luego promocionamos a float.

    printf("a: %f\n", a);
    printf("b: %f\n", b);
}
```


### Efectos de las conversiones
#### Enteros y Reales
- Cuando convertimos de REAL a ENTERO, se trunca la parte decimal.
- Cuando convertimos de ENTERO a REAL, se agrega una parte decimal de 0.

🚨 Si asignamos un float negativo a un entero sin signo es impredecible lo que sucederá, no está establecido en el lenguaje.
