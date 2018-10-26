/**
 * \file            main.c
 * \brief           2. Variables y Tipos - Ejemplo 2
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Puedo declarar varias variables en una misma linea y asignarles un valor   
          en el mismo momento de la declaracion */
    int miVariableEntera1, miVariableEntera2;
    char miVariableCaracter;
    float miVariableReal = 3.14;

    // 2. Le paso los valores de las variables por consola
    printf("Ingrese el valor a almacenar en miVariableCaracter\n");
    scanf("%c", &miVariableCaracter);
    printf("Ingrese el valor a almacenar en miVariableEntera1\n");
    scanf("%d", &miVariableEntera1);
    printf("Ingrese el valor a almacenar en miVariableEntera2\n");
    scanf("%d", &miVariableEntera2);
    printf("Ingrese el valor a almacenar en miVariableReal\n");
    scanf("%f", &miVariableReal);

    // 3. Imprimo el contenido de las variables en pantalla
    printf("miVariableCaracter vale %c\n", miVariableCaracter);
    printf("miVariableEntera1 vale %d\n", miVariableEntera1);
    printf("miVariableEntera2 vale %d\n", miVariableEntera2);
    printf("miVariableReal vale %f\n", miVariableReal);

	return 0;
}
