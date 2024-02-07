# Operadores
Un operador es un símbolo reservado en el sistema, que representa una opreación.

Este operador tiene uno o más operandos, que son los valores que se usan como entrada para la operación.

También, un operador tiene un resultado (que es el valor de retorno) y puede tener efectos secundarios.

## Operadores de asignación
Son operadores que asignan un valor a una variable.

### Asignación simple
El operador de asignación principal es `=`. Este operador toma el operando de la derecha y lo asigna a la variable de la izquierda.

🚨 **Importante**: este operador podría fácilmente confundirse con el de comparación de igualdad (`==`), ocasionando errores 🐞.

**Ejemplo**
```c
#include <stdio.h>

int main() {
    int x;
    x = 5; // asignamos el valor 5 a la variable x
    printf("El valor de x es: %d\n", x);

    /*
    Primero "resolvemos" el lado derecho y luego lo asignamos.

    Esta linea se lee:
    "guárdese en la variable x el resultado de sumar el valor actual de x y 1"
    */
    x = x + 1;

    printf("El valor de x es: %d\n", x);
    return 0;
}

```

#### ¿Qué regresa?
El valor devuelto por el operador de asignación es el valor que está siendo asignado:

```c
#include <stdio.h>

int main() {
    int x;
    x = 5; // asignamos el valor 5 a la variable x
    printf("El valor de x es: %d\n", x);

    /*
    Primero "resolvemos" el lado derecho y luego lo asignamos.

    Esta linea se lee:
    "guárdese en la variable x el resultado de sumar el valor actual de x y 1"
    */
    x = x + 1;

    int valor_devuelto_por_igual = (x = x + 1);
    printf("El valor de x es: %d\n", x);
    printf("El valor devuelto por el operador de asignación es: %d\n", valor_devuelto_por_igual);

    printf("El valor de x es: %d\n", x);
    return 0;
}
```

### Asignación compuesta
Estos operadores realizan una operación y luego asignan el resultado a la variable.

| Operador | Descripción | Ejemplo | Equivalente a |
|----------|-------------|---------|---------------|
| `+=` | Suma y asigna | `a += b` | `a = a + b` |
| `-=` | Resta y asigna | `a -= b` | `a = a - b` |
| `*=` | Multiplica y asigna | `a *= b` | `a = a * b` |
| `/=` | Divide y asigna | `a /= b` | `a = a / b` |
| `%=` | Módulo y asigna | `a %= b` | `a = a % b` |

**Ejemplo**
```c
#include <stdio.h>

int main() {
    int x = 5;
    printf("El valor inicial de x es: %d\n", x);

    x += 3; // x = x + 3
    printf("El valor de x +=3 es: %d\n", x);

    x -= 2; // x = x - 2
    printf("Luego, el valor de x-=2 es: %d\n", x);

    x *= 4; // x = x * 4
    printf("Luego, el valor de x*=4 es: %d\n", x);

    x /= 3; // x = x / 3
    printf("Luego, el valor de x/=3 es: %d\n", x);

    x %= 3; // x = x % 3
    printf("Luego, el valor de x%%=3 es: %d\n", x);

    return 0;
}
```

## Operadores aritméticos
Estos operadores realizan operaciones aritméticas, como suma, resta y una que otra más interesantes.

| Operador | Descripción | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `+` | Suma | `a + b` | Suma de `a` y `b` |
| `-` | Resta | `a - b` | Resta de `a` y `b` |
| `*` | Multiplicación | `a * b` | Multiplicación de `a` y `b` |
| `/` | División | `a / b` | División de `a` entre `b` |
| `%` | Módulo | `a % b` | Residuo de la división de `a` entre `b` |

**Ejemplo**
```c
#include <stdio.h>

int main() {
    int a = 5, b = 2;
    printf("La suma de %d y %d es: %d\n", a, b, a + b);
    printf("La resta de %d y %d es: %d\n", a, b, a - b);
    printf("La multiplicación de %d y %d es: %d\n", a, b, a * b);
    printf("La división de %d entre %d es: %d\n", a, b, a / b);
    printf("%d modulo %d (residuo de %d/%d) es: %d\n", a, b, a, b, a % b);
    return 0;
}
```