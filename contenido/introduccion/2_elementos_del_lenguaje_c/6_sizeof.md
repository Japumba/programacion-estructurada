# Size of
Hasta ahora hemos usado mucho el operador o funcion `sizeof`, que nos permite obtener el tamaño en bytes de un tipo de dato o de una variable. Veremos algunos detalles.

```c
#include <stdio.h>

int main() {
    int edad = 31;
    printf("El tamaño de edad es: %d bytes\n", sizeof(edad));
    return 0;
}
```

Seguramente te has topado con este warning:
```bash
main.c:7:49: warning: format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]
    printf("El tamaño de edad es: %d bytes\n", sizeof(edad));
                                  ~~           ^~~~~~~~~~~~
                                  %lu
```

Podemos ver que el warning nos dice que el formato `%d` es para un `int`, pero el argumento que le pasamos es un `unsigned long`. Esto es porque el tipo de dato que devuelve `sizeof` es `unsigned long`, y no `int`. Para solucionar esto, podemos usar el formato `%lu` para `unsigned long` (podríamos decir que es por _"long unsigned"_).

```c
#include <stdio.h>

int main() {
    printf("El tamaño de edad es: %lu bytes\n", sizeof(edad)); // este ya no nos da warning
    return 0;
}
```

## ¿Cómo funciona?
Realmente no es algo que sucede en el tiempo de ejecución, sino que es un cálculo que hace el compilador con la información que tiene disponible. Por ejemplo, si tenemos una variable `int` en un sistema de 32 bits, el compilador sabe que esa variable ocupará 4 bytes, y por lo tanto, cuando vea el operador `sizeof`, sabrá que debe devolver `4`.

Esto nos lleva a comportamientos interesantes que abarcaremos luego, cuando por ejemplo tenemos funciones y arreglos y queremos determinar el tamaño de un argumento.
