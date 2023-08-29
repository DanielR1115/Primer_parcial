#include <stdio.h>

int main() {
    FILE *historial = fopen("historial.txt", "a");  

    if (historial == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char continuar;
    const float porcentajeIVA = 0.12;  

    do {
        float precio;
        
        printf("Ingrese el precio en quetzales: ");
        scanf("%f", &precio);

        float montoIVA = precio * porcentajeIVA;
        float precioSinIVA = precio - montoIVA;

        printf("Monto de IVA: %.2f quetzales\n", montoIVA);
        printf("Precio sin IVA: %.2f quetzales\n", precioSinIVA);

        fprintf(historial, "Precio: %.2f, IVA: %.2f, Sin IVA: %.2f\n", precio, montoIVA, precioSinIVA);

        printf("Desea calcular otro precio? (s/n): \n\n");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    fclose(historial);

    return 0;
}