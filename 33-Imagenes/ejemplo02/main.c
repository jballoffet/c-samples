/*!
 * @file   main.c
 * @brief  31. Imágenes - 02. OpenCV - Negativo de una imagen (en escala de
 *   grises)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 24, 2019
 */
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(void)
{
    // Declaro una variable de tipo "CvScalar" para almacenar el valor de cada
    // píxel.
    int row, column;
    IplImage* img = NULL;
    CvScalar pixel;

    // Abro la imagen (en escala de grises) y la muestro en una ventana.
    img = cvLoadImage("lena.png", CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Original", 100, 100);
    cvShowImage("Original", img);

    // Recorro la imagen píxel a píxel.
    for (row = 0; row < (*img).height; row++)
    {
        for (column = 0; column < (*img).width; column++)
        {
            // Niego el valor de cada píxel (los valores posibles van de 0 a
            // 255).
            pixel = cvGet2D(img, row, column);
            pixel.val[0] = 255 - pixel.val[0];
            cvSet2D(img, row, column, pixel);
        }
    }

    // Muestro el negativo de la imagen en una ventana.
    cvNamedWindow("Negativo", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Negativo", 700, 100);
    cvShowImage("Negativo", img);

    // Espero la presión de alguna tecla (bloqueante).
    cvWaitKey(0);

    // Libero los recursos (memoria).
    cvDestroyAllWindows();
    cvReleaseImage(&img);

    return 0;
}
