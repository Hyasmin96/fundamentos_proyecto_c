#include <stdio.h>
#include <string.h>

#define USD_TO_GTQ 7.85
#define EUR_TO_GTQ 8.60
#define USD_TO_EUR 0.92
#define EUR_TO_USD 1.09

void convertirMoneda(int opcion, float cantidad) {
    float resultado;

    switch(opcion) {
        case 1:
            resultado = cantidad / USD_TO_GTQ;
            printf("\n%.2f Quetzales = %.2f Dólares\n", cantidad, resultado);
            break;
        case 2:
            resultado = cantidad / EUR_TO_GTQ;
            printf("\n%.2f Quetzales = %.2f Euros\n", cantidad, resultado);
            break;
        case 3:
            resultado = cantidad * USD_TO_GTQ;
            printf("\n%.2f Dólares = %.2f Quetzales\n", cantidad, resultado);
            break;
        case 4:
            resultado = cantidad * EUR_TO_GTQ;
            printf("\n%.2f Euros = %.2f Quetzales\n", cantidad, resultado);
            break;
        case 5:
            resultado = cantidad * EUR_TO_USD;
            printf("\n%.2f Euros = %.2f Dólares\n", cantidad, resultado);
            break;
        case 6:
            resultado = cantidad * USD_TO_EUR;
            printf("\n%.2f Dólares = %.2f Euros\n", cantidad, resultado);
            break;
        default:
            printf("\nOpción no válida, por favor intente de nuevo.\n");
    }
}

int main() {
    int opcion;
    float cantidad;
    char continuar[10];

    printf("======= Conversor de Moneda =======\n");

    do {
        // Mostrar menú
        do {
            printf("\n1. Quetzales a Dólares\n");
            printf("2. Quetzales a Euros\n");
            printf("3. Dólares a Quetzales\n");
            printf("4. Euros a Quetzales\n");
            printf("5. Euros a Dólares\n");
            printf("6. Dólares a Euros\n");
            printf("Seleccione una opción (1-6): ");
            
            if (scanf("%d", &opcion) != 1) {
                printf("\n❌ Entrada no válida. Por favor, ingrese un número entre 1 y 6.\n");
                while (getchar() != '\n'); // Limpiar el buffer
                opcion = -1; // Forzar el reinicio del bucle
            } else if (opcion < 1 || opcion > 6) {
                printf("\n❌ Opción inválida, por favor ingrese un número entre 1 y 6.\n");
            }
        } while (opcion < 1 || opcion > 6);  // Validar opción correcta

        // Ingresar y validar cantidad
        do {
            printf("Ingrese la cantidad a convertir (use punto como separador decimal): ");
            if (scanf("%f", &cantidad) != 1 || cantidad <= 0) {
                printf("\n❌ La cantidad debe ser un número mayor a cero. Intente de nuevo.\n");
                while (getchar() != '\n'); // Limpiar el buffer
                cantidad = -1; // Forzar el reinicio del bucle
            }
        } while (cantidad <= 0);

        // Realizar conversión
        convertirMoneda(opcion, cantidad);

        // Preguntar si desea continuar
        printf("\n¿Desea realizar otra conversión? (Si/No): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Si") == 0 || strcmp(continuar, "si") == 0);

    printf("\n¡Gracias por usar el conversor de moneda! 😊\n");
    return 0;
}


