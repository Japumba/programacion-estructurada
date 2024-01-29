# Impresión de variables y Formatos de Impresion
Hasta ahora hemos usado estas etiquetas ('%d' es una etiqueta) para imprimir variables:
```c
printf("%c", inicial); // Para caracteres, como 'A'

printf("%d", edad); // Para enteros, como 31

printf("%f", altura); // Para flotantes, como 1.75
```

Para los formatos de impresión hay más que la configuración estándar de imprimir una variable. Se puede configurar dependiendo del tipo de dato. A continuación, algunas opciones para cada etiqueta:

## Etiqueta decimal (%d)
```c
#include <stdio.h>

int main() {
    int edad = 31;
    printf("podemos imprimir enteros con la etiqueta %%d:\n");
    printf("Tengo %d años\n", edad);

    printf("Podemos imprimir enteros en diferentes bases numéricas:\n");
    printf("En hexadecimal: %x\n", edad);
    printf("En octal: %o\n", edad);

    printf("podemos imprimir enteros con un ancho mínimo, agregando un número antes de la d en la etiqueta:\n");
    printf("Con ancho mínimo de 10: '%10d'\n", edad);
    printf("Con ancho mínimo de 10 y rellenado con ceros: '%010d'\n", edad);
    
    return 0;
}

```

## Etiqueta de punto flotante (%f)
Esta etiqueta nos sirve tanto para `float` como para `double`. Para imprimir un `double`. Podemos configurar algunas cosas para esta etiqueta:

```c
#include <stdio.h>

int main() {
    float altura = 1.75;

    printf("\nPodemos imprimir flotantes con la etiqueta %%f:\n");
    printf("  por default se imprimen 6 decimales\n");
    printf("  Mi altura es %f\n", altura);

    printf("\nPodemos especificar un número de decimales, agregando un punto y un número después de la f en la etiqueta:\n");
    printf("  Con 2 decimales: '%.2f'\n", altura);
    printf("  Con 5 decimales, se rellena con 0s: '%.5f'\n", altura);

    printf("\nSi se especifican menos decimales que los que tiene el valor, se redondea:\n");
    printf("  Con 1 decimal, se imprime: '%.1f'\n", altura);

    printf("\nPodemos especificar un ancho mínimo, agregando un número antes de la f en la etiqueta:\n");
    printf("  Con ancho mínimo de 10: '%10f'\n", altura);
    printf("  Con ancho mínimo de 10 y rellenado con ceros: '%010f'\n", altura);

    printf("\npodemos combinar ancho mínimo y número de decimales:\n");
    printf("  Con ancho mínimo de 10 y 2 decimales: '%10.2f'\n", altura);
    printf("  Con ancho mínimo de 10 y 2 decimales, rellenado con ceros: '%010.2f'\n", altura);
}
    
```

## Imprimir caracteres especiales
Para imprimir caracteres especiales, como el salto de línea, el tabulador, etc. Se usan secuencias de escape. Estas secuencias de escape se escriben con un backslash `\` seguido de una letra. Por ejemplo, `\n` es el salto de línea. A continuación, una lista de las secuencias de escape más comunes:

| Secuencia de escape | Descripción |
| --- | --- |
| `\n` | Salto de línea |
| `\t` | Tabulador |
| `\\` | Backslash |
| `\"` | Comillas dobles |

```c
#include <stdio.h>

int main() {
    printf("Hola\nMundo\n");
    printf("Hola\tMundo\n");
    printf("Hola \\Mundo\n");
    printf("Hola \"Mundo\"\n");
}

``` 