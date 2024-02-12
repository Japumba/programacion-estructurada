# Entrada estándar: scanf
En C, tenemos un concepto llamado **entrada estándar**. Esto se refiere a la forma en que un programa recibe información del usuario.

Por default, esta entrada viene del teclado, y para leer esta información, usamos la función `scanf`.

Con `scanf`, podemos almacenar la entrada del usuario en variables, ya sea de forma simple o con un formato específico.

Al igual que `printf`, `scanf` es una función que viene de la librería `stdio.h`.

## Sintaxis
La sintaxis de `scanf` es similar a la de `printf`, pero con algunas diferencias.

```c
scanf("formato", argumentos);
```

Donde:
- `scanf` es la función que estamos llamando.
- `"formato"` es una cadena de texto que describe cómo debe ser la entrada que estamos esperando. Aquí puede haber caracteres y **etiquetas** (`%d`, `%f`, `%c`, etc.), dependiendo de los tipos de dato a leer.
- `argumentos` son las variables donde se almacenará la información leída, pasadas **por referencia**. Es una o más variables separadas por comas. Por cada etiqueta en `"formato"`, debe haber una variable correspondiente.
    - Pasar una variable por referencia significa antecederla por un `&` (ampersand), y lo que hace es, dicho de manera simple, permitir que la función que la recibe modifique el valor de la variable original. Si no, se pasa normalmente una "copia", es decir, se pasa por valor.


Especificadores de formato (etiquetas):

|Etiqueta| Significado|
|--------|------------|
|%c	| Caracter|
|%s| Cadena de caracteres|
|%hi| Entero corto|
|%hu| Entero corto sin signo|
|%Lf| Doble precisión largo|
|%d	| Entero|
|%i	| Entero|
|%o	| Entero octal|
|%x	| Entero hexadecimal|
|%p	| Puntero|
|%f	| Flotante|
|%u	| Entero sin signo|
|%e	| Notación científica|
|%E	| Notación científica|
|%%| Porcentaje|

Ejemplo:
```c
#include <stdio.h>

int main() {
    int numero;
    printf("Ingresa un número entero: ");
    scanf("%d", &numero);
    printf("El número que ingresaste es: %d\n", numero);
    return 0;
}
```

```c
scanf("%d", &numero);
```

- `"%d"` es la etiqueta que indica que estamos esperando un número entero.
- `&numero` es la variable donde se almacenará el número leído. Observa que se agrega el `&` para pasar la variable por referencia.

La función `scanf` regresa un valor, pero no es el valor leído, sino el número de elementos (etiquetas) leídos con éxito.

Veamos esto:
```c
#include <stdio.h>

int main() {
    int numero, variables_leidas;
    printf("Ingresa un número entero: ");
    variables_leidas = scanf("%d", &numero);
    printf("Elementos leídos: %d\n", variables_leidas);
    printf("El número que ingresaste es: %d\n", numero);
    return 0;
}
```

## Leer más de una variable
Podemos leer más de una variable en una sola llamada a `scanf`. Para esto, simplemente separamos las etiquetas con espacios (u otros caracteres) en la cadena de formato.

Estos simbolos se leerán separados por espacios, o incluso por un salto de línea.

```c
#include <stdio.h>

int main() {
    int numero1, numero2, elementos_leidos;
    printf("Ingresa dos números enteros, separados por espacios (o con enter): ");
    elementos_leidos = scanf("%d %d", &numero1, &numero2);
    printf("Elementos leídos: %d\n", elementos_leidos);
    printf("Los números que ingresaste son: %d y %d\n", numero1, numero2);
    return 0;
}
```


### Leer con formato especial:
Si agregamos caracteres que no son etiquteas al formato del scanf, estos deben coincidir con la entrada del usuario. De no ser  así, la función sólo leerá hasta donde coincida.
```c
#include <stdio.h>

int main() {
    unsigned short year = 9999;
    unsigned char month = 99, day = 99;
    int elementos_leidos;
    printf("Ingresa tu fecha de nacimiento año/mes/día: ");
    elementos_leidos = scanf("%hu/%hhu/%hhu", &year, &month, &day);

    printf("Elementos leidos: %d\n", elementos_leidos);
    printf("Anio: %hu\n Mes: %02hhu\n Dia: %02hhu\n", year, month, day);
}
```
