# Primer vistazo a condicionales
En C, el operador condicional es `if (condicion) { bloque }`. Si condicion es un valor que se considera verdadero, el bloque se ejecuta y si no, no.

Para la condición, en C no tenemos como tal el tipo de dato `boolean` para determinar **Verdaderas** y **Falsas**. Lo que se usa son valores numéricos, donde `0` es **Falso** y cualquier otro valor es **Verdadero**. Por ejemplo:

```c
#include <stdio.h>

int main() {
    
    if (0) {
        printf("esto no se ejecuta, 0 se considera falso\n");
    }

    if (1) {
        printf(" 1 se considera verdadero\n");
    }

    if (-1) {
        printf("-1 se considera verdadero");
    }

    return 0;
}

```

Podemos usar el operador else inmediatamente después de un if, para ejecutar un bloque de código en caso de que la condición sea falsa.
```c
#include <stdio.h>

int main() {
    
    if (0) {
        printf("el IF no se ejecuta, 0 se considera falso\n");
    } else {
        printf("el ELSE se ejecuta, 0 se considera falso\n");
    }

    return 0;
}

```

Podemos usar operadores relacionales para comparar y obtener valores verdaderos o falsos. Por ejemplo:

```c
#include <stdio.h>

int main() {
    
    if (1 == 1) {
        printf("1 es igual a 1\n");
    }

    if (1 != 2) {
        printf("1 es distinto de 2\n");
    }

    if (1 < 2) {
        printf("1 es menor que 2\n");
    }

    if (2 > 1) {
        printf("2 es mayor que 1\n");
    }

    if (1 <= 1) {
        printf("1 es menor o igual que 1\n");
    }

    if (1 >= 1) {
        printf("1 es mayor o igual que 1\n");
    }

    return 0;
}

```

Podemos ver que el resultado de los operadores relacionales es 0 o 1, para falso y verdadero respectivamente.

```c
#include <stdio.h>

int main() {
    // usamos parentesis en (1 == 1) para claridad.
    printf("1 == 1: %d\n", (1 == 1));


    // podemos guardar el resultado de (65 == 'A') en una variable, después de todo es un valor numérico.
    int condicion = (65 == 'A');
    printf("65 y 'A' son lo mismo: %d\n", condicion);

    condicion = (1 != 2);
    printf("1 != 2: %d\n", condicion);

    condicion = (1 > 2);
    printf("1 > 2: %d\n", condicion);

    return 0;
}

```
