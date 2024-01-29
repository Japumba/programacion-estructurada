# Modificadores de variables
Normalmente las variables tienen:
    - Un tipo de dato
    - Un identificador, o nombre
    - Un valor

```c
int edad = 31;
```

En C, podemos modificar una variable en algunos de estos componentes para que su comportamiento y utilidad cambien. A continuación, algunos de estos modificadores:

## Constante (const)
Este modificador se coloca antes del tipo de dato de la variable, y le indica al compilador que el valor de dicha variable no podrá cambiar durante la ejecución del programa. Esto causa que el compilador arroje un error si se intenta modificar el valor de la variable.

```c
#include <stdio.h>

int main() {
    const int edad = 31;
    edad = 32; // Error: no se puede modificar una constante
    return 0;
}
```

El código anterior arroja este error al compilar:
```bash
> gcc ./main.c -o main
./main.c:5:10: error: cannot assign to variable 'edad' with const-qualified type 'const int'
    edad = 32; // Error: no se puede modificar una constante
    ~~~~ ^
./main.c:4:15: note: variable 'edad' declared const here
    const int edad = 31;
    ~~~~~~~~~~^~~~~~~~~
1 error generated.
```

## Modificadores de signo
Los modificadores de signo se colocan antes del tipo de dato de la variable, y le indican al compilador que la variable podrá almacenar valores negativos. Esto es útil cuando sabemos que el valor de la variable puede ser negativo, y queremos ahorrar espacio en memoria.

Por defecto las variables en C son con signo, por lo que no es necesario colocar el modificador `signed`. Sin embargo, si queremos que una variable no tenga signo, podemos colocar el modificador `unsigned` antes del tipo de dato de la variable.

```c
#include <stdio.h>

int main() {
    int edad = -31;
    unsigned int edad_sin_signo = 31;

    printf("La edad es: %d\n", edad); // %d es para imprimir valores con signo

    printf("La edad sin signo es: %u\n", edad_sin_signo); // %u es para imprimir valores sin signo
    return 0;
}
```

¿Puedes notar que cambiamos la etiqueta de `%d` a `%u` en el `printf`? Esto es porque `%d` es para imprimir valores con signo, y `%u` es para imprimir valores sin signo. Es muy importante que si usas printf, uses la etiqueta correcta para el tipo de dato que estás imprimiendo.

¿Qué pasa si imprimimos un numero negativo con `%u`? En cuanto conozcas la representación de los enteros en memoria, sabrás por qué pasa esto:
```c
#include <stdio.h>

int main() {
    int edad = -31;
    unsigned int edad_sin_signo = 31;

    printf("La edad es: %u\n", edad);

    printf("La edad sin signo es: %u\n", edad_sin_signo);
    return 0;
}
```

## Modificadores de tamaño
Los modificadores de tamaño se colocan antes del tipo de dato de la variable, y le indican al compilador que la variable tendrá un tamaño diferente al que normalmente tiene. Lo que logramos con esto es almacenar valores más grandes que los que normalmente podríamos, o manejar mejor el espacio en memoria si sabemos el valor máximo de nuestras variables.

Los modificadores de tamaño son:
- short
- long
- long long

Estos modificadores se utilizan principalmente con el tipo de dato `int`, pero también pueden utilizarse con `double` y `float`. No pueden utilizarse con `char`.

### Short
El modificador `short` se usa con el tipo de dato `int`, e indica que la variable tendrá la mitad del tamaño normal. Por ejemplo, en una arquitectura de 32 bits, un `int` normalmente ocupa 4 bytes, pero si se le agrega el modificador `short`, ocupará 2 bytes.

```c
#include <stdio.h>

int main() {
    int edad = 31;
    short int edad_corta = 31;
    printf("La edad es: %d\n", edad);
    printf("La edad corta es: %d\n", edad_corta);
    printf("El tamaño de edad es: %d bytes\n", sizeof(edad));
    printf("El tamaño de edad_corta es: %d bytes\n", sizeof(edad_corta));
    return 0;
}
```

### Long
El modificador `long` puede ser usado con `int` y `double`, e indica que la variable tendrá el doble del tamaño normal. Por ejemplo, en una arquitectura de 32 bits, un `int` normalmente ocupa 4 bytes, pero si se le agrega el modificador `long`, ocupará 8 bytes.

En el caso del `int`, podemos usar dos veces el modificador `long`, y esto hará que la variable ocupe 8 bytes. En el caso del `double`, podemos usar una vez el modificador `long`, y esto hará que la variable ocupe 16 bytes.

```c
#include <stdio.h>

int main() {
    printf("## Int\n");
    printf("  Un int tiene %d bytes\n", sizeof(int));
    printf("  Un long int tiene %d bytes\n", sizeof(long int));
    printf("  Un long long int tiene %d bytes\n", sizeof(long long int));
    
    printf("\n## Double\n");
    printf("  Un double tiene %d bytes\n", sizeof(double));
    printf("  Un long double tiene %d bytes\n", sizeof(long double));

    return 0;
}

```

Es muy importante tener en cuenta que el modificador `long` dependerá de la arquitectura y del sistema operativo, por lo que no se garantiza que siempre sea el mismo tamaño. Por ejemplo, estos serían normalmente los tamaños en una arquitectura de 16 y 32 bits:

| Tipo de dato | en 16 bits | en 32 bits |
|--------------|------------|------------|
| int          | 2 bytes    | 4 bytes    |
| short int    | 2 bytes    | 2 bytes    |
| long int     | 4 bytes    | 8 bytes    |
| long long int| 8 bytes    | 8 bytes    |


#### Precisión del long double
Si usamos el modificador `long` con `double`, puede que éste se vuelva más preciso pero no es garantía. La especificación sólo pide que sea _"al menos tan preciso como un `double` normal"_.

### Librería de tipos de datos con tamaño garantizado
Existe una librería que nos permite acceder a tipos de datos en los que sí se nos garantiza el tamaño de cada uno. Esta librería se llama `stdint.h`, y nos permite acceder a los siguientes tipos de datos:

| Tipo de dato | Descripcion | Tamaño en bytes y (bits) |
|--------------|-------------|------------------------|
| int8_t       | Entero con signo de 8 bits | 1 (8) |
| int16_t      | Entero con signo de 16 bits | 2 (16) |
| int32_t      | Entero con signo de 32 bits | 4 (32) |
| int64_t      | Entero con signo de 64 bits | 8 (64) |
| uint8_t      | Entero sin signo de 8 bits | 1 (8) |
| uint16_t     | Entero sin signo de 16 bits | 2 (16) |
| uint32_t     | Entero sin signo de 32 bits | 4 (32) |
| uint64_t     | Entero sin signo de 64 bits | 8 (64) |

Ejemplo de uso:
```c
#include <stdio.h>
#include <stdint.h>

int main() {
    int8_t edad = 31;
    printf("La edad es: %d\n", edad);
    printf("El tamaño de edad es: %d bytes\n", sizeof(edad));
    return 0;
}
```

Además se definen otras cosas para el manejo de éstos, puedes ver todo en la [documentación oficial de IBM](https://www.ibm.com/docs/es/i/7.5?topic=files-stdinth).
