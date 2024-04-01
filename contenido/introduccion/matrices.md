# Arreglos de más de una dimensión
Anteriormente vimos que un arreglo es un conjunto de elementos del mismo tipo, almacenados en posiciones contiguas de memoria, a las que tenemos acceso a través del primer elemento y podemos acceder a cada uno de ellos mediante un índice (`array[index]`).

En los casos anteriores, hemos trabajado con arreglos de una dimensión, es decir, un conjunto de elementos en una sola fila. Pero, ¿qué pasa si queremos almacenar un conjunto de elementos en una matriz, o en un espacio de 3 o más dimensiones?

## Declarar arreglos de más de una dimensión
Para usar arreglos de más de 1 dimensión, C nos permite utilizar una sintaxis similar a la de los arreglos de una dimensión, pero con dos o más índices:

En el caso de las matrices, o arreglos de 2 dimensiones, normalmente les llamamos filas y columnas.

```c
// Declaración de una matriz de 2 filas y 3 columnas
//     filas
//         |  columnas
//         |  |
//         v  v
int matriz[2][3];

// Asignación de un valor a un elemento de la matriz
//  fila 0, columna 1
matriz[0][1] = 5;

// Acceso a un elemento de la matriz, por ejemplo para imprimirlo
//  fila 0, columna 1
printf("%d\n", matriz[0][1]);
```

Podemos dar valores iniciales a los elementos de una matriz al momento de declararla, de forma similar a los arreglos de una dimension:
```c
#include <stdio.h>

int main()
{
    // Este es un arreglo de dos dimensiones.
    // Tiene 2 filas y 3 columnas.
    // 
    // Se da un valor inicial a cada elemento de cada fila.
    // 
    // Nótese la similitud en la sintaxis con los arreglos de una dimensión:
    // cada fila de la matriz es un arreglo de una dimensión con 3 elementos.
    int matriz[2][3] = {
        {1, 2, 3}, // esta es la fila 0
        {4, 5, 6}  // esta es la fila 1
    };

    // Para recorrer todo el arreglo, necesitamos dos ciclos anidados.
    //  - El ciclo exterior es para recorrer las filas.
    //  - El ciclo interior es para recorrer las columnas.
    // 
    // Una forma de leer esto es: "por cada fila, recorre todas las columnas".
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("matriz[%d][%d]: %d\n", row, col, matriz[row][col]);
        }
        printf("\n");
    }

    return 0;
}
```

## Pasar arreglos de más de una dimensión a funciones como argumentos
Como ya conocen, para usar una función con arreglos de distintos tamaños, necesitamos indicar en un parámetro el tamaño del arreglo (`void print_array(int array[], int size)`).

En el caso de arreglos de más de una dimensión, también podemos indicar el tamaño de las dimensiones en variables, pero con algunas restricciones.

Observa en el ejemplo las diferentes formas de declarar una función que recibe un arreglo como parametro:
```c
#include <stdio.h>

/**
 * Podemos dejar los tamaños fijos, pero esto nos limita a siempre recibir
 * arreglos del tamaño especificado.
 * 
 * podemos agregar cuantas dimensiones queramos.
 */
void imprimir_matriz_de_2_por_3(int matriz[2][3])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("matriz[%d][%d]: %d\n", row, col, matriz[row][col]);
        }
        printf("\n");
    }
}

/**
 * Para matrices (de 2 dimensiones)
 * Podemos dejar el tamaño "más grande" como variable, pero todas las dimensiones más pequeñas deben ser fijas.
 *
 * En este caso, el argumento `n` es el tamaño de la primera dimensión, la cantidad de filas.
 * La cantidad de columnas es fija en 3.
 * 
 * Esta es una forma estándar y compatible con versiones anteriores de C.
 */
void imprimir_matriz_de_N_filas_de_3_columnas(int matriz[][3], int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("matriz[%d][%d]: %d\n", row, col, matriz[row][col]);
        }
        printf("\n");
    }
}

/**
 * Para arreglos de más dimensiones (3 o más)
 * Podemos dejar el tamaño "más grande" como variable, pero todos los tamaños "más pequeños" deben ser fijos.
 *
 * El argumento `matrices` es el tamaño de la dimensión más grande.
 *
 * el arreglo que le vamos a pasar es "un arreglo de matrices"
 */
void imprimir_arreglo_de_matrices_3d_de_2_por_3(int arreglo3D[][2][3], int matrices)
{
    for (int matriz = 0; matriz < matrices; matriz++)
    {
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                printf("arreglo3D[%d][%d][%d]: %d\n", matriz, row, col, arreglo3D[matriz][row][col]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/**
 * Para poder usar todas las dimensiones como variables, tenemos dos opciones:
 *
 * 1. (disponible para todas las versiones del compilador): Usar punteros, lo verán en el siguiente curso.
 * 2. (disponible a partir de C99): Usar el nombre del parámetro de tamaño de la dimension para indicar el tamaño en la firma.
 *
 * Aquí estamos usando la opcion 2:
 * En lugar de `int matriz[][3]`, usamos `int matriz[][m]`. `m` es el tamaño de la segunda dimensión.
 * Para esto, el parametro m debe ser declarado antes que el parametro para la matriz.
 *
 * De otra forma, el compilador nos dará un error. si queremos, por ejemplo, usar int matriz[][].
 */
void imprimir_matriz_de_N_por_M(int n, int m, int matriz[][m])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            printf("matriz[%d][%d]: %d\n", row, col, matriz[row][col]);
        }
        printf("\n");
    }
}

/**
 * En arreglos de más de 2 dimensiones también podemos usar todo como parámetros,
 * uno por cada dimensión.
 *
 * Nuevamente tenemos dos opciones, de las cuales usaremos la de "usar los nombres de los parametros dentro de los corchetes"
 *
 * En este caso, tenemos 3 dimensiones, por lo que necesitamos 3 parámetros.
 *  - p es el tamaño de la primera dimensión, la más grande. Es la cantidad de matrices.
 *  - n es el tamaño de la segunda dimensión, la cantidad de filas.
 *  - m es el tamaño de la tercera dimensión, la cantidad de columnas.
 */
void imprimir_arreglo_3d_de_P_matrices_de_N_por_M(int p, int n, int m, int arreglo3D[][n][m])
{
    for (int matriz = 0; matriz < p; matriz++)
    {
        // podemos reutilizar la función anterior para imprimir cada matriz
        printf("Matriz %d:\n", matriz);
        imprimir_matriz_de_N_por_M(n, m, arreglo3D[matriz]);
        printf("\n");
    }
}

int main()
{
    int matriz2por3[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    printf("Matriz de 2x3:\n");
    imprimir_matriz_de_2_por_3(matriz2por3);

    printf("\nMatriz de Nx3:\n");
    int matrizNpor3[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}};
    imprimir_matriz_de_N_filas_de_3_columnas(matrizNpor3, 5);

    printf("\nMatriz de NxM:\n");
    int matrizNporM[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};
    imprimir_matriz_de_N_por_M(5, 4, matrizNporM);

    printf("\nArreglo de matrices 3D de 2x3:\n");
    int arreglo3D[4][2][3] = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}},
        {{13, 14, 15},
         {16, 17, 18}},
        {{19, 20, 21},
         {22, 23, 24}}};
    imprimir_arreglo_de_matrices_3d_de_2_por_3(arreglo3D, 4);

    printf("\nArreglo 3D de P matrices de NxM:\n");
    int arreglo3DdeP[2][2][3] = {
        {{1, 2, 3},
         {4, 5, 6}},
        {{7, 8, 9},
         {10, 11, 12}}};
    imprimir_arreglo_3d_de_P_matrices_de_N_por_M(2, 2, 3, arreglo3DdeP);

    return 0;
}
```

### Usar cada fila de una matriz de forma independiente
Ya que en C tenemos a las matrices definidas como "arreglos de arreglos", podemos usar cada fila de una matriz como si fuera un arreglo.

```c
#include <stdio.h>

/**
 * Imprime un arreglo en formato bonito
 * [1, 2, 3, 4, 5]
 */
void imprimir_arreglo(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]");
}

/**
 * Imprime una matriz en formato bonito,
 * cada fila se imprime en una línea diferente
 * [
 *  [1, 2, 3],
 *  [4, 5, 6]
 * ]
 */
void imprimir_matriz(int filas, int columnas, int matriz[][columnas])
{
    printf("[\n");
    for (int i = 0; i < filas; i++)
    {
        printf("  ");
        imprimir_arreglo(matriz[i], columnas);
        if (i < filas - 1)
        {
            printf(",");
        }
        printf("\n");
    }
    printf("]\n");
}

int main()
{
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Imprimir un arreglo de la matriz:\n");
    imprimir_arreglo(matriz[0], 3);

    printf("\n\nImprimir la matriz:\n");
    imprimir_matriz(2, 3, matriz);

    return 0;
}
```

## Ejercicios

### Básico: leer e imprimir matrices
Escribe las funciones:
- `read_matrix(int filas, int columnas, int matriz[][columnas])` que lea del usuario suficientes numeros para llenar una matriz de `filas` por `columnas` del usuario, que la funcion recibe.
- `print_matrix(int filas, int columnas, int matriz[][columnas])` que imprima la matriz en formato de tabla.

Esqueleto del programa:
```c
#include <stdio.h>

void print_matrix(int filas, int columnas, int matriz[][columnas])
{
    // tu codigo aqui
}

void read_matrix(int filas, int columnas, int matriz[][columnas])
{
    // tu codigo aqui
}

int main()
{
    int matriz[2][3];
    read_matrix(2, 3, matriz);

    return 0;
}
```

### Lista de nombres
Una matriz `char nombres[5][20]` puede almacenar 5 nombres de hasta 19 caracteres cada uno.

1. Escribe un programa que lea 5 nombres del usuario y los guarde en esa matriz.
2. Termina de implementar la función `print_names()` que imprime los nombres en formato de lista.

Esqueleto del código:
```c
#include <stdio.h>

void print_names(/* ¡faltan los parámetros! */)
{
    // tu codigo aqui
}

int main()
{
    char nombres[5][20];

    // el codigo que lee los nombres del usuario y los guarda en la matriz

    // llama aqui tu funcion print_names para imprimir los nombres

    // que el formato de impresion en lista sea:
    // 1. Nombre 1
    // 2. Nombre 2
    // 3. Nombre 3
    // ...

    return 0;
}
```

### Ganador de un juego de gato
Considera un tablero de gato como una matriz de 3x3, en la que 0 significa que no hay nada en esa casilla, 1 significa que el jugador 1 puso una X y 2 significa que el jugador 2 puso una O.

Escribe un programa que lea un tablero de gato del usuario y determine si hay un ganador, y si lo hay, imprima el número del jugador que ganó. Estos son los posibles valores de retorno de la función `ganador_gato`:
- 0 si no hay ganador
- 1 si el jugador 1 ganó
- 2 si el jugador 2 ganó

Esqueleto del programa:
```c
#include <stdio.h>

/**
 * Recibe un tablero de gato y determina si hay un ganador.
 * Regresa:
 * - 0 si no hay ganador
 * - 1 si el jugador 1 ganó
 * - 2 si el jugador 2 ganó
 */
int ganador_gato(int tablero[3][3])
{
    // tu codigo aqui
}

int main()
{
    int tablero[3][3];

    // el codigo que lee el tablero del usuario

    int ganador = ganador_gato(tablero);
    if (ganador == 0)
    {
        printf("No hay ganador\n");
    }
    else
    {
        printf("El ganador es el jugador %d\n", ganador);
    }

    return 0;
}
```

### Suma de matrices
Implementa la función suma_matrices, que recibe 3 matrices a, b y result, todas de las mismas dimensiones. La función debe sumar las matrices a y b y guardar el resultado en la matriz result.

Reutiliza tus funciones `read_matrix` y `print_matrix` para leer las matrices a y b del usuario y para imprimir la matriz resultante.

Esqueleto del programa:
```c
#include <stdio.h>

void read_matrix(int filas, int columnas, int matriz[][columnas])
{
    // tu codigo aqui
}

void print_matrix(int filas, int columnas, int matriz[][columnas])
{
    // tu codigo aqui
}

void suma_matrices(int filas, int columnas, int a[][columnas], int b[][columnas], int result[][columnas])
{
    // tu codigo aqui
}

int main()
{
    int rows, cols;
    printf("Ingrese el número de filas y columnas de las matrices: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0)
    {
        printf("Las dimensiones de la matriz deben ser mayores a 0\n");
        return 1;
    }

    printf("Ingrese la matriz A:\n");
    // tu codigo aqui

    printf("Ingrese la matriz B:\n");
    // tu codigo aqui


    suma_matrices(2, 3, a, b, result);

    printf("La suma de las matrices es:\n");
    print_matrix(rows, cols, result);

    return 0;
}
```

### Mover un personaje en un mapa
Considera un mapa como una cuadricula de 10x10, en la que cada celda puede estar vacía o contener un obstáculo. Escribe un programa que permita mover un personaje en el mapa, representado por una matriz de 10x10.

El personaje se mueve con las teclas W, A, S, D, que corresponden a arriba, izquierda, abajo y derecha, respectivamente. Si el personaje intenta moverse a una celda con un obstáculo, no se mueve.

Objetos en el mapa:
- 0: celda vacía
- p: personaje
- #: obstáculo

Funciones a implementar:
- `void print_map(char map[100][100])`: imprime el mapa en formato de cuadricula. Puedes cambiar el tamaño del mapa si deseas.
- `char get_move_direction()`: lee del usuario hasat que se especifique una direccion válida (W, A, S, D), y la devuelve.
- `int move_character(char map[100][100], char direction)`: mueve el personaje en la dirección indicada. Devuelve 1 si el personaje se movió, 0 si no se movió. `Direction` puede ser 'W', 'A', 'S' o 'D'.