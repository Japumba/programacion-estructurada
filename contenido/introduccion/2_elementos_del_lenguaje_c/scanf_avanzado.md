## Más detalles de input y output

### Otras funciones de entrada y salida
Entre todas las opciones para leer y escribir en la consola, existen otras dos funciones que son útiles para manejo de caracteres individuales:
- **getchar():** Lee un caracter de la entrada estándar y lo devuelve como un unsigned char (0 a 255).
    ```c
    char c;
    c = getchar();
    printf("c: %c\n", c);
    ```
- **putchar():** Escribe un caracter en la salida estándar.
    ```c
    char c = 'a';
    putchar(c);
    ```

A diferencia de scanf y printf, éstos no requieren de formato (porque siempre leen o escriben un solo caracter) y al leer no se tiene que pasar la variable con el ampersand (&), porque la función regresa el valor leído para ser asignado.

### Buffer de entrada y salida
Analiza este programa con detenimiento; ¿qué esperas que suceda con la entrada y salida de datos?
```c
#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    while(c != 'X')
    {
        printf("suena el eco de '%c'.\n", c);
        scanf("%c", &c);
    }

    printf("bye\n");
    return 0;
}
```
Lo intuitivo sería pensar que el programa da un "eco" de lo que el usuario ingresa, por ejemplo si el usuario ingresa 'a', el programa debería imprimir "suena el eco de 'a'." y así sucesivamente hasta que el usuario ingrese 'X', en cuyo caso el programa debería imprimir "bye" y terminar.

**Salida de ejemplo**
```txt
a
suena el eco de 'a'.
suena el eco de '
'.
b
suena el eco de 'b'.
suena el eco de '
X
bye
'.
```

Sin embargo, si ejecutas el programa, te darás cuenta que no funciona así.

Podemos ver que, además de imprimir el eco de la letra ingresada, se imprime también un salto de línea.

¿Qué tecla presiona el usuario luego de alguna letra? La tecla "Enter". Este Enter, junto con todo lo que el usuario ingresa, se guarda en un lugar del programa llamado "búffer de entrada", y de ahí es tomado por scanf y otras funciones.

Intenta ingresar muchos caracteres y luego enter:
```txt
abcde
suena el eco de 'a'.
suena el eco de 'b'.
suena el eco de 'c'.
suena el eco de 'd'.
suena el eco de 'e'.
suena el eco de '
'.
```

La función `scanf` requiere leer un formato, y lo hace no directamente de la terminal, sino del buffer de entrada estándar. Ahora, cuando se ejecuta la función scanf, primero se revisa si el buffer tiene algo aún y si no es así, se pide al usuario que ingrese algo.

El usuario ingresa un conjunto de caracteres y luego presiona ENTER. Este ENTER también se envía al buffer y es leído por la siguiente llamada a scanf. Por eso, el programa imprime el eco de un salto de línea, porque está en un while.

¿Pasa también con getchar?
```c
#include <stdio.h>

int main()
{
    char c;
    c = getchar();
    while(c != 'X')
    {
        printf("suena el eco de '%c'.\n", c);
        c = getchar();
    }

    printf("bye\n");
    return 0;
}
```
**Salida de ejemplo**
```txt
a
suena el eco de 'a'.
suena el eco de '
'.
b
suena el eco de 'b'.
suena el eco de '
'.
c
suena el eco de 'c'.
suena el eco de '
'.
X
bye
```
Sí sucede, porque getchar también lee del buffer de entrada.

**¿Cómo leemos solo el caracter?**
Tenemos una función llamada `fflush` que limpia un búffer que se le envíe como parámetro. Podemos entonces limpiar nuestro buffer con `fflush(stdin)` antes de leer un caracter, si queremos asegurarnos que no hay nada.
```c
#include <stdio.h>

int main()
{
    char c;

    // en la primera llamada no se necesita limpiar el buffer, porque empieza vacío
    c = getchar();

    while(c != 'X')
    {
        printf("suena el eco de '%c'.\n", c);

        fflush(stdin); // Limpiamos el buffer antes de volver a leer
        c = getchar();
    }

    printf("bye\n");
    return 0;
}
```
**Salida de ejemplo**
```txt
a
suena el eco de 'a'.
b
suena el eco de 'b'.
c
suena el eco de 'c'.
X
bye
```

La función `fflush` podemos usarla siempre que queramos leer datos desde cero, es muy útil al leer de interfaces de terminal.

## Scanf y el buffer de entrada

### Datos numéricos
1. Si el buffer esta vacio, pide al usuario que ingrese algo.
2. Va leyendo del buffer todos los caracteres espacio, tab y enter, y los quita. Lo que busca son números.
3. Al encontrar el primer caracter valido para un número, comienza a leerlo y sigue leyendo hasta encontrar el primer caracter que no coincida con el formato que se le pidió. Interpreta los dígitos leídos y los guarda en la variable correspondiente. NO REMUEVE EL CARACTER INVALIDO DEL BUFFER.
4. Si hay otro scanf, sigue leyendo de donde se quedó.
```c
#include <stdio.h>

int main()
{
    int n;
    int leido = 0;
    leido = scanf("%d", &n);
    printf("n = %d\n", n);
    printf("leido = %d\n", leido);

    leido = scanf("%d", &n);
    printf("n = %d\n", n);
    printf("leido = %d\n", leido);

    printf("en el buffer queda:");
    char c;
    while ((c = getchar()) != '\n')
    {
        putchar(c);
    }

    return 0;
}
```

**Salida de ejemplo**
```txt
3.14
n = 3
leido = 1
n = 3
leido = 0
en el buffer queda:.14%
```