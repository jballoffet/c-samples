/*!
 * @file   main.c
 * @brief  31. Imágenes - 05. OpenCV - Dibujo de figuras geométricas
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 24, 2019
 */
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

#define WAIT_TIME_MS 200
#define ESC_KEY 27

int main(void)
{
    // Creo una imagen de 640x480 pixeles donde se dibujarán las figuras
    // geométricas.
    int point1_x, point1_y, point2_x, point2_y, rgb_red, rgb_green, rgb_blue,
        diameter, figure_type;
    IplImage* img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);

    // Creo una ventana.
    cvNamedWindow("Figuras geometricas", CV_WINDOW_AUTOSIZE);

    // Dibujo figuras geométricas aleatorias hasta que se presione la tecla ESC.
    do
    {
        // Obtengo el tipo de figura geométrica de forma aleatoria.
        figure_type = 1 + (int)(3.0 * rand() / (RAND_MAX + 1.0));
        // Obtengo la posición de la figura de forma aleatoria.
        point1_x = (int)(639.0 * rand() / (RAND_MAX + 1.0));
        point1_y = (int)(479.0 * rand() / (RAND_MAX + 1.0));
        // Obtengo el color de la figura de forma aleatoria.
        rgb_red = (int)(255.0 * rand() / (RAND_MAX + 1.0));
        rgb_green = (int)(255.0 * rand() / (RAND_MAX + 1.0));
        rgb_blue = (int)(255.0 * rand() / (RAND_MAX + 1.0));

        // Dibujo la figura en la imagen.
        switch (figure_type)
        {
            case 1:
                // Obtengo el diámetro del círculo de forma aleatoria.
                diameter = 1 + (int)(100.0 * rand() / (RAND_MAX + 1.0));
                cvCircle(img, cvPoint(point1_x, point1_y), diameter,
                         cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            case 2:
                // Obtengo el segundo punto de la línea de forma aleatoria.
                point2_x = (int)(639.0 * rand() / (RAND_MAX + 1.0));
                point2_y = (int)(479.0 * rand() / (RAND_MAX + 1.0));
                cvLine(img, cvPoint(point1_x, point1_y),
                       cvPoint(point2_x, point2_y),
                       cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            case 3:
                // Obtengo el punto opuesto del rectángulo de forma aleatoria.
                point2_x = (int)(639.0 * rand() / (RAND_MAX + 1.0));
                point2_y = (int)(479.0 * rand() / (RAND_MAX + 1.0));
                cvRectangle(img, cvPoint(point1_x, point1_y),
                            cvPoint(point2_x, point2_y),
                            cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            default:
                break;
        }

        // Muestro la imagen en la ventana.
        cvShowImage("Figuras geometricas", img);
        // El bucle termina si se pulsa la tecla ESC.
    } while ((cvWaitKey(WAIT_TIME_MS) & 0xFF) != ESC_KEY);

    // Libero los recursos (memoria).
    cvReleaseImage(&img);

    return 0;
}
