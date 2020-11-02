#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc == 0)
    {
        printf("Esto podría suceder, pero no es común porque existe una convención\n");
        printf("que sugiere que siempre se ejecute un programa con su nombre como\n");
        printf("primer argumento.\n");
        exit(-1);
    }

    if (argc == 1)
    {
        printf("Si no pasamos ningun argumento, de todas formas el sistema\n");
        printf("operativo le pasa al programa de forma automatica el nombre\n");
        printf("del archivo ejecutado como primer argumento.\n");
        printf("\n");
        printf("argv[0]: %s\n", argv[0]);
    }
    else if (argc == 2)
    {
        printf("Si solo pasamos un argumento, ahora lo que tendremos es:\n");
        printf(" - el default (nombre del programa)      en argv[0]\n");
        printf(" - cual sea que sea el argumento pasado, en argv[1]\n");
        printf("\n");
        printf("argv[0]: %s\n", argv[0]);
        printf("argv[1]: %s\n", argv[1]);
    }
    else if (argc == 3)
    {
        printf("Podemos pasarle dos argumentos, y entonces tendremos el nombre del programa\n");
        printf("en argv [0], el primer argumento en argv[1] y el segundo en argv[2] \n");
        printf("\n");
        printf("argv[0]: %s\n", argv[0]);
        printf("argv[1]: %s\n", argv[1]);
        printf("argv[2]: %s\n", argv[2]);
    }
    else
    {
        printf("Podemos pasarle cualquier cantidad de argumentos, y tendremos:\n");
        printf(" - el nombre del programa en argv[0]\n");
        printf(" - cada argumento pasado en las posiciones de [1] hasta [argc-1]\n");
        printf("\n");
        printf("En total tenemos %i argumentos\n", argc);
        printf("el nombre del programa, como siempre:\n");
        printf("  argv[0]: %s\n", argv[0]);
        printf("y %i dados por el usuario:\n", argc - 1);
        for (int i = 1; i < argc; i++)
        {
            printf("  argv[%i]: %s\n", i, argv[i]);
        }
    }

    return 0;
}
