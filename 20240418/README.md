# Lista de Albumes
Modifica tu ejercicio de albumes de la clase pasada:

## Tipos de datos y funciones
- Agrega una **estructura anidada anónima** al Album que contenga un `nombre` (de hasta 50 caracteres + nulo) y un `anio_nacimiento` del artista.
    - Borra el campo anterior `nombre_artista`.
- Declara un nuevo tipo de dato estructura `Cancion`, que contenga un `titulo` (de hasta 50 caracteres + nulo) y una `duracion_minutos`, flotante de precision simple.
- Modifica tu estructura `Album` para que contenga una lista de Canciones `canciones` de hasta `30` elementos.
    - Mantenemos el campo `numero_canciones`, que nos dirá cuantos elementos del arreglo realmente contienen canciones.
- Remueve el campo `total_minutos`.
    - En su lugar, implementa una funcion `float total_minutos(Album a)` que calcule recibe un album y calcule la duración total del album.
- Implementa una funcion `Cancion crear_cancion(const char titulo[51], float duracion_minutos)` que reciba los datos de una cancion y devuelva una estructura `Cancion` con esos datos.

## Main
De la clase pasada tienes 3 albumes en total: a dos de ellos les asignaste valores con el punto (`strcpy(album1.titulo, "The Number of the Beast")`) y al tercero le asignaste valor inicial con la sintaxis parecida al arreglo (`Album album3 = { ... }`)

- Modifica los albumes que creaste para que correctamente tengan al artista, con sus campos.
- Para los dos albumes que creaste con el punto:
    - A uno de ellos, asigna con el punto los valores de cada cancion, usando tu funcion crear_cancion.
    - Al otro, usando tambien el punto, asigna los valores de las canciones, pero usando sintaxis similar al arreglo para la cancion y conversion explícita (`(Cancion){"Invaders", 3.20};`)
- Para el tercer album, asigna los valores de las canciones con la sintaxis de arreglo.


### Ejemplo de ejecucion
```
== 📀 Zeit ==
   🗓️  2022
   🎤 Rammstein
   🎤🎂 1994
   🎵 11 canciones (44.57 minutos):
      1. Armee der Tristen (3.12)
      2. Zeit (5.37)
      3. Schwarz (3.51)
      4. Giftig (4.19)
      5. Zick Zack (3.05)
      6. OK (4.25)
      7. Meine Traennen (4.00)
      8. Angst (3.59)
      9. Dicke Titten (4.00)
     10. Lugen (4.00)
     11. Adieu (5.49)

== 📀 The Number of the Beast ==
   🗓️  1982
   🎤 Iron Maiden
   🎤🎂 1975
   🎵 8 canciones (38.54 minutos):
      1. Invaders (3.20)
      2. Children of the Damned (4.35)
      3. The Prisoner (6.00)
      4. 22 Acacia Avenue (6.34)
      5. The Number of the Beast (4.50)
      6. Run to the Hills (3.54)
      7. Gangland (3.49)
      8. Hallowed Be Thy Name (7.12)

== 📀 Future Nostalgia ==
   🗓️  2020
   🎤 Dua Lipa
   🎤🎂 1995
   🎵 11 canciones (35.58 minutos):
      1. Future Nostalgia (3.04)
      2. Don't Start Now (3.03)
      3. Cool (3.29)
      4. Physical (3.13)
      5. Levitating (3.23)
      6. Pretty Please (3.14)
      7. Hallucinate (3.28)
      8. Love Again (4.18)
      9. Break My Heart (3.42)
     10. Good in Bed (3.38)
     11. Boys Will Be Boys (2.46)
```