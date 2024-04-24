// operaciones.h

// Primero, usaremos la instruccion del preprocesador #ifndef (if not defined) para revisar si un símbolo específico no ha sido definido.
// Esto nos permite evitar que el archivo de cabecera se incluya más de una vez en un archivo fuente, lo que causaría un error.
// encuentra el #endif al final del archivo, y observa cómo sólo se incluirá una vez.
#ifndef OPERACIONES_H

// Aqui se define el símbolo. No tiene un valor específico, sólo nos interesa saber si existe.
#define OPERACIONES_H

// 1) Prototipo de las funciones, solamente las firmas

/**
 * Recibe dos enteros y devuelve su suma.
 */
int sumar(int a, int b);

/**
 * Recibe dos enteros y devuelve la resta del primero menos el segundo.
 */
int restar(int a, int b);

#endif