/*!
 * @file   main.c
 * @brief  12. Arreglos Multidimensionales - 09. Arreglos de N dimensiones
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    // Declaro un arreglo multidimensional (3D array) de enteros (int) de 2x3x4
    // elementos.
    int array3D[2][3][4];
    int i, j, k;

    // Cargo el arreglo.
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", &array3D[i][j][k]);
            }
        }
    }

    // Imprimo el contenido del arreglo.
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("Valor de array3D[%d][%d][%d] = %d\n", i, j, k,
                       array3D[i][j][k]);
            }
        }
    }

    return 0;
}
