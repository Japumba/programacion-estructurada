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
=> 15 ...
=> 1 + 5
=> 6

digital_root(132189)
=> 1 + 3 + 2 + 1 + 8 + 9
=> 24 ...
=> 2 + 4
=> 6

digital_root(493193)
=> 4 + 9 + 3 + 1 + 9 + 3
=> 29 ...
=> 2 + 9
=> 11 ...
=> 1 + 1
=> 2
```