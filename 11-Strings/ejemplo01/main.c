/*!
 * @file   main.c
 * @brief  11. Strings - 01. Declaración de strings
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 5, 2019
 */
#include <stdio.h>

int main(void)
{
    int i;

    // Declaro un string (array de caracteres) de varias maneras
    // diferentes.
    char name1[5] = "Juan";
    char name2[] = "Juan";
    char name3[5] = {'J', 'u', 'a', 'n', '\0'};
    char name4[] = {'J', 'u', 'a', 'n', '\0'};

    // Imprimo el contenido de los strings.
    printf("Valor de name1 = %s\n", name1);
    printf("Valor de name2 = %s\n", name2);
    printf("Valor de name3 = %s\n", name3);
    printf("Valor de name4 = %s\n", name4);

    // Imprimo el tamaño de los strings (en bytes).
    printf("Tamanio de name1 = %ld\n", sizeof(name1));
    printf("Tamanio de name2 = %ld\n", sizeof(name2));
    printf("Tamanio de name3 = %ld\n", sizeof(name3));
    printf("Tamanio de name4 = %ld\n", sizeof(name4));

    // Imprimo el tamaño de los strings (en cantidad de caracteres).
    printf("Tamanio de name1 (en cantidad de caracteres) = %ld\n",
           sizeof(name1) / sizeof(char));
    printf("Tamanio de name2 (en cantidad de caracteres) = %ld\n",
           sizeof(name2) / sizeof(char));
    printf("Tamanio de name3 (en cantidad de caracteres) = %ld\n",
           sizeof(name3) / sizeof(char));
    printf("Tamanio de name4 (en cantidad de caracteres) = %ld\n",
           sizeof(name4) / sizeof(char));

    // Imprimo un string caracter a caracter.
    for (i = 0; i < 5; i++)
    {
        printf("Contenido de name1[%d] = %c\n", i, name1[i]);
        printf("Contenido de name1[%d] (codigo ascii en decimal) = %d\n", i,
               name1[i]);
    }

    return 0;
}
