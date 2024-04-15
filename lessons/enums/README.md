# Enumeraciones

Las enumeraciones en C son una forma de defir un tipo de dato que puede tomar un conjunto de valores predefinidos, haciendo que el código sea más legible y mantenible.

Imagina un código que maneja tareas por hacer. Cada tarea podría estar en uno de los siguientes estados:
- `PENDIENTE`
- `EN_PROGRESO`
- `COMPLETADA`
- `CANCELADA`

Podríamos usar strings para cada valor posible, pero esto puede llevar a errores de escritura y hace más compleja la comparación de estados.

Podríamos también guadarlo en un int y usar directamente números y decir: 0 es Pendiente, 1 es En Progreso, 2 es Completada y 3 es Cancelada. Pero esto hace que el código sea menos legible y más propenso a errores. Tenemos que acordarnos que 0 es Pendiente, 1 es En Progreso, etc. y además podríamos asignarle un valor que no corresponda a ninguno de los estados.

La tercera opción es usar enumeraciones. Podemos definir un tipo de dato que tomará alguno de esos valores, y podemos usar el nombre en el código:

```c
#include <stdio.h>

enum Estado {
    PENDIENTE,
    EN_PROGRESO,
    COMPLETADA,
    CANCELADA
};

int main() {
    enum Estado estado = PENDIENTE;

    if (estado == PENDIENTE) {
        printf("La tarea está pendiente\n");
    }

    return 0;
}
```

Las enumeraciones son tratadas por el compilador como enteros, por lo que podemos asignarle un valor distinto a cada uno de los elementos de la enumeración. Si no asignamos un valor, el compilador asignará un valor incremental a cada uno de los elementos de la enumeración, empezando por 0.

```c
#include <stdio.h>

enum Estado {
    PENDIENTE = 1,
    EN_PROGRESO = 2,
    COMPLETADA = 3,
    CANCELADA = 4
};

int main() {
    enum Estado estado = PENDIENTE;

    if (estado == PENDIENTE) {
        printf("La tarea está pendiente\n");
    }

    if (estado == 1) {
        printf("La tarea está pendiente\n");
    }

    return 0;
}
```

Podemos asignar un valor solo a algunos elementos, y el compilador asignará valores incrementales a los elementos que no tengan un valor asignado.

```c
#include <stdio.h>

enum Estado {
    PENDIENTE = 1,
    EN_PROGRESO,    // 2, incrementando 1 al anterior
    COMPLETADA = 8,
    CANCELADA       // 9, incrementando 1 al anterior
};

int main() {
    printf("Estado pendiente: %d\n", PENDIENTE);
    printf("Estado en progreso: %d\n", EN_PROGRESO);
    printf("Estado completada: %d\n", COMPLETADA);
    printf("Estado cancelada: %d\n", CANCELADA);
}
```

## Ejercicio: [Limpieza de Código](clean-code/user-roles)
Actividades de limpieza de código usando enumeraciones.