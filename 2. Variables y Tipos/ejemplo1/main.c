/**
 * \file            main.c
 * \brief           2. Variables y Tipos - Ejemplo 1
 * \author          Javier Balloffet
 * \date            07-SEP-2018
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    // 1. Declaro las variables
    int miVariableEntera;
    float miVariableReal;
    char miVariableCaracter;
	
    // 2. Asigno las variables
    miVariableEntera = 5;
    miVariableReal = 3.1415;
    miVariableCaracter = 'J';
    
    // 3. Imprimo el contenido de las variables en pantalla
    printf("miVariableEntera vale %d\n", miVariableEntera);
    printf("miVariableReal vale %f\n", miVariableReal);
    printf("miVariableCaracter vale %c\n", miVariableCaracter);

    // 4. ¿Si quiero mostrar solo dos decimales de mi variable real?
    printf("miVariableReal vale %.2f\n", miVariableReal);

    // 5. ¿Y si imprimo un char como entero? Me muestra el codigo ASCII correspondiente!
    printf("miVariableCaracter vale %d\n", miVariableCaracter);

    // 6. ¿Cuanto puedo almacenar en cada tipo de variable?
    printf("Una variable entera (int) tiene %ld bytes de largo\n", sizeof(int));
    printf("Una variable real (float) tiene %ld bytes de largo\n", sizeof(float));
    printf("Una variable caracter (char) tiene %ld bytes de largo\n", sizeof(char));

	return 0;
}
