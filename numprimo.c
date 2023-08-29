#include <stdio.h>

int esPrimo(int numero) {
    if (numero <= 1) {
        return 0;  //menores o iguales a 1 no son primos
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    FILE *registro = fopen("registronumeros.txt", "a");

    if (registro == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char continuar;

    do {
        int numero;
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if (esPrimo(numero)) {
            printf("%d es un numero primo.\n", numero);
            fprintf(registro, "Primo: %d\n", numero);
        } else {
            printf("%d es un numero compuesto.\n", numero);
            fprintf(registro, "Compuesto: %d\n", numero);
        }

        printf("Desea verificar otro numero? (s/n): \n\n");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    fclose(registro);

    return 0;
}