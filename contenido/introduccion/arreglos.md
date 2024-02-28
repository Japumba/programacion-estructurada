# Arreglos

Un arreglo es una estructura de datos compuesta, en la que un conjunto de elementos del mismo tipo son almacenados en memoria de manera contigua, a los que tenemos acceso a través de lo que llamamos índices.

El tamaño total en memoria de un arreglo es el resultado de multiplicar el tamaño de cada elemento por el número de elementos que contiene.

## Declarar un arreglo

Al declarar un arreglo, lo hacemos de una forma similar a otras variables, pero es necesario especificar entre corchetes (`[]`) el tamaño del arreglo.

```c
/*
    nombre del arreglo
          |
          |   tamaño del arreglo
          |     |
          |     |                    */
    int arreglo[5];
/*  |
    |
   tipo de dato
*/
```

En el ejemplo anterior, declaramos un arreglo de enteros llamado `arreglo` con un tamaño de 5 elementos de tipo int, con un tamaño total de 20 bytes (4 bytes por cada entero).

Los elementos de un arreglo al ser declarado `int arr[5];` no tienen un valor inicial explícito, por lo que el valor inicial de cada uno será indeterminado (realmente será el que esté en la memoria "que le tocó" en el momento de la declaración).

Podemos dar un valor inicial explícito a cada elemento del arreglo al momento de declararlo, de la siguiente forma:

```c
int arreglo[5] = {1, 2, 3, 4, 5};
```

Si solo especificamos algunos elementos en esa lista de inicialización, los elementos restantes se inicializarán en 0.

```c
int arreglo[5] = {0}; // crea un arreglo de 5 enteros, todos inicializados en 0

int arreglo[5] = {1}; // crea un arreglo de 5 enteros, el primero en 1 y los demás en 0
```

## Acceder a los elementos de un arreglo
Como dijimos, accedemos a los elementos de un arreglo usando lo que llamamos **índice**. El índice es un **número entero sin signo** que empieza en `0`, y nos dice cuántos elementos, empezando del primero, tenemos que avanzar antes de obtener el valor.

Por ejemplo, en el ejemplo anterior tendríamos que usar el índice `0` para acceder al primer elemento, el `1` para acceder el segundo elemento y así los demás.

```c
int arreglo[5] = {1, 2, 3, 4, 5};

printf("%d\n", arreglo[0]); // imprime el primer elemento, es decir 1
```

Importante: el rango de índices válidos para un arreglo de tamaño `n` es de `0` a `n - 1`. Si intentamos acceder a un índice fuera de este rango, el programa puede comportarse de manera inesperada o arrojar un error de compilación o ejecución.

```c
int arreglo[5] = {1, 2, 3, 4, 5};

printf("%d\n", arreglo[5]); // esto es un error, ya que el índice 5 está fuera del rango válido
```

### Modificar un arreglo
Aceder puede ser usado también para modificar el arreglo. Usaremos el operador de asignación para cambiar el valor de un elemento en un índice específico:

```c
int arreglo[5] = {1, 2, 3, 4, 5};

arreglo[0] = 10; // cambia el primer elemento por 10

// ahora el arreglo es [10, 2, 3, 4, 5]
```

#### Una nota sobre la asignación de arreglos
Con esta forma de utilizar los arreglos, en la que indicamos en el compilador el tamaño del arreglo, no se nos permite hacer cosas como `arreglo_2 = arreglo_1`, asumiendo que `arreglo_1` y `arreglo_2` son arreglos de enteros y que tienen el mismo tamaño.

Si lo intentamos, obtendremos un error:
```c
#include <stdio.h>

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = arr1;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}
```
```txt
main.c:7:9: error: array initializer must be an initializer list or wide string literal
    int arr2[5] = arr1;
        ^
1 error generated.
```

Tampoco podemos hacerlo más delante en el programa:

```c
#include <stdio.h>

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];

    arr2 = arr1; // esto es un error

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}
```

```txt
main.c:9:10: error: array type 'int[5]' is not assignable
    arr2 = arr1;
    ~~~~ ^
1 error generated.
```

### Acceder cada elemento de un arreglo
Naturalmente podemos ver una relación entre un arreglo, con su rango de índices, y un ciclo for (o while) que nos permita acceder a cada elemento del arreglo.

Para lograrlo, usaremos la variable de control del ciclo como índice de nuestro arreglo.

```c
int arreglo[5] = {1, 2, 3, 4, 5};

// para plasmar claramente el rango, usamos:
//  - valor inicial de i en 0, el primer índice
//  - condición de paro en i < 5, plasmando claramente el 5 que coincide con el tamaño del arreglo
//  - incremento de i en 1, para avanzar al siguiente índice de 1 en 1.
for (int i = 0; i < 5; i++) {
    printf("%d\n", arreglo[i]);
}
```

Podemos usar un ciclo for no solo para leer, sino también para modificar un arreglo.
```c
int arreglo[5] = {1, 2, 3, 4, 5};

for (int i = 0; i < 5; i++) {
    arreglo[i] = i;
}

// ahora el arreglo es [0, 1, 2, 3, 4]
```

### Arreglos con tamaño determinado en tiempo de ejecución
Hasta ahora, los arreglos los hemos declarado con un tamaño fijo en compilación. Sin embargo, es posible declarar arreglos con un tamaño determinado en tiempo de ejecución, usando una variable que contenga el tamaño.

```c
#include <stdio.h>

int main()
{
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int arreglo[n];

    for (int i = 0; i < n; i++)
    {
        arreglo[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }

    return 0;
}
```

## Ejercicios

### Básicos
1. Declara un arreglo de 5 elementos de tipo entero. Imprime todos los elementos y nota qué valores tiene cada elemento.
2. Declara un arreglo de 10 elementos de tipo short, inicializándolos todos en 0.
3. Crea un arreglo de 5 elementos e intenta acceder el elemento en el índice `100`.
4. Crea un arreglo de 5 elementos e intenta acceder el elemento en el índice `-1`.
5. Crea un arreglo de 100 elementos, sin inicializarlo. Luego, **usando un ciclo for**, asigna un `0` a cada elemento.
6. Crea un arreglo de 10 elementos, sin inicializarlo. Luego, **usando un ciclo for**, asigna a cada elemento **el doble de su índice**.
7. Usando un ciclo for y el operador módulo (`%`), imprime los elementos en posición par de un arreglo de 10 elementos.
8. Usando un ciclo for y sin usar el operador módulo (`%`), imprime los elementos en posición impar de un arreglo de 10 elementos.
9. Declara un arreglo de 5 posiciones y pide al usuario que ingrese cada una. Luego imprime cada elemento.


### Intermedios
1. Investiga cómo usar las funciones `rand` y `srand` de la librería `stdlib.h` para generar números aleatorios y crea un arreglo de 10 elementos con números aleatorios entre 0 y 100. Para los siguientes programas reutiliza este arreglo, nos referiremos a él como "arreglo aleatorio"
2. Usando el arreglo aleatorio, escribe un programa que encuentre el número más grande en el arreglo.
3. Usando el arreglo aleatorio, escribe un programa que encuentre el número más pequeño en el arreglo.
4. Usando el arreglo aleatorio, escribe un programa que encuentre el promedio de todos los números en el arreglo.
5. Usando el arreglo aleatorio, escribe un programa que cuente las veces que aparece un número N en el arreglo. Por ejemplo, `4` aparece 2 veces en el arreglo `[2, 3, 4, 2, 1, 7, 6, 5, 4, 1, 8, 3]`.
6. Usando el arreglo aleatorio, escribe un programa que determine si un elemento N está en el arreglo o no. Que imprima `0` si no está y `1` si sí está.
7. Usando el arreglo aleatorio, escribe un programa que cambie todos los valores impares en el arreglo por un 0. Por ejemplo el arreglo `[1, 3, 4, 7, 5, 2, 3, 9]` debe quedar como `[0, 0, 4, 0, 0, 2, 0, 0]`.
8. Usando `for` y `break`, escribe un programa que compare dos arreglos, elemento por elemento, y determine si son iguales o no. Que imprima `0` si no son iguales y `1` si sí lo son.

### Avanzados
1. Declara un arreglo de 5 elementos con los valores {1, 2, 3, 4, 5}. Luego, intercambia el primer y el último elementos del arreglo.
2. Declara un arreglo de 5 elementos con los valores {1, 2, 3, 4, 5}. Pide al usuario dos índices e intercambia esos elementos.
3. Usando el mismo arreglo, escribe un programa que invierta el orden de los elementos.
4. Ahora, que invierta el orden de un arreglo de 6 elementos. ¿Tuviste que cambiar algo?
