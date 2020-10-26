#include <stdio.h>
#include <assert.h>

/**
 * INSTRUCCIONES:
 * 1. Declara un string que pueda contener al menos 13 caracteres e inicialízalo
 *    con el texto "Hello, World" con un enter al final.
 */

int main()
{
    // Declara aquí el string.
    

    assert(str_hello[0] == 'H');
    assert(str_hello[1] == 'e');
    assert(str_hello[2] == 'l');
    assert(str_hello[3] == 'l');
    assert(str_hello[4] == 'o');
    assert(str_hello[5] == ',');
    assert(str_hello[6] == ' ');
    assert(str_hello[7] == 87);
    assert(str_hello[8] == 111);
    assert(str_hello[9] == 114);
    assert(str_hello[10] == 108);
    assert(str_hello[11] == 100);
    assert(str_hello[12] == 10);
    assert(str_hello[13] == '\0');

    printf("%s", str_hello);

    printf("OK! Funcion implementada correctamente\n");
    return 0;
}