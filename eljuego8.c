#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
 
    srand(time(NULL));

    int num1, num2, suma;

    do {
        // Generar dos dados lanzados
        num1 = rand() % 6 + 1;
        num2 = rand() % 6 + 1;

        // suma de las caras
        suma = num1 + num2;

        printf("dado 1: %d\n", num1);
        printf("dado 2: %d\n", num2);
        printf("suma: %d\n", suma);

        if (suma == 8) {
            printf("Ganaste\n");
        } else if (suma == 7) {
            printf("Perdiste\n");
        } else {
            printf("Vuelve a intentarlo.\n");
        }

    } while (suma != 7 && suma != 8);

    return 0;
}