/*!
 * @file   main.c
 * @brief  10. Arreglos - 06. Alocación en memoria de un arreglo
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro un arreglo (array) de caracteres (char) de 5 elementos.
    char array[5];
    int i;

    // Imprimo las direcciones de memoria de cada elemento del arreglo.
    for (i = 0; i < 5; i++)
    {
        printf("Direccion de array[%d] = %p\n", i, &array[i]);
    }

    // Imprimo el contenido de "array".
    printf("Contenido de array = %p\n", array);

    return 0;
}
