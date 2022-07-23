/*!
 * @file   main.c
 * @brief  11. Strings - 09. Pasaje de un string a una función
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Jun 14, 2022
 */
#include <stdio.h>

void print_string(char* string_pointer);

int main(void)
{
    char string[] = "Foobarbaz";

    // Paso el string (puntero) a la función "print_string" para imprimir el
    // mismo caracter a caracter. En los strings no necesito pasar la longitud
    // ya que el caracter null indica la finalización del mismo.
    print_string(string);

    return 0;
}

void print_string(char* string_pointer)
{
    int i = 0;

    // Recorro el string usando el puntero recibido hasta encontrar el caracter
    // null.
    printf("[");
    while (*(string_pointer + i) != '\0')
    {
        printf("'%c', ", *(string_pointer + i));
        i++;
    }
    printf("'\\0']\n");
}
