# Strings
Los strings en C, como en otros lenguajes, son una secuencia de caracteres. En específico, en C son un arreglo de elementos de tipo `char`. Además de contener los caracteres, los strings en C tienen una característica de vital importancia: su terminación la dicta la presencia de un caracter con el valor 0, al que llamamos caracter NULO, o NULL character.

El arreglo que contenga un string debe ser lo suficientemente largo para contener todos los caracteres del texto, más uno por el caracter nulo:
```c
// Podemos declarar un arreglo de 7 elementos y asignarle como valor inicial el string "Carlos".
// Nótese que tenemos comillas dobles (") para indicar que es un string, en lugar de comillas simples (').
char nombre[7] = "Carlos";
```

En memoria, así se ve el arreglo:
```txt
// como caracteres:
['C', 'a', 'r', 'l', 'o', 's', '\0']

// Recuerda que los caracteres son numeros enteros, entonces se ve asi tambien:
[ 68,  97, 114, 108, 111, 115,    0]
```

El momento de inicializar un string es el único momento en el que podemos asignar un string directamente con el símbolo igual. Si queremos modificar un string después, debemos hacerlo "a mano", o usando funciones de ayuda para strings.
```c
char nombre[7] = "Carlos";
nombre = "Oscar"; // Esto no es válido, ya que no podemos asignar un string directamente a un arreglo fuera de su inicialización.
```

También podemos dejarle al compilador decidir el tamaño del arreglo en el caso de inicializar directamente con un string:
```c
char nombre[] = "Carlos"; // El compilador asignará el tamaño del arreglo automáticamente.
```

Pregunta rápida: ¿Qué tamaño tendrá el arreglo, y por qué?

## Imprimir un string en consola
Para imprimir un string podemos usar la funcion `printf`, con la etiqueta `%s`:
```c
#include <stdio.h>

int main() {
    char nombre[] = "Carlos";
    printf("Hola, %s\n", nombre);
    return 0;
}
```

## Leer un string del usuario
Podemos leer un string del usuario con la función `scanf` y usando la etiqueta `%s` que leerá texto hasta el primer enter o espacio. Nótese la declaración del arreglo con suficientes elementos para guardar algún nombre de hasta 9 caracteres, más el caracter nulo:
```c
#include <stdio.h>

int main() {
    char nombre[10];
    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    printf("Hola, %s\n", nombre);
    return 0;
}
```
Es muy importante considerar el tamaño del arreglo al leer cadenas de texto del usuario, especialmente si usamos scanf: si el usuario ingresa un string más largo que el tamaño del arreglo, podemos tener problemas de seguridad, ya que el string podría sobreescribir otras variables en memoria.

Una opción más segura es usar la función `fgets`, que nos permite leer texto hasta una cantidad máxima de caracteres del usuario. Si no ha terminado de leer el texto y llega al máximo de caracteres, se detiene y deja el resto del texto en el buffer para la siguiente llamada a `fgets`. La función `fgets` también incluye el caracter nulo al final del string, por lo que debemos considerar un espacio adicional en el tamaño del arreglo:
```c
#include <stdio.h>

int main() {
    char nombre[10];
    printf("Ingresa tu nombre: ");
    fgets(nombre, 10, stdin); // se le pasa como parametro stdin, que es el standard input. Podría leer de otros lugares, como de un archivo.
    printf("Hola, %s\n", nombre);
    return 0;
}
```

## Funciones de ayuda para strings
Las operaciones sobre strings no se hacen como en otros lenguajes. En C se tiene un conjunto de funciones que nos ayudan a trabajar con strings. Estas funciones están disponibles en la librería `string.h`.

Uno de los más notables es ¿cuánto mide la cadena de texto? Esta pregunta podría malinterpretarse y confundisre con "¿cuánto mide el arreglo?". Recordemos que un string son todos los caracteres _hasta el caracter nulo_, por lo que el tamaño del arreglo no es el tamaño del string.

Para saber cuánto mide el string necesitamos contar la cantidad de caracteres que no son nulos. Existe una función llamada `strlen` que nos ayuda con esto:
```c
#include <stdio.h>
#include <string.h> // Necesitamos incluir la librería string.h para usar strlen.

int main() {
    // aun cuando el arreglo es de 100 caracteres, el string tiene solamente 6 caracteres antes del NULO.
    char nombre[100] = "Carlos";
    printf("El nombre tiene %lu caracteres\n", strlen(nombre));
    return 0;
}
```

¿Cuánto mide el string vacío `""`?

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nombre[] = "";
    printf("El nombre tiene %lu caracteres\n", strlen(nombre));
    return 0;
}
```

Otra cosa que haremos mucho con strings es compararlas, saber si una es igual a otra. ¿Cómo comparo dos strings? Probablemente hayas hecho algo como esto en otros lenguajes: `if(string1 == string2) { ... }`. Esto no es posible en C!

```c
#include <stdio.h>

int main() {
    char nombre1[] = "Carlos";
    char nombre2[] = "Carlos";

    if(nombre1 == nombre2) {
        printf("Los nombres son iguales\n");
    } else {
        printf("Los nombres son diferentes\n");
    }
    return 0;
}
```

Puede que al compilar este codigo tengas un mensaje como este:
```shell
warning: array comparison always evaluates to false [-Wtautological-compare]
    if(nombre1 == nombre2) {
               ^
1 warning generated.
```

Y si ejecutas el programa, tendrás este resultado:
```shell
Los nombres son diferentes
```

Entonces, ¿cómo se comparan dos strings? Necesitamos una función que nos ayude con esto, es un proceso más laborioso y explícito.

Para que dos strings sean considerados iguales, todos sus caracteres deben ser iguales. Existe una función que nos ayuda con esto, llamada `strcmp`.

Esta función nos puede regresar 3 valores:

- regresa 0 si todos los caracteres de ambos strings son iguales.
- regresa un número negativo si el primer string es menor que el segundo, alfabéticamente.
- regresa un número positivo si el primer string es mayor que el segundo, alfabéticamente.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nombre1[] = "Carlos";
    char nombre2[] = "Carlos";

    if(strcmp(nombre1, nombre2) == 0) {
        printf("Los nombres son iguales\n");
    } else {
        printf("Los nombres son diferentes\n");
    }
    return 0;
}
```

Modifica el código anterior para obtener los otros resultados.

Existen más funciones para trabajar con strings, como `strcpy`, `strcat`, `strchr`, `strstr`, `strtok`, entre otras. Puedes consultar la documentación de la librería `string.h` para más información.
