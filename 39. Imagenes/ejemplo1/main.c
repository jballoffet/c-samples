/**
 * \file            main.c
 * \brief           39. Imágenes - Ejemplo 1 - OpenCV - Abrir imagen
 * \author          Javier Balloffet
 * \date            Aug 24, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <cv.h>
#include <highgui.h>

int main() {
	/* 1. Declaro descriptores para las imágenes */
    IplImage* img1 = NULL;
    IplImage* img2 = NULL;

    /* 2. Abro las imágenes en modo color y escala de grises */
    img1 = cvLoadImage("lena.png", CV_LOAD_IMAGE_COLOR);
    img2 = cvLoadImage("lena.png", CV_LOAD_IMAGE_GRAYSCALE);

    /* 3. Creo dos ventanas */
    cvNamedWindow("Ejemplo Color", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Ejemplo Grises", CV_WINDOW_AUTOSIZE);

    /* 4. Acomodo las ventanas */
    cvMoveWindow("Ejemplo Color", 100, 100);
    cvMoveWindow("Ejemplo Grises", 700, 100);

    /* 5. Muestro la imagen en la ventana */
    cvShowImage("Ejemplo Color", img1);
    cvShowImage("Ejemplo Grises", img2);

    /* 6. Espero la presión de alguna tecla (bloqueante) */
    cvWaitKey(0);

    /* 7. Libero los recursos (memoria) */
	cvDestroyAllWindows();
    cvReleaseImage(&img1);
    cvReleaseImage(&img2);

    return 0;
}
