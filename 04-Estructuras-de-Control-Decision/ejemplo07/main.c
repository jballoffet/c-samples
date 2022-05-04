/*!
 * @file   main.c
 * @brief  04. Estructuras de Control - Decisión - 07. Estructura 'switch-case'
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 7, 2018
 */
#include <stdio.h>

int main(void)
{
    int option;

    // Solicito una opción por consola.
    printf("Ingrese la opcion deseada:\n");
    printf("1) Opcion 1\n");
    printf("2) Opcion 2\n");
    scanf("%d", &option);

    // Informo por pantalla la opción elegida.
    switch (option)
    {
        case 1:
            printf("Usted eligio la opcion 1\n");
            break;

        case 2:
            printf("Usted eligio la opcion 2\n");
            break;

        default:
            printf("Usted eligio una opcion incorrecta\n");
            break;
    }

    return 0;
}
