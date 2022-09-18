/*!
 * @file   main.c
 * @brief  19. Uniones - 04. Distintos tipos
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Sep 16, 2022
 */
#include <stdio.h>

typedef union Number
{
    char x;
    int y;
    double z;
} Number;

int main(void)
{
    // Declaro una variable de tipo "Number".
    Number number;

    // Asigno 10 al campo X.
    number.x = 10;
    printf("Campo X: %d\n", number.x);
    printf("Campo Y: %d\n", number.y);
    printf("Campo Z: %lf\n", number.z);

    // Asigno 10 al campo Y.
    number.y = 10;
    printf("Campo X: %d\n", number.x);
    printf("Campo Y: %d\n", number.y);
    printf("Campo Z: %lf\n", number.z);

    // Asigno 10.0 al campo Z.
    number.z = 10.0;
    printf("Campo X: %d\n", number.x);
    printf("Campo Y: %d\n", number.y);
    printf("Campo Z: %lf\n", number.z);

    return 0;
}
