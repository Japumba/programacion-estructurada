# Overflow
Sabemos que los tipos de datos tienen un tamaño fijo, y entonces pueden solamente contener valores dentro de cierto rango. Por ejemplo, un `unsigned char` tiene 1 byte y puede contener valores entre 0 y 255. Si intentamos asignarle un valor fuera de ese rango, se produce un **overflow**, o desbordamiento.

Podemos ver qué pasa si asignamos un valor fuera de rango a un `unsigned char`, o con operaciones llegamos a eso:

```c
#include <stdio.h>

int main() {
    unsigned char c = 0;
    /*
    Imaginemos el cajón de memoria en que se guarda el valor 0. Contiene los siguientes 8 bits:
    [ 0 0 0 0 0 0 0 0 ]
    */
    printf("empezamos con c = %d\n", c);

    c = 255;
    /*
    Ahora imaginemos que le asignamos el valor 255, el máximo para unsigned int.
    Contiene entonces los siguientes 8 bits:
    [ 1 1 1 1 1 1 1 1 ]
    */
    printf("le asignamos 255, tenemos c = %d\n", c);

    c = 256;
    /*
    Ahora imaginemos que le asignamos el valor 256, uno más que el máximo para unsigned int.
    Los bits que se necesitan para representar 256 son 9:
    [ 1 0 0 0 0 0 0 0 0 ] pero unsigned char solo tiene 8 bits, entonces se pierde el bit más significativo.

    Observa si los empalmamos, alineando hasta la derecha, se pierde el bit más significativo:
    
    valor 256, 9 bits necesarios:    [ 1 0 0 0 0 0 0 0 0 ]
    variable c, 8 bits disponibles:    [ 0 0 0 0 0 0 0 0 ]

    ¡Se piede el 1 porque literalmente no cabe en el cajón!
    Nos quedamos con todos los 0s
    */
    printf("Ahora le asignamos 256, y tenemos c = %d\n", c);

    c = 257;
    /*
    Ahora imaginemos que le asignamos el valor 257, dos más que el máximo para unsigned int.
    Los bits que se necesitan para representar 257 son 9, pero nota que tenemos un 1 hasta la derecha.
    [ 1 0 0 0 0 0 0 0 1 ]

    Al empalmar, se pierde el bit más significativo y nos quedamos con los 8 bits menos significativos:
    valor 257, 9 bits necesarios:    [ 1 0 0 0 0 0 0 0 1 ]
    variable c, 8 bits disponibles:    [ 0 0 0 0 0 0 0 1 ]
    */
    printf("Y asignarle un 257 nos deja con c = %d\n", c);

    /*
    Tendremos un efecto similar si le sumamos por encima de su límite, "saltando" al valor más bajo.
    */
    c = 255;
    printf("Volvemos al máximo 255, con c = %d\n", c);
    c = c + 1;
    printf("le sumamos uno y nos queda c = %d\n", c);

    /*
    También si le restamos al mínimo, "saltando" al valor más alto.
    */
    c = 0;
    printf("Volvemos ahora al mínimo, 0, y tenemos c = %d\n", c);
    c = c - 1;
    printf("Si le restamos uno, tenemos c = %d\n", c);
    printf("no se va a negativos porque es unsigned char\n");

    return 0;
}
```