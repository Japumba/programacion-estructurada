# Recursión
En términos simples: la recursión es cuando una función se llama a sí misma.

Es una forma de resolver problemas donde la solución depende de soluciones a instancias más pequeñas del mismo problema.

Existen cosas en el mundo que son inherentemente recursivas:
- Un árbol genealógico:
    - Un padre tiene hijos.
    - Cada hijo puede tener hijos.
    - Cada hijo puede tener hijos, etcétera.
- La estructura de archivos y carpetas de sus computadoras.
    - Una carpeta puede contener archivos y carpetas.
    - Cada carpeta puede contener archivos y carpetas.
    - Cada carpeta puede contener archivos y carpetas, etcétera.

## Factorial
El factorial de un numero natural N es el producto de todos los números enteros positivos menores o iguales a N.

Por ejemplo, el factorial de 5 es 5! = 5 * 4 * 3 * 2 * 1 = 120.
El factorial de 4 es 4! = 4 * 3 * 2 * 1 = 24.

### Caso Recursivo
Busquemos una definición recursiva para el factorial de un número N.

Si vemos de cerca ambos procedimientos:
```txt
5! = 5 * 4 * 3 * 2 * 1
4! =     4 * 3 * 2 * 1
3! =         3 * 2 * 1
2! =             2 * 1
1! =                 1
```

Podemos notar que el factorial de un número N es igual a N multiplicado por el factorial de N-1. Entonces, nuestro caso recursivo es:
```txt
factorial(N) = N * factorial(N-1)
```

### Caso Base
¿Cuándo nos detenemos?
Cuando N es igual a 1, el factorial de 1 es 1.

Implementa una función **RECURSIVA** que calcule el factorial de un número.

Toma [este código](exercises/factorial.c) como base.

## Raíz digital
La raíz digital de un número es la suma recursiva de todos los dígitos de un número.

Dado un número N, obtén la suma de los dígitos de N; si ese valor tiene más de un dígito, continúa reduciéndolo de esta manera hasta que obtengas un resultado de un solo dígito. Este resultado es la raíz digital de N.

Implementa una función **RECURSIVA** que calcule la raíz digital de un número.

Toma [este código](exercises/digital_root.c) como base.

Nota: Esto solo aplica para números naturales.

Algunos ejemplos del proceso:

```txt
digital_root(16)
=> 1 + 6
=> 7

digital_root(942)
=> 9 + 4 + 2
=> 15
=> 1 + 5
=> 6

digital_root(132189)
=> 1 + 3 + 2 + 1 + 8 + 9
=> 24
=> 2 + 4
=> 6

digital_root(493193)
=> 4 + 9 + 3 + 1 + 9 + 3
=> 29
=> 2 + 9
=> 11
=> 1 + 1
=> 2
```