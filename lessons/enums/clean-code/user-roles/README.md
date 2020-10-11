# Limpia el código
El código en `roles.c` funciona correctamente, pero tiene varios detalles que hacen que no sea claro.
Corrígelos y asegúrate que el código sigue funcionando luego de cambiarlo.

## Nombramiento
- Las variables no tienen nombres claros; cámbialos para que sea claro qué hace cada una.
- La función tiene un nombre inútil; cámbiale el nombre por uno que refleje lo que esa función hace.

## Enumeraciones
El significado de los valores del rol están documetados en un comentario, pero podrías cambiarlo para que estuvieran en una enumeración.

> _Usar enumeraciones para grupos de valores relacionas nos ayuda a hacer más entendible el código._

### Instrucciones
1. Crea una enumeración que haga claro y parte del código qué significa cada rol.
2. Modifica el código para que se utilice esta enumeración en lugar de numeros enteros constantes.
3. Ahora que tienes enumeraciones, modifica la implementación de la función, para que en lugar de ser una cadena de `if-else if`, sea una sentencia `switch`; esto hará más fácil leer la función.