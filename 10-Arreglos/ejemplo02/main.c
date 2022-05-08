/*!
 * @file   main.c
 * @brief  10. Arreglos - 02. Inicialización de arreglos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro un arreglo (array) de enteros (int) de 5 elementos e inicializo
    // el arreglo.
    int array[5] = {3, 24, 12, 5, 76};

    // Imprimo el contenido del arreglo.
    printf("Valor de array[0] = %d\n", array[0]);
    printf("Valor de array[1] = %d\n", array[1]);
    printf("Valor de array[2] = %d\n", array[2]);
    printf("Valor de array[3] = %d\n", array[3]);
    printf("Valor de array[4] = %d\n", array[4]);

    // Imprimo el tamaño del arreglo (en bytes).
    printf("Tamanio del arreglo (en bytes) = %ld\n", sizeof(array));

    // Imprimo el tamaño del arreglo (en cantidad de elementos).
    printf("Tamanio del arreglo (en cantidad de elementos) = %ld\n",
           sizeof(array) / sizeof(int));

    return 0;
}
