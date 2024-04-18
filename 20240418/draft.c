#include <stdio.h>
#include <string.h>

struct s_fecha
{
    short anio;
    int mes, dia;
};

typedef struct s_fecha Fecha;

typedef struct
{
    char titulo[101];
    Fecha fecha_del_evento;
} Evento;

struct plan
{
    int numero_eventos;
    struct {
        char nombre[100];
        Fecha dia_nacimiento;
    } organizador;
    Evento eventos[100];
};

int main()
{

    struct plan viaje_narnia = {
        3,
        {
            "Aslan",
            {
                1992, 12, 02
            }
        },
        {
            {
                "Entrar al armario",
                {
                    2024, 12, 25 
                }
            },
            {
                "Ir a la casa del fauno",
                {
                    2024, 12, 25 
                }
            },
            {
                "Visitar a la reina",
                {
                    2024, 12, 26
                }
            }
        }
    };

    printf("Primer cosa por hacer: %s\n", viaje_narnia.eventos[0].titulo);

    Fecha hoy = {2024, 04, 18};

    int x = 6;

    int a = x + 1;
    //  a = 6 + 1
    //  a = 7

    printf("hoy     es %d de %02d de %d\n", hoy.dia, hoy.mes, hoy.anio);
    printf("maniana es %d de %02d de %d\n", hoy.dia + 1, hoy.mes, hoy.anio);
    hoy.dia = hoy.dia + 2;
    printf("pasado maniana es %d de %02d de %d\n", hoy.dia, hoy.mes, hoy.anio);

    Evento clase = {
        "Clase de hoy",
        {2024,
         04, 18}};

    int no_existe = 3;
    int y = 4;

    double z = no_existe / y;

    // printf("%f\n", z);

    Evento clase_maninana;
    strcpy(clase_maninana.titulo, "Clase de manana");
    clase_maninana.fecha_del_evento.anio = 2024;
    clase_maninana.fecha_del_evento.mes = 04;
    clase_maninana.fecha_del_evento.dia = clase.fecha_del_evento.dia + 1;

    Evento clase_ayer;
    strcpy(clase_ayer.titulo, "Clase de ayer");
    clase_ayer.fecha_del_evento = (Fecha){2024, 04, 17};

    printf("Evento: %s sucedera el dia %d de %02d de %d\n", clase.titulo, clase.fecha_del_evento.dia, clase.fecha_del_evento.mes, clase.fecha_del_evento.anio);
    printf("Evento: %s sucedera el dia %d de %02d de %d\n", clase_maninana.titulo, clase_maninana.fecha_del_evento.dia, clase_maninana.fecha_del_evento.mes, clase_maninana.fecha_del_evento.anio);
    printf("Evento: %s sucedera el dia %d de %02d de %d\n", clase_ayer.titulo, clase_ayer.fecha_del_evento.dia, clase_ayer.fecha_del_evento.mes, clase_ayer.fecha_del_evento.anio);

    Fecha semana[7] = {
        {2024, 04, 18},
        {2024, 04, 19},
        {2024, 04, 20},
        {2024, 04, 21},
        {2024, 04, 22},
        {2024, 04, 23},
        {2024, 04, 24},
    };

    printf("\n");
    printf("semana[0] es %04d/%02d/%02d\n", semana[0].anio, semana[0].mes, semana[0].dia);

    Evento eventos[2];
    strcpy(eventos[0].titulo, "Club de Ajedrez");
    eventos[0].fecha_del_evento = (Fecha){2024, 05, 01};
    strcpy(eventos[1].titulo, "Vacaciones");
    eventos[1].fecha_del_evento = (Fecha){2024, 05, 12};

    printf("eventos:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("  %s %d/%d/%d\n", eventos[i].titulo, eventos[i].fecha_del_evento.anio, eventos[i].fecha_del_evento.mes, eventos[i].fecha_del_evento.dia);
    }
}