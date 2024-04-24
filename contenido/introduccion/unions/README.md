# Uniones
Asi como los structs, tenemos otra forma de definir tipos de datos propios. Con las uniones, podemos definir un tipo de dato que puede almacenar diferentes tipos de datos, pero solo uno a la vez.

No es como en python donde las variables pueden ser de cualquier tipo, sino que de forma anticipada, definimos qué tipo de datos puede almacenar nuestra union.

Luego, podemos acecder al valor almacenado en la union interpretándolo como si fuera alguno de los tipos indicados.

## Definición
Para definir una union, usamos la palabra reservada `union` seguida del nombre de la union y las llaves `{}` que contienen los tipos de datos que puede almacenar.

```c
#include <stdio.h>

typedef union
{
    int entero;
    float flotante;
    char caracter;
} MiUnion;

int main()
{
    MiUnion u;

    printf("Asignar y leer cada tipo:\n");
    u.entero = 10;
    printf("  Entero: %d\n", u.entero);

    u.flotante = 3.14;
    printf("  Flotante: %f\n", u.flotante);

    u.caracter = 'A';
    printf("Caracter: %c\n", u.caracter);

    printf("\nValores de los tipos distintos al ultimo asignado:\n");
    // Ahora, si accedemos a los tipos anteriores, obtendremos un valor indeterminado porque va a leer lo almacenado en la memoria "como si fuera un tipo distinto del que realmente es"
    printf("  Entero: %d\n", u.entero);
    printf("  Flotante: %f\n", u.flotante);

    return 0;
}
```

## Caracteristicas
- **Tamaño**: El tamaño de una union es el tamaño del tipo de dato más grande que puede almacenar.
    ```c
    union {
        int entero;
        float flotante;
        char caracter;
    };
    ```
    En este caso, el tamaño de la union será el tamaño de un `float` porque es el tipo de dato más grande que puede almacenar.
- **Acceso**: Podemos acceder a los datos almacenados en la union como si fueran de cualquier tipo indicado en la definición, no importa cuál fue el último tipo asignado.

## Usos
- **Optimización de memoria**: Si sabemos que solo vamos a usar un tipo de dato a la vez, podemos usar una union para ahorrar memoria.
- **Acceso a diferentes tipos de datos**: Si tenemos un dato que puede ser de diferentes tipos, podemos usar una union para acceder a él de forma más sencilla.
- **Acceder a bits**: Si queremos acceder a los bits de un dato, podemos usar una union para acceder a ellos de forma más sencilla.

## Ejemplos

### Inspector de Flotante
Aqui tenemos un ejemplo de como podemos usar una union para acceder a los bits de un flotante.

```c
#include <stdio.h>

typedef union
{
    float flotante;
    unsigned int entero;
} FloatInspector;

void imprimir_binario(unsigned int numero)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (numero >> i) & 1);
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    FloatInspector f;
    f.flotante = 3.5;

    printf("Valor flotante: %f\n", f.flotante);
    printf("Hex:     0x%0x\n", f.entero);
    printf("Binario: 0b");
    imprimir_binario(f.entero);
}
```

### Color RGBA
En este ejemplo, usamos una union para almacenar un color RGBA y acceder a sus componentes por separado. El struct "sin nombre" dentro de la union nos permite acceder a los componentes del color como si fueran variables independientes. Cada campo del struct se "descompone" en el color.
```c
#include <stdio.h>

typedef union
{
    unsigned int color;
    struct
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };
} RGBA;

int main()
{
    RGBA c1;
    c1.color = 0xFF0000FF;
    printf("#%08X\n", c1.color);
    printf("rgba(%d, %d, %d, %d)\n", c1.r, c1.g, c1.b, c1.a);
    return 0;
}
```

### Ayudarnos de un Struct
Para saber qué tipo de dato está almacenado en la union, podemos usar un struct que contenga un campo que indique el tipo de dato almacenado y otro campo que almacene el valor. De esta forma, podemos saber qué tipo de dato está almacenado en la union y acceder a él de forma más sencilla.
```c
#include <stdio.h>

typedef enum
{
    TIPO_ENTERO,
    TIPO_FLOTANTE,
    TIPO_CARACTER
} TipoDato;

typedef struct
{
    TipoDato tipo;
    union
    {
        int entero;
        float flotante;
        char caracter;
    } valor;
} Dato;

void imprimir_dato(Dato d)
{
    switch (d.tipo)
    {
    case TIPO_ENTERO:
        printf("Entero: %d\n", d.valor.entero);
        break;
    case TIPO_FLOTANTE:
        printf("Flotante: %f\n", d.valor.flotante);
        break;
    case TIPO_CARACTER:
        printf("Caracter: %c\n", d.valor.caracter);
        break;
    }
}

int main()
{
    Dato d1 = {TIPO_ENTERO, .valor.entero = 10};

    Dato d2;
    d2.tipo = TIPO_FLOTANTE;
    d2.valor.flotante = 3.14;

    Dato d3 = {TIPO_CARACTER};
    d3.valor.caracter = 'A';

    imprimir_dato(d1);
    imprimir_dato(d2);
    imprimir_dato(d3);

    return 0;
}
```

### Bytes de un entero
En este ejemplo, usamos una union para acceder a los bytes de un entero de 4 bytes. De esta forma, podemos acceder a los bytes de un entero de forma más sencilla.
```c
#include <stdio.h>

typedef union
{
    int entero;
    unsigned char bytes[4];
} EnteroInspector;

int main()
{
    EnteroInspector e;
    e.entero = 1;

    printf("Entero: %08X\n", e.entero);
    printf("Bytes:          %02X %02X %02X %02X\n", e.bytes[0], e.bytes[1], e.bytes[2], e.bytes[3]);
    printf("Bytes al reves: %02X %02X %02X %02X\n", e.bytes[3], e.bytes[2], e.bytes[1], e.bytes[0]);

    return 0;
}
```
