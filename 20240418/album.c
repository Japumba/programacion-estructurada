#include <stdio.h>
#include <string.h>

typedef struct
{
    char inicial_titulo;
    char titulo[201];
    char nombre_artista[51];
    short int anio;
    unsigned char num_canciones;
    float total_minutos;
} Album;

void imprimir_album(Album);

int main()
{
    Album album_1;
    album_1.inicial_titulo = 'Z';
    strcpy(album_1.titulo, "Zeit");
    strcpy(album_1.nombre_artista, "Rammstein");
    album_1.anio = 2022;
    album_1.num_canciones = 11;
    album_1.total_minutos = 44.17;

    Album album_2;
    album_2.inicial_titulo = 'T';
    strcpy(album_2.titulo, "The Number of the Beast");
    strcpy(album_2.nombre_artista, "Iron Maiden");
    album_2.anio = 1982;
    album_2.num_canciones = 8;
    album_2.total_minutos = 40.37;

    Album album_3 = {
        'F',
        "Future Nostalgia",
        "Dua Lipa",
        2020,
        11,
        37.38};

    imprimir_album(album_1);
    imprimir_album(album_2);
    imprimir_album(album_3);
}

void imprimir_album(Album a)
{
    printf("== 📀 %s ==\n", a.titulo);
    printf("   🎤 %s\n", a.nombre_artista);
    printf("   🗓️  %d\n", a.anio);
    printf("   🎵 %d canciones\n", a.num_canciones);
    printf("   ⏳ %.2f minutos\n", a.total_minutos);
    printf("\n");
}