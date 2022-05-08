/*!
 * @file   main.c
 * @brief  10. Arreglos - 04. Escritura y lectura de arreglos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro un arreglo (array) de enteros (int) de 5 elementos.
    int array[5];
    int i;

    // Cargo el arreglo.
    for (i = 0; i < 5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &array[i]);
    }

    // Imprimo el contenido del arreglo.
    for (i = 0; i < 5; i++)
    {
        printf("Valor de array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
