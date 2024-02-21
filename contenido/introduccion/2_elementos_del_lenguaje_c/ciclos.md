# Ciclos
En C, tenemos 3 formas de hacer ciclos, o de tener repeticiones controladas de código. Estos son:
- `for`: Ciclo que normalmente tiene un numero fijo de repeticiones, por ejemplo, un rango.
- `while`: Ciclo que se repite mientras alguna condición sea verdadera, no necesariamente un rango.
- `do-while`: Ciclo que se ejecuta al menos una vez, y luego se repite mientras alguna condición sea verdadera.

Tenemos también algunas palabras reservadas para ayudarnos a controlar el flujo de los ciclos:
- `break`: Termina el ciclo actual.
- `continue`: Salta a la siguiente iteración del ciclo actual.

## For
El ciclo `for` es el más común, y se utiliza cuando se conoce el número de repeticiones que se desean. La sintaxis es la siguiente:
```c
for (inicialización; condición; actualización) {
    // Código a repetir
}
```

Donde:
- `inicialización`: Es una expresión que se ejecuta una sola vez, al inicio del ciclo. Normalmente se utiliza para inicializar una o más variables útiles en el ciclo.
- `condición`: Es una expresión que se evalúa al inicio de cada iteración. Si es verdadera, se ejecuta el código del ciclo, si es falsa, se termina el ciclo.
- `actualización`: Es una expresión que se ejecuta al final de cada iteración. Normalmente se utiliza para actualizar una o más variables útiles en el ciclo.

Por ejemplo, el siguiente código imprime los números del 1 al 10:
```c
for (int i = 1; i <= 10; i++) {
    printf("%d\n", i);
}
```

En el codigo anterior:
- `inicialización`: `int i = 1;` Se crea una variable `i` y se le asigna el valor de 1. Esta variable sólo existirá dentro del ciclo.
- `condición`: `i <= 10;` Se evalúa si `i` es menor o igual a 10. Si es verdadero, se ejecuta el código del ciclo, si es falso, se termina el ciclo.
- `actualización`: `i++` Se incrementa el valor de `i` en 1. El operador `++` incrementa el valor de la variable en 1, es lo mismo que `i = i + 1`.

Para un for, es importante considerar:
- ¿Qué variables de control necesito?
- ¿Qué valor de inicio y fin necesito, para tener exactamente las repeticiones que necesito?
- ¿Qué operación debo hacer en cada iteración (incrementar, decrementar, qué valores...)?

### Ejercicios
- Imprime los números de 10 al 1 en cuentra regresiva usando un for.
- Escribe un programa que imprima una barrita de progreso para representar el porcentaje:
    ```txt
    Que porcentaje?: 0
    [          ] 0%

    Que porcentaje?: 15
    [==        ] 15%

    Que porcentaje?: 50
    [=====     ] 50%

    Que porcentaje?: 90
    [========= ] 90%

    Que porcentaje?: 100
    [==========] 100%
    ```

## While
El ciclo `while` se utiliza normalmente cuando no se conoce el número de repeticiones que se desean, pero se conoce una condición que debe cumplirse para que el ciclo se repita. La sintaxis es la siguiente:
```c
while (condición) {
    // Código a repetir
}
```

Donde:
- `condición`: Es una expresión que se evalúa al inicio de cada iteración. Si es verdadera, se ejecuta el código del ciclo, si es falsa, se termina el ciclo.

Por ejemplo, el siguiente código ayuda al usuario a seguir ingresando datos hasta que éste ingrese una letra mayúscula.
```c
char letra;

printf("Ingrese una letra mayúscula: ");
scanf(" %c", &letra);

while(letra < 'A' || letra > 'Z') {
    printf("Que sea mayuscula, por favor:");
    scanf(" %c", &letra);
}

printf("La letra ingresada es: %c\n", letra);
```

En el codigo anterior:
- `condición`: `letra < 'A' || letra > 'Z'` Se evalúa si `letra` es menor a 'A' o mayor a 'Z'. Si es verdadero, no es mayúscula y se solicita una letra.

Otro ejemplo sería el siguiente código que imprime los números del 1 al 10, pero de una forma distinta que con el for.
```c
int i = 1;

while (i <= 10) {
    printf("%d\n", i);
    i++;
}
```

En el codigo anterior:
- No tenemos un lugar fijo para la inicialización como en el `for`, por lo que debemos hacerlo manualmente. En este caso, se inicializa `i` en 1.
- `condición`: `i <= 10` Se evalúa si `i` es menor o igual a 10. Si es verdadero, se ejecuta el código del ciclo, si es falso, se termina el ciclo.
- No tenemos un lugar fijo para la actualización como en el `for`, por lo que debemos hacerlo manualmente. En este caso, se incrementa `i` en 1.

### Ejercicios
- Imprime los números del 1 al 100 usando un while.
- Pide al usuario que ingrese numeros positivos, y un negativo para terminar la entrada de datos y calcular el promedio.
    ```txt
    Calculador de promedios. Ingrese tantos numeros positivos como desee y uno negativo para terminar.
    Ingrese un numero (-1 para salir): 1
    Ingrese un numero (-1 para salir): 34
    Ingrese un numero (-1 para salir): 6
    Ingrese un numero (-1 para salir): 4
    Ingrese un numero (-1 para salir): 3
    Ingrese un numero (-1 para salir): -1
    El promedio de los numeros ingresados es: 9.60
    ```

## Do-While
Finalmente tenemos el ciclo `do-while`, que es similar al `while`, pero se ejecuta al menos una vez, y luego se repite mientras alguna condición sea verdadera. Podemos notar que en este caso la condición se evalúa al final de cada iteración. La sintaxis es la siguiente:
```c
do {
    // Código a repetir
} while (condición);
```

Por ejemplo, el siguiente código es una alternativa a nuestra implementación anterior para que el usuario ingrese una letra mayúscula.
```c
char letra;

do {
    printf("Ingrese una letra mayúscula: ");
    scanf(" %c", &letra);
} while(letra < 'A' || letra > 'Z');

printf("La letra ingresada es: %c\n", letra);
```

## Ciclos Anidados
Es posible tener ciclos dentro de otros ciclos, esto se conoce como ciclos anidados. Por ejemplo, el siguiente código imprime una tabla de multiplicar del 1 al 10.
```c
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%d x %d = %d\n", i, j, i * j);
    }
    printf("\n");
}
```

Podemos ver que el ciclo `for` que imprime la tabla de multiplicar está dentro de otro ciclo `for` que va del 1 al 10. Esto significa que el ciclo interno se ejecutará 10 veces, una por cada iteración del ciclo externo.

### Ejercicios
- Imprime un cuadrado de 3x5 con asteriscos usando ciclos anidados.
    ```txt
    *****
    *****
    *****
    ```
- Solicita al usuario el alto de una pirámide, y luego imprímela con astericos
    ```txt
    Que tan alta?: 3
      *
     ***
    *****
    ```

    ```txt
    Que tan alta?: 4
       *
      ***
     *****
    *******
    ```

## Break y Continue
Finalmente, tenemos las palabras reservadas `continue` y `break` que nos ayudan a controlar el flujo de los ciclos.

La palabra `continue` termina la iteración actual, y el flujo de ejecución salta a la siguiente iteración del ciclo. Por ejemplo, el siguiente código imprime los números del 1 al 10, pero salta el 5:
```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        continue;
    }

    printf("%d\n", i);
}
```

El siguiente codigo imprime todos los numeros del 1 al 100. Quisiéramos que sólo se imprimieran los números pares.

¿Cómo podemos hacerlo con la instrucción `continue`?
```c
for (int i = 1; i <= 100; i++) {
    printf("%d\n", i);
}
```

La palabra `break` termina el ciclo actual, y el flujo de ejecución continúa después del ciclo. Por ejemplo, el siguiente código imprime números y termina en el primer múltiplo de 13:

```c
for (int i = 1; i <= 100; i++) {
    if (i % 13 == 0) {
        break;
    }

    printf("%d\n", i);
}
```

El siguiente es un ciclo infinito. ¿Cómo podemos terminarlo en caso de encontrarnos con el numero 77?
```c

int numero = 0;

printf("Dime el 77\n");

while(1) {
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
}

printf("Adios!");
```

## Ejercicio final
Haz un programa que te adivine el numero, haciéndote preguntas
```txt
Piensa en un numero entre el 1 y el 100 y lo adivinare.
Presiona cualquier tecla cuando lo hayas pensado.

Tu numero es mas (b)ajo o (a)lto que 50, o es (c)orrecto?: b
Tu numero es mas (b)ajo o (a)lto que 25, o es (c)orrecto?: a
Tu numero es mas (b)ajo o (a)lto que 37, o es (c)orrecto?: a
Tu numero es mas (b)ajo o (a)lto que 43, o es (c)orrecto?: b
Tu numero es mas (b)ajo o (a)lto que 40, o es (c)orrecto?: a
Tu numero es mas (b)ajo o (a)lto que 41, o es (c)orrecto?: a
Tu numero es mas (b)ajo o (a)lto que 42, o es (c)orrecto?: c
¡Adiviné!
```
