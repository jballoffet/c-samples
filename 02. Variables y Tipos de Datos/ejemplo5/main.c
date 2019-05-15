/**
 * \file            main.c
 * \brief           02. Variables y Tipos de Datos - Ejemplo 5 - Código ASCII
 * \author          Javier Balloffet
 * \date            Sep 7, 2018
 * \details         Ver README para compilar, linkear y ejecutar
 */

#include <stdio.h>

int main() {
    /* 1. Declaro una variable char y le asigno el valor A */
    char myCharacterVariable = 'A';

    /* 2. Imprimo el contenido de la variable en pantalla */
    printf("El contenido de myCharacterVariable es %c\n", myCharacterVariable);

    /* 3. ¿Y si imprimo un char como un entero? Me muestra el codigo ASCII correspondiente! */
    printf("El contenido de myCharacterVariable es %d\n", myCharacterVariable);

	return 0;
}
