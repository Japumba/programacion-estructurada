# Ejercicios
Hoy hemos visto varias cosas:
- Entrada de datos con scanf
- Operadores de asignación y aritméticos
- Operadores relacionales
- Operadores lógicos

## Calculadora de promedio de edad
Solicita al usuario la edad de tres personas y calcula el promedio de edad. Muestra el resultado, redondeando a un decimal.

Ejemplo:
```txt
Ingresa la edad de la primera persona: 20
Ingresa la edad de la segunda persona: 15
Ingresa la edad de la tercera persona: 18

Calculando...

El promedio de edad es: 17.7
```

## Tiempo estimado de llegada
Solicita al usuario su velocidad promedio en km/h y la distancia que recorrerá en km. Calcula y muestra el tiempo estimado de llegada en horas y minutos.

Ejemplo:
```txt
Velocidad actual (km/h): 130
Distancia a recorrer (km): 500

Calculando...

Tiempo estimado de llegada: 3 horas y 51 minutos
```

## Calculadora simple de gastos
Programa para decirle al usuario cuánto dinero le va a quedar luego de comprar una cantidad de artículos de cierto precio. Calcula el total de la compra y muestra el dinero restante.

Ejemplo:
```txt
¿Cuánto dinero traes?: $500
¿Cuánto cuesta lo que vas a comprar?: $12.5
¿Cuántos artículos vas a comprar?: 4

Calculando...

Total de la compra: $50
Luego de la compra te quedará: $450

¡Ahorra!
```

## Recomendaciones para salir
Pregunta al usuario algunas preguntas de si y no, y luego haz recomendaciones.

Preguntas:
- ¿Está lloviendo?
- ¿Tienes paraguas? sólo preguntar si está lloviendo

- ¿Está soleado? sólo preguntar si no está lloviendo

Luego, haz estas recomendaciones:
- Si está lloviendo y no tiene paraguas, recomienda ir a un lugar techado.
- Si está lloviendo y tiene paraguas, recomienda llevarlo.
- Si no está lloviendo y está soleado, recomienda usar bloqueador solar.
- Si no está lloviendo y no está soleado, recomienda llevar un suéter.

Ejemplo:
```txt
¿Está lloviendo? (s/n): s
¿Tienes paraguas? (s/n): n

Recomendación: Ve a un lugar techado.

// Otra ejecución:

¿Está lloviendo? (s/n): s
¿Tienes paraguas? (s/n): s

Recomendación: Lleva tu paraguas.

// Otra ejecución:

¿Está lloviendo? (s/n): n
¿Está soleado? (s/n): s

Recomendación: Usa bloqueador solar.

// Otra ejecución:

¿Está lloviendo? (s/n): n
¿Está soleado? (s/n): n

Recomendación: Lleva un suéter.
```