# Comentarios, Identificadores y Palabras Reservadas
Partimos de un programa mínimo en C:
```c
#include <stdio.h>

/*
    Esta función es la principal. El programa comienza ejecutándose aquí
*/
int main() {

    // saludemos al mundo
    printf("hola, mundo!\n");

    return 0; // regresamos 0 porque no hay error 👑🇪🇸
}
```

## Un programa es un archivo de texto
Un programa escrito en C es un archivo (o muchos) de texto plano, que contiene instrucciones para que el compilador genere un ejecutable. Las palabras originales del archivo se perderán, y solo el ejecutable será el resultado de la compilación.

Entonces, todas las letras y palabras (excepto lo que esté comentado), tienen un propósito y un significado en el programa.

Por ejemplo, el símbolo `#` al inicio de la línea le dice al compilador que esa línea es una instrucción para el preprocesador, otro actor en el proceso de programación en C.

Existen varios tipos de símbolos que podemos encontrar en un programa de C:

### Comentarios
Un comentario es una sección del código que será ignorada por el compilador. Esta sección puede ser una parte de una línea (el final de ella), una línea completa o varias líneas.

```c
#include <stdio.h>

int main() {
    
    int power = 9000; // esto es un comentario al final de la línea

    // esto es un comentario de una línea
    power = power + 1;

    /*
        Esto es un comentario
        de varias líneas
    */
    printf("The scouter says its power level is %d. It's over 9000!!!\n", power);
}

```

### Identificadores
Definidos por quien programa, son los nombres que le damos a las variables, funciones, estructuras, etc.

Como en todos los lenguajes, en C existen reglas para definir identificadores:

|Regla|Ejemplos|
|---|---|
|Deben comenzar con una letra, un guión bajo (`_`) o un signo de dólar (`$`).|`_edad`, `$edad`, `edad`|
|Los caracteres que le siguen pueden ser letras, números o guiones bajos. Cuando decimos letras, nos referimos a las letras del alfabeto inglés, mayúsculas y minúsculas. No es permitido usar letras con acentos, eñes, diéresis, etc.|`edad`, `edad_2`, `edad_2_3`|
|No pueden ser palabras reservadas|`int`, `float`, `if` y `for` no pueden ser identificadores.|
|Se distingue entre mayúsculas y minúsculas.|`edad` y `Edad` son dos identificadores distintos.|
|La longitud mínima es de un caracter.|`int a = 16`|
|La longitud máxima depende del compilador, pero normalmente puede pasar los 300 caracteres.|`esta_es_una_variable_con_un_nombre_largo`|
|Al declarar una variable, no puede tener el mismo nombre que otra variable declarada en el mismo ámbito, porque ocasiona colisiones.|`int edad = 16; int edad = 17;` ocasiona error de compilación|

```c
#include <stdio.h>

// do_kessel_run es un identificador de una funcion
void do_kessel_run(int parsecs) {
    printf("I did the Kessel Run in less than %d parsecs!\n", parsecs);
}

// main también es un identificador de una función, y es especial porque es el punto de entrada de un programa en C
int main() {
    int parsecs = 12; // parsecs es un identificador de una variable

    do_kessel_run(parsecs); // llamamos una función a través de su identificador. Podemos pasarle valores a una función, por ejemplo el valor de la variable parsecs
}

```

### Palabras reservadas
Son las palabras que tienen un significado especial para el compilador. Por ejemplo, `int` es una palabra reservada que le dice al compilador que lo que le sigue es de tipo entero.

Las siguientes son las palabras reservadas en C:

|Palabra reservada|Descripción|
|---|---|
|`auto`|Especifica que una variable es de almacenamiento automático.|
|`break`|Termina la ejecución de un ciclo o un switch.|
|`case`|Etiqueta para un caso en un switch.|
|`char`|Tipo de dato para caracteres.|
|`const`|Especifica que una variable es de solo lectura.|
|`continue`|Salta a la siguiente iteración de un ciclo.|
|`default`|Etiqueta para un caso por defecto en un switch.|
|`do`|Inicia un ciclo do-while.|
|`double`|Tipo de dato para números de punto flotante de doble precisión.|
|`else`|Especifica una condición alternativa para un if.|
|`enum`|Define un tipo de dato enumerado.|
|`extern`|Especifica que una variable es definida en otro lugar.|
|`float`|Tipo de dato para números de punto flotante de precisión simple.|
|`for`|Inicia un ciclo for.|
|`goto`|Transfiere el control a una etiqueta.|
|`if`|Especifica una condición a evaluar.|
|`int`|Tipo de dato para enteros.|
|`long`|Tipo de dato para enteros largos.|
|`register`|Especifica que una variable es de almacenamiento de registro.|
|`return`|Termina la ejecución de una función y regresa un valor.|
|`short`|Tipo de dato para enteros cortos.|
|`signed`|Tipo de dato para enteros con signo.|
|`sizeof`|Devuelve el tamaño de un tipo de dato o una variable.|
|`static`|Especifica que una variable es de almacenamiento estático.|
|`struct`|Define una estructura.|
|`switch`|Inicia un switch.|
|`typedef`|Define un tipo de dato.|
|`union`|Define una unión.|
|`unsigned`|Tipo de dato para enteros sin signo.|
|`void`|Especifica que una función no tiene valor de retorno.|
|`volatile`|Especifica que el valor de una variable puede cambiar en cualquier momento.|
|`while`|Inicia un ciclo while.|

Muchas de estas palabras no serán claras en este momento ni está en el alcance del curso, pero dependiendo de la trayectoria que tomes, las irás conociendo.

### Operadores
Son los símbolos que usamos para realizar operaciones. Por ejemplo, `+` es un operador que suma dos valores.

- **Literales**: Son los símbolos que representan valores constantes. Por ejemplo, `42` es un literal decimal que representa el número cuarenta y dos. Profundizaremos un poco en las literales más adelante.

- **Espacios en blanco**: Son los símbolos que usamos para separar palabras. Estos son ignorados por el compilador.

- **Caracteres de escape**: Son los símbolos que usamos para representar caracteres especiales. Por ejemplo, `\n` es un caracter de escape que representa un salto de línea.

- **Delimitadores**: Son los símbolos que usamos para delimitar bloques de código. Por ejemplo, `{` y `}` delimitan un bloque de código.

- **Separadores**: Son los símbolos que usamos para separar elementos. Por ejemplo, `,` es un separador que usamos para separar argumentos de una función.
