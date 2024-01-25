# Variables y Declaración

## Una variable
Podríamos decir que una variable tiene tres compnentes:
- Un **Identificador**, que **no** cambia.
- Un **Tipo de dato**, que (en C) **no** cambia.
- Un **Valor**, que **sí** cambia (excepto en algunos casos 😀).

Finalmente, una variable es un espacio en la memoria que contiene información.

## Declarar una variable
Declarar una variable significa asignarle un espacio en la memoria y asociar dicho espacio con un identificador y un tipo de dato. En ese espacio de memoria se guardarán los datos.

Tres formas distintas de declarar la misma variable:
```c
#include <stdio.h>

int main() {
    /*
    declaramos una variable de tipo INT que se llama edad, y le asignamos un valor inicial de 31.
    */
    int edad = 31;
    printf("Mi edad es %d\n", edad);

    // declaramos una varialbe de tipo INT que se llama otra_edad, pero no le asignamos un valor inicial.
    // ¿Qué valor inicial tiene otra_edad?
    int otra_edad;
    printf("Mi otra_edad, sin inicializar, es %d\n", otra_edad);

    /*
    Podemos declarar dos o más variables del mismo tipo en una misma línea
        - ¿Qué valor inicial tiene ultima_edad?
        - ¿Qué valor inicial tiene nivel?
        - ¿Qué valor inicial tiene nivel_maximo?
    */
    int ultima_edad, nivel = 32, nivel_maximo = 100;
    printf("Mi ultima_edad es %d\n", ultima_edad);
    printf("Mi nivel es %d\n", nivel);
    printf("Mi nivel máximo es %d\n", nivel_maximo);
}
```

En C, es importante que al declarar una variable le asignemos un valor inicial. Si no lo hacemos, la variable tendrá un valor inicial aleatorio, que puede ser cualquier cosa. Ejecuta el programa anterior varias veces y observa el valor de las variables que no tienen valor inicial asignado.

## Usar una variable
Para usar una variable, simplemente escribimos su identificador en un lugar adecuado. Por ejemplo:

```c
#include <stdio.h>

int main() {
    int edad = 25;
    printf("Mi edad es %d\n", edad); // Accedemos al valor guardado en la memoria asociada a la variable edad.

    int envejecer = 2;

    /*
    Modificamos el valor guardado en la memoria asociada a la variable edad,
    asignándole el valor que tenía más el valor de la variable envejecer.
    */
    edad = edad + envejecer;

    printf("Luego de envejecer %d años, mi edad es %d\n", envejecer, edad); // Accedemos a ambos valores.

    return 0;
}
```
