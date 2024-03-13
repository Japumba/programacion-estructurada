# Arreglos como argumentos
Pasar un valor de una variable a una función es una de las cosas más comunes que hacemos en programación. 

Hasta ahora hemos visco cómo se copian los valores para enviarlos a una función, y no se modifican las variables originales. Esto se llama "pasar un parámetro _por valor_".
```c
#include <stdio.h>

void duplicar(int x) {
    x = x * 2;
}

int main() {
    int numero = 5;
    
    duplicar(numero);

    printf("%d\n", numero);

    return 0;
}
```

En el ejemplo anterior, el valor de `numero` no cambia, ya que la función `duplicar` recibe una copia del valor de `numero`, y no la referencia a la variable original.

Imaginemos que tenemos un arreglo de 10,000 elementos y queremos enviárselo a una función. Si tuviéramos que copiar todo el arreglo para poderlo enviar a la función, estaríamos haciendo un movimiento gigante de memoria cada vez, lo que sería muy ineficiente.

Esta es una de las razones por las que los arreglos no se pasan "como copias", sino que se pasa una **referencia** al arreglo original, específicamente al primer elemento del arreglo. Esto se llama "pasar un parámetro _por referencia_".

Veamos un ejemplo de una función que recibe un arreglo como parámetro:
```c
#include <stdio.h>

//           recibe un arreglo de 5 elementos
//                         v
void imprimir_arreglo(int arreglo[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main()
{
    int arreglo[] = {1, 2, 3, 5, 8};
    imprimir_arreglo(arreglo);

    return 0;
}
```

En el ejemplo anterior estamos limitados a elementos de 5 elementos, ya que el tamaño del arreglo es parte del tipo de dato del parámetro. Si queremos que la función reciba arreglos de cualquier tamaño, necesitamos indicar el tamaño del arreglo en otro parámetro. Esta es la práctica común:
```c
#include <stdio.h>

//           recibe un arreglo de enteros
//                         |       
//                         |        y su tamaño
//                         |              |
//                         v              v
void imprimir_arreglo(int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main()
{
    int arreglo1[] = {1, 2, 3, 5, 8};
    imprimir_arreglo(arreglo, 5);

    int arreglo2[] = {1, 2, 3, 5, 8, 13, 21, 34};
    imprimir_arreglo(arreglo, 8);

    return 0;
}
```

De esa forma podemos enviar arreglos de cualquier tamaño a una función.