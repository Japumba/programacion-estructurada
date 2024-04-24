# Múltiples Arcihvos Fuente
Sabemos que podemos escribir código de forma modular usando funciones; esto nos permite diseñar e implementar de forma aislada y enfocada.

Sin embargo, a medida que nuestros programas crecen, es posible que necesitemos dividir nuestro código en varios archivos. Esto nos permite organizar nuestro código de una manera más limpia y fácil de mantener.

Usaremos este ejemplo simple:

**main.c**
```c
#include <stdio.h>

// 1) Prototipo de las funciones, solamente las firmas

/**
 * Recibe dos enteros y devuelve su suma.
 */
int sumar(int a, int b);

/**
 * Recibe dos enteros y devuelve la resta del primero menos el segundo.
 */
int restar(int a, int b);

// 2) Funcion main
int main() {
    int a = 5;
    int b = 3;

    printf("La suma de  %d y %d es %d\n", a, b, sumar(a, b));
    printf("La resta de %d y %d es %d\n", a, b, restar(a, b));

    return 0;
}

// 3) Implementación de las funciones

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}
```

Para compilar este codigo, podemos usar el comando `gcc main.c -o main`.
- `gcc` ejecuta el compilador de C.
- `main.c` es el archivo que queremos compilar.
- `-o main` le dice al compilador que queremos que el archivo ejecutable se llame `main`.

Actualmente tenemos 3 partes que están en el mismo archivo:
1. **Prototipo de la función**: Es la firma de la función, que le dice al compilador que la función existe y que será definida en algún lugar.
2. **Función main**: Es la función principal que se ejecuta cuando el programa se inicia.
3. **Implementación de la función**: Es la definición de la función, que contiene el código que se ejecuta cuando la función es llamada.

Para mejorar la organizacion, podemos separar nuestro código más aun, en 3 archivos distintos:
- **main.c**: Contiene la función `main`, e incluye las librerías externas que usará.
- **operaciones.h**: Es un archivo de cabecera y contiene los prototipos de las funciones `sumar` y `restar`, se incluirá en el archivo `main.c` para que el compilador sepa que las funciones existen y serán definidas en otro lugar.
- **operaciones.c**: Es un archvo de implementación y contiene las definiciones de las funciones `sumar` y `restar`, se usará para compilar.

### Archivo de cabeceara (Header File)
Estos archivos nos permiten compartir un "contrato" entre los archivos de implementación y los archivos que los usan. En este archivo se definen los prototipos de las funciones, tipos de datos y variables globales que se usarán en otros archivos.

En nuestro ejemplo, el archivo `operaciones.h` se vería así:
```c
// operaciones.h

// Primero, usaremos la instruccion del preprocesador #ifndef (if not defined) para revisar si un símbolo específico no ha sido definido.
// Esto nos permite evitar que el archivo de cabecera se incluya más de una vez en un archivo fuente, lo que causaría un error.
// encuentra el #endif al final del archivo, y observa cómo sólo se incluirá una vez.
#ifndef OPERACIONES_H

// Aqui se define el símbolo. No tiene un valor específico, sólo nos interesa saber si existe.
#define OPERACIONES_H

// 1) Prototipo de las funciones, solamente las firmas

/**
 * Recibe dos enteros y devuelve su suma.
 */
int sumar(int a, int b);

/**
 * Recibe dos enteros y devuelve la resta del primero menos el segundo.
 */
int restar(int a, int b);

#endif
```

### Archivo de implementación
Estos archivos contienen la implementación de las funciones que se declaran en los archivos de cabecera. Normalmente, por cada archivo de cabecera, hay un archivo de implementación correspondiente.

En nuestro ejemplo, el archivo `operaciones.c` se vería así:
```c
// operaciones.c

// 3) Implementación de las funciones
int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}
```

### Separar el programa en archivos

1. Modifica el archivo `main.c`, borrando las firmas y las implementaciones de las funciones `sumar` y `restar`. Tendrás un error de compilación `undeclared function` porque no están declaradas funciones.
    ```shell
    % gcc main.c -o main
    main.c:8:49: error: call to undeclared function 'sumar'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
        printf("La suma de  %d y %d es %d\n", a, b, sumar(a, b));
                                                    ^
    main.c:9:49: error: call to undeclared function 'restar'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
        printf("La resta de %d y %d es %d\n", a, b, restar(a, b));
                                                    ^
    2 errors generated.
    ```
2. Crea el el archivo `operaciones.h` en el mismo directorio que `main.c` y copia el contenido del archivo de cabecera. Seguirás teniendo el mismo error de compilación porque no hemos incluido la cabecera en el archivo `main.c`.
3. Agrega la linea `#include "operaciones.h"` al principio del archivo `main.c`. Nota que usamos comillas dobles en lugar de los corchetes angulares que usamos para incluir librerías externas.
    1. Si compilas ahora, tendrás un error distinto. En lugar de `undeclared function`, tenemos `undefined symbols`, porque aunque tenemos las firmas de las funciones, no tenemos las implementaciones.
        ```shell
        % gcc main.c -o main
        ld: Undefined symbols:
        _restar, referenced from:
            _main in main-f83a40.o
        _sumar, referenced from:
            _main in main-f83a40.o
        clang: error: linker command failed with exit code 1 (use -v to see invocation)
        ```
4. Ahora, crea un archivo llamado `operaciones.c` en el mismo directorio que `main.c` y copia el contenido de las implementaciones de las funciones `sumar` y `restar`.
    ```c
    // operaciones.c

    // 3) Implementación de las funciones
    int sumar(int a, int b) {
        return a + b;
    }

    int restar(int a, int b) {
        return a - b;
    }
    ```
5. Al volver a compilar, necesitamos agregar el nuevo archivo, `operaciones.c`, al comando de compilación.
    ```shell
    % gcc main.c operaciones.c -o main
    ```
    - `gcc` ejecuta el compilador de C.
    - `main.c` es uno de los archivos que queremos compilar.
    - `operaciones.c` es el otro archivo que queremos compilar, el que contiene las implementaciones de las funciones.
    - `-o main` le dice al compilador que queremos que el archivo ejecutable se llame `main`.

Ahora puedes compilar y ejecutar tu programa sin problemas.

### Resultado final
Al final, quedarás con estos 3 archivos en la misma carpeta:
```txt
.
├── main.c
├── operaciones.c
└── operaciones.h
```

**main.c**
```c
#include <stdio.h>
#include "operaciones.h"

// 2) Funcion main
int main() {
    int a = 5;
    int b = 3;

    printf("La suma de  %d y %d es %d\n", a, b, sumar(a, b));
    printf("La resta de %d y %d es %d\n", a, b, restar(a, b));

    return 0;
}
```

**operaciones.c**
```c
// operaciones.c

// 3) Implementación de las funciones
int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}
```

**operaciones.h**
```c
// operaciones.h

// Primero, usaremos la instruccion del preprocesador #ifndef (if not defined) para revisar si un símbolo específico no ha sido definido.
// Esto nos permite evitar que el archivo de cabecera se incluya más de una vez en un archivo fuente, lo que causaría un error.
// encuentra el #endif al final del archivo, y observa cómo sólo se incluirá una vez.
#ifndef OPERACIONES_H

// Aqui se define el símbolo. No tiene un valor específico, sólo nos interesa saber si existe.
#define OPERACIONES_H

// 1) Prototipo de las funciones, solamente las firmas

/**
 * Recibe dos enteros y devuelve su suma.
 */
int sumar(int a, int b);

/**
 * Recibe dos enteros y devuelve la resta del primero menos el segundo.
 */
int restar(int a, int b);

#endif
```