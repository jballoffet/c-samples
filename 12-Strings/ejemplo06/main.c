/*!
 * @file   main.c
 * @brief  12. Strings - 06. Uso de strcmp()
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Mar 6, 2019
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declaro dos strings sin inicializar.
    char word1[20];
    char word2[20];
    int diff;

    // Ingreso el contenido de los strings por consola.
    printf("Ingrese una palabra: ");
    scanf("%s", word1);
    printf("Ingrese otra palabra: ");
    scanf("%s", word2);

    // Imprimo el contenido de los strings.
    printf("Primera palabra ingresada: %s\n", word1);
    printf("Segunda palabra ingresada: %s\n", word2);

    // Comparo ambos strings (lexicográficamente).
    diff = strcmp(word1, word2);

    // Imprimo el resultado de la comparación.
    if (diff == 0)
    {
        printf("Los strings ingresados son iguales\n");
    }
    else
    {
        printf(
            "Los strings ingresados son distintos: el primer caracter "
            "diferente difiere por un valor (en codigo "
            "ascii en decimal) de: %d\n",
            diff);
    }

    return 0;
}
