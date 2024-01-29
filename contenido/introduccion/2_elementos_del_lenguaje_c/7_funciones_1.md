# Primer vistazo a las funciones
Las funciones son un tema fundamental y también extenso. En esta sección, conoceremos su sintaxis básica y algunos primeros usos.

## ¿Qué son las funciones?
Una función es, dicho de forma simple, un bloque de código que podemos reutilizar a lo largo de nuestro programa. Esto nos permite escribir código más limpio y fácil de mantener.

La función con la que siempre interactuamos en C es la función `main`, que es el punto de entrada de nuestro programa. Sin embargo, podemos crear nuestras propias funciones.

```c
#include <stdio.h>

// main es nuestra función principal, y es la que se ejecuta cuando corremos el programa
int main() {
    printf("Hola desde main\n");
    return 0;
}

```

Para declarar, implementar y mandar llamar nuestras propias funciones, escribimos algo similar a lo que vemos en main:

```c
#include <stdio.h>

// declaración de una función que saluda cordialmente
void saludar_cordialmente() {
    // las llaves definen el cuerpo de la función {}
    printf("Saludos cordiales\n");

    // como nuestro tipo de dato de retorno es void, no necesitamos usar la palabra return, aunque podemos hacerlo.
    return;

    // ¿qué pasa si colocamos instrucciones luego de return?
    printf("...Bro\n");
}

int main() {
    printf("Hola desde main\n");
    saludar_cordialmente(); // llamamos a la función que declaramos
    return 0;
}

```

### ¿Importa el orden de cómo lo declaramos?
Recordemos que el compilador va de arriba a abajo, y que no puede usar algo que no ha visto. Por lo tanto, si queremos usar una función, debemos declararla antes de usarla. Intenta compilar el siguiente código y observa el error:

```c
#include <stdio.h>

int main() {
    saludar_cordialmente(); // llamamos a la función que aun no declaramos
    printf("Hola desde main\n");
    return 0;
}

void saludar_cordialmente() {
    printf("Saludos cordiales\n");
    return;
}

```

```bash
main.c:5:5: error: call to undeclared function 'saludar_cordialmente'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
    saludar_cordialmente(); // llamamos a la función que declaramos
```

¿Cómo podemos colocar la función abajo, para que sea claro dónde empieza el programa? Podemos separar su declaración de su implementación.

- La **declaración** es lo primero que el compilador necesita para saber que existe la función, la llamamos también _firma_. En ella, especificamos el nombre de la función, los parámetros que recibe y el tipo de dato que devuelve.
    - **Nombre**: es el identificador de la función, y nos permite llamarla desde otras partes del programa.
    - **Parámetros**: son los valores que recibe la función para realizar su trabajo. Pueden ser de cualquier tipo de dato.
    - **Tipo de dato de retorno**: es el tipo de dato que devuelve la función. Puede ser cualquier tipo de dato.
- La **implementación** es el cuerpo de la función, donde escribimos las instrucciones que queremos que se ejecuten cuando llamamos a la función.


Así podemos tener muchas funciones y organizarlas mejor:
```c
#include <stdio.h>

// declaración de las funciones
void saludar_cordialmente();
void saludar_bro();

int main() {
    printf("Hola desde main\n");
    saludar_cordialmente(); // llamamos a la función que declaramos
    saludar_bro();
    return 0;
}

// implementación de la función. Repetimos la firma, para que el compilador sepa que esta implementación corresponde a la función que declaramos.
void saludar_cordialmente() {
    printf("Saludos cordiales\n");
    return;
}

void saludar_bro() {
    printf("Saludos bro\n");
    return;
}

```

Más delante veremos que incluso podemos separar las funciones en **archivos distintos**!

### Valor de retorno
Podemos especificar un valor de retorno y usarlo en donde sea que mandemos llamar la función. Un ejemplo muy burdo pero ilustrativo es el siguiente:

```c
#include <stdio.h>

int devuelve_cinco();

int main() {
    int cinco = devuelve_cinco();
    printf("cinco vale %d\n", cinco);
    return 0;
}

int devuelve_cinco() {
    return 5;
}

```

Podemos ver cómo estamos mandando llamar la función `devuelve_cinco` y asignando su valor de retorno a la variable `cinco`. Luego, imprimimos el valor de `cinco` en pantalla.

### Argumentos de una función
Podemos pasarle argumentos a una función, para que realice su trabajo con ellos. Para ello, debemos especificar el tipo de dato de cada argumento en la declaración de la función, y luego usarlos en la implementación.

Combinemos el valor de retorno y los parámetros para una función de sumar:

```c
#include <stdio.h>

int sumar(int a, int b);

int main() {
    int resultado = sumar(5, 7);
    printf("5 + 7 = %d\n", resultado);
    
    // podemos directamente usar el valor de retorno de la función en otra función
    printf("10 + 11 = %d\n", sumar(10, 11));
    return 0;
}

int sumar(int a, int b) {
    return a + b;
}

```