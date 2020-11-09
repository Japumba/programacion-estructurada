# Structs

## Ejercicios
- [1. Operaciones con vectores](exercises/vector.c)
- [2. Fecha y hora](exercises/datetime.c)

## Contenido
Un struct en C, también llamado "tipo estructura", es un tipo de dato conformado por muchos elementos nombrados, o "campos", que están guardados de forma secuencial y **pueden ser de distinto tipo**.

Este tipo de dato estructura **es definido por el programador**, es decir, el programador primero declara cómo estará compuesto este tipo, le da un nombre único y podrá posteriormente usarlo (es similar en este sentido a una enumeración, también definida por el programador).


### Declarar un tipo estructura
Para declarar un tipo estructura, utilizamos la palabra reservada `struct`, seguida del nombre de la estructura y a continuación, cada uno de los campos que conforman a este tipo estructura.

Cada campo tiene un tipo de dato y un identificador.

```C
// Contiene la informacion de un jugador en el mapa
struct player
{
    char avatar;         // campo de tipo char, llamado avatar.
    char name[15];       // podemos poner campos que sean arreglos o matrices.
    int posX, posY;      // dos campos de tipo int, para almacenar la posicion
    unsigned int health; // campo de tipo unsigned int, para almacenar la vida.
};
```
👀 _En la declaración de un tipo estructura no se asignan valores; lo que estamos haciendo es creando el tipo, para que esté disponible después. Cuando declaremos una variable de este tipo, le asignaremos valores._


### Crear una variable de tipo estructura
Una vez declarado el tipo estructura y todos sus campos, podemos usarlo para declarar variables y asignarle valores a sus campos, por ejemplo, para declarar una variable en nuestra función main que sea el jugador 1 y otra para el jugador 2.

Una vez declarada una variable de un tipo estructura, podemos asignarle valores a cada uno de sus campos, accediendo a ellos con el operador de acceso: el punto `.`

```C
#include <stdio.h>
#include <string.h>

// Contiene la informacion de un jugador en el mapa
struct player
{
    char avatar;         // campo de tipo char, llamado avatar.
    char name[15];       // podemos poner campos que sean arreglos o matrices.
    int posX, posY;      // dos campos de tipo double, para almacenar la posicion
    unsigned int health; // campo de tipo unsigned int, para almacenar la vida.
};

int main()
{
    // declarar las variables para jugador 1 y 2
    struct player p1, p2; // es necesario usar aqui tambien la palabra struct, seguida del nombre del struct, y luego el identificador de la(s) variable(s) declarada(s).

    // ponerle informacion al jugador 1
    p1.avatar = 'C'; // accedemos al campo llamado 'avatar' de la variable 'p1'
    strcpy(p1.name, "Cuasimodo"); // necesitamos usar strcpy
    p1.posX = 0;
    p1.posY = 0;
    p1.health = 100;

    // ponerle informacion al jugador 2
    p2.avatar = 'E';
    strcpy(p2.name, "Esmeralda");
    p2.posX = 3;
    p2.posY = 2;
    p2.health = 100;

    // acceder al valor de un campo
    printf("Player 1 name: %s\n", p1.name);
    printf("Player 2 position: (%i, %i)\n", p2.posX, p2.posY);

}
```


### Inicializar una variable de tipo estructura
Podemos inicializar una variable de un tipo de dato estructura similar a un arreglo. Indicamos entre las llaves cada uno de los campos, en el orden en el que fueron declarados:

```C
#include <stdio.h>

struct point
{
  double x, y;
  char name[10];
};

int main()
{
  struct point p1 = {10, 20, "Punto 1"}; // primero x, luego y y al final name
  printf("initialized point:     %s(%.2f, %.2f)\n\n", p1.name, p1.x, p1.y);

  // si no inicializamos, tiene datos basura:
  struct point p2;
  printf("not initialized point: %s(%.2f, %.2f)\n\n", p2.name, p2.x, p2.y);
}
```


### Tipos struct como argumentos
Podemos declarar una función que tome como argumento un valor de tipo estructura, para utilizarlo dentro.

```C
#include <stdio.h>

struct point
{
  double x, y;
  char name[10];
};

void printPoint(struct point p)
{
  printf("%s(%.1f, %.1f)\n", p.name, p.x, p.y);
}

int main()
{
  struct point p1 = {10, 20, "Punto 1"};
  struct point p2 = {42, 1337, "Punto 2"};

  printPoint(p1);
  printPoint(p2);
}
```

Cuando pasamos una variable de tipo estructura como argumento, esta variable se pasa por valor, lo que significa que no se modifica la variable original (como los `int` y `char`).

```C
#include <stdio.h>
#include <string.h>

struct point
{
  double x, y;
  char name[10];
};

void printPoint(struct point p)
{
  printf("%s(%.1f, %.1f)\n", p.name, p.x, p.y);
}

// intenta poner en 0 todos los valores,
// pero solo lo hace en la copia local
void intentarPonerEnCero(struct point p)
{
  strcpy(p.name, "Punto 0");
  p.x = 0;
  p.y = 0;
  printf("    Adentro de la funcion:    ");
  printPoint(p);
}

int main()
{
  struct point p1 = {10, 20, "Punto 1"};

  printf("Antes de llamar la funcion:   ");
  printPoint(p1);

  intentarPonerEnCero(p1);
  
  printf("Despues de llamar la funcion: ");
  printPoint(p1);
}
```

### Regresar un tipo estrucutra
Es posible regresar un tipo estructura de una funcion, para asignarlo a una variable o usarlo posteriormente:
```C
#include <stdio.h>
#include <string.h>

struct point {
  int x, y;
  char name[10];
};

// crea un nuevo punto y lo regresa, con los valores indicados
struct point pointWithValues(char name[10], int x, int y)
{
  struct point newPoint = {x, y};
  strcpy(newPoint.name, name);
  return newPoint;
}

int main()
{
  struct point p = pointWithValues("Point X", 42, 1337);
  
  printf("point: %s(%i, %i)\n",p.name, p.x, p.y);
}
```

## Typedef
Escribir el "nombre completo" de una estructura cada vez es muy largo y repetitivo. Afortunadamente, C tiene una herramienta llamada `typedef` (corto de "type definition") que nos permite ponerle un "sobrenombre" a un tipo de dato.

Con `typedef`, podemos indicarle al compilador que `Point2D` sea un sobrenombre para el tipo de dato `struct point`, de esta forma:

```C
#include <stdio.h>
#include <string.h>

struct point {
    int x, y;
    char name[10];
};

// ahora podemos referirnos a struct point con la palabra Point2D
typedef struct point Point2D;

// crea un nuevo punto y lo regresa, con los valores indicados
// hemos cambiado de struct point a Point2D, para que sea mas corto.
// en lugar de struct point pointWithValues(char name[10], int x, int y)
Point2D pointWithValues(char name[10], int x, int y)
{
    // en lugar de struct point newPoint = {x, y};
    Point2D newPoint = {x, y};
    strcpy(newPoint.name, name);
    return newPoint;
}

int main()
{
    // tambien para declarar las variables
    // en lugar de // struct point p = ...
    Point2D p = pointWithValues("Point X", 42, 1337);
  
    printf("point: %s(%i, %i)\n",p.name, p.x, p.y);
}
```

Tambien podemos hacerlo en la misma linea:
```C
typedef struct point {
    int x, int y;
    char name[10];
} Point2D;
```

Además, podemos hacerlo con otros tipos de datos como las enumeraciones; con esto, ya no tenemos que escribir `enum movement move;`, sino `Movement move`;
```C
typedef enum movement{
    UP = 'w',
    LEFT = 'a',
    DOWN = 's',
    RIGHT = 'd'
} Movement;

Movement askForMovement()
{
    // en lugar de enum movement move;
    Movement move;

    // ... codigo para pedir al usuario un movimiento

    return move;
}
```

## Estructuras anidadas
Ya que los campos de un struct son declaraciones y cada uno tiene un tipo de dato, es posible que un campo en un struct sea de un tipo struct. Con esto, es posible simplificar el ejemplo anterior del jugador:

```C
typedef struct struct_position {
    int x, y;
} Position;

// Contiene la informacion de un jugador en el mapa
typedef struct player
{
    char avatar;         // campo de tipo char, llamado avatar.
    char name[15];       // podemos poner campos que sean arreglos o matrices.

    Position position;   // un solo campo de tipo Position, en lugar de dos campos de tipo int, para almacenar la posicion
    unsigned int health; // campo de tipo unsigned int, para almacenar la vida.
} Player;
```

Para declarar e inicializar, es similar a las matrices: cuando inicializamos el campo "anidado", necesitamos indicarlo con otras llaves, tal como inicializando una estructura.

Para acceder, usamos varias veces el operador de acceso punto (`.`), para acceder a los campos del struct anidado.

```C
#include <stdio.h>

typedef struct struct_position {
    int x, y;
} Position;

// Contiene la informacion de un jugador en el mapa
typedef struct player
{
    char avatar;         // campo de tipo char, llamado avatar.
    char name[15];       // podemos poner campos que sean arreglos o matrices.

    Position position;   // un solo campo de tipo Position, en lugar de dos campos de tipo int, para almacenar la posicion
    unsigned int health; // campo de tipo unsigned int, para almacenar la vida.
} Player;

void printPlayer(Player p)
{
    printf("(%c) %s [", p.avatar, p.name);

    for(int i=0; i < p.health; i++){
        printf("<3");
        
        if(i != p.health-1)
          printf(" ");
    }

    printf("]\n");

    // accedemos a los campos X y Y del campo POSITION del jugador
    printf("pos: (%i, %i)\n", p.position.x, p.position.y);
}

int main()
{
    Player p1 = {
        'C',
        "Cuasimodo",
        {42, 1337}, // posicion, una estructura de tipo Position
        3
    };

    printPlayer(p1);
}
```