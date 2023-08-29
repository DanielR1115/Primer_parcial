#include <stdio.h>
#include <stdlib.h>

struct Estudiante {
    char nombre[50];
    float matematicas;
    float fisica;
    float lenguaje;
    float contabilidad;
    float promedio;
};

// Función para calcular el promedio de un estudiante
void calcularPromedio(struct Estudiante *estudiante) {
    estudiante->promedio = (estudiante->matematicas + estudiante->fisica + estudiante->lenguaje + estudiante->contabilidad) / 4.0;
}

int main() {
    FILE *notasArchivo = fopen("notas.txt", "a+");

    if (notasArchivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int opcion;
    struct Estudiante estudiante;

    do {
        // Mostrar menú
        printf("\nMenu:\n");
        printf("1. Registrar nuevo estudiante y sus notas\n");
        printf("2. Ver el historial de notas\n");
        printf("3. Borrar historial de notas\n");
        printf("4. Cerrar programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Registrar nuevo estudiante y sus notas
                printf("Ingrese el nombre del estudiante: ");
                scanf("%s", estudiante.nombre);
                printf("Ingrese la nota de Matematicas: ");
                scanf("%f", &estudiante.matematicas);
                printf("Ingrese la nota de Fisica: ");
                scanf("%f", &estudiante.fisica);
                printf("Ingrese la nota de Lenguaje: ");
                scanf("%f", &estudiante.lenguaje);
                printf("Ingrese la nota de Contabilidad: ");
                scanf("%f", &estudiante.contabilidad);

                calcularPromedio(&estudiante);
                
                fprintf(notasArchivo, "Nombre: %s, Matematicas: %.2f, Fisica: %.2f, Lenguaje: %.2f, Contabilidad: %.2f, Promedio: %.2f\n",
                        estudiante.nombre, estudiante.matematicas, estudiante.fisica, estudiante.lenguaje, estudiante.contabilidad, estudiante.promedio);

                printf("Estudiante registrado con exito.\n");
                break;
            
            case 2:
                // Ver el historial de notas
                printf("\nHistorial de Notas:\n");
                rewind(notasArchivo);
                char linea[200];
                while (fgets(linea, sizeof(linea), notasArchivo) != NULL) {
                    printf("%s", linea);
                }
                break;

            case 3:
                // Borrar historial de notas
                fclose(notasArchivo);
                notasArchivo = fopen("notas.txt", "w");
                if (notasArchivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    return 1;
                }
                printf("Historial de notas borrado.\n");
                break;

            case 4:
                printf("Cerrando el programa.\n");
                fclose(notasArchivo);
                break;

            default:
                printf("Opcion invalida.\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}