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

Podemos usar el operador `else` inmediatamente después de un `if`, para ejecutar un bloque de código en caso de que la condición sea falsa.
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

Además de poner un bloque directamente luego de un else, se puede colocar también un if, para tener una estructura `if else-if ... else`. Por ejemplo:
```c
#include <stdio.h>

int main() {
    
    // cambia el valor de numero para ver que mensaje se imprime.
    int numero = 0;

    if (numero > 0) {
        printf("el numero es positivo\n");
    } else if (numero < 0) {
        printf("el numero es negativo\n");
    } else {
        printf("el numero es cero\n");
    }

    return 0;
}

```
## Operadores relacionales
Podemos usar operadores relacionales para comparar y obtener valores verdaderos o falsos. Estos operadores regresan 1 si su comparación es verdadera, y 0 si es falsa.

Estos son los operadores relacionales en C:
| Nombre del operador | Operador | Ejemplo de uso | Regresa 1 si: |
|----------|----------|----------------|-------------|
| Igualdad | `==` | `a == b` | a es igual a b |
| Desigualdad | `!=` | `a != b` | a es distinto de b |
| Menor que | `<` | `a < b` | a es menor que b |
| Mayor que | `>` | `a > b` | a es mayor que b |
| Menor o igual que | `<=` | `a <= b` | a es menor o igual que b |
| Mayor o igual que | `>=` | `a >= b` | a es mayor o igual que b |


Por ejemplo:

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

## Operadores lógicos
Muchas veces necesitamos combinar condiciones, para esto usamos operadores lógicos.

Para estos, los operandos se interpretan como **valores de verdad** (0 es falso y cualquier otro valor es verdadero).

Los operadores lógicos en C son:

| Nombre del operador | Operador | Ejemplo de uso | Regresa 1 si: |
|----------|----------|----------------|-------------|
| AND | `&&` | `a && b` | a y b son verdaderos |
| OR | `\|\|` | `a \|\| b` | a o b son verdaderos |
| NOT | `!` | `!a` | a es falso. Efectivamente niega el valor de a. |

Estas son las "Tablas de Verdad" para los operadores lógicos:

**AND:**
| a | b | a && b |
|---|---|--------|
| 0 | 0 | 0      |
| 0 | 1 | 0      |
| 1 | 0 | 0      |
| 1 | 1 | 1      |

**OR:**
| a | b | a \|\| b |
|---|---|---------|
| 0 | 0 | 0       |
| 0 | 1 | 1       |
| 1 | 0 | 1       |
| 1 | 1 | 1       |

**NOT:**
| a | !a |
|---|----|
| 0 | 1  |
| 1 | 0  |
