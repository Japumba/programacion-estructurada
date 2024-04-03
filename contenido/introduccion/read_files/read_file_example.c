#include <stdio.h>
#include <string.h>

int MAX_LINES = 1000;
int LINE_MAX_SIZE = 1000;

int main()
{
    FILE *file = fopen("sample_file.txt", "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return -1;
    }

    char lines[MAX_LINES][LINE_MAX_SIZE];
    char line[LINE_MAX_SIZE];
    int line_count = 0;

    while (fgets(line, LINE_MAX_SIZE, file) != NULL)
    {
        if (line_count == MAX_LINES)
        {
            printf("Se excedió la cantidad máxima de líneas\n");
            break;
        }

        strcpy(lines[line_count], line);
        line_count++;
    }

    fclose(file);

    printf("Lineas del archivo: \n");
    for (int i = 0; i < line_count; i++)
    {
        printf("%s", lines[i]);
    }

    return 0;
}