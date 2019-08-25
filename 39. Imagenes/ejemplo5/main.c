/**
 * \file            main.c
 * \brief           39. Imágenes - Ejemplo 5 - OpenCV - Dibujo de figuras geométricas
 * \author          Javier Balloffet
 * \date            Aug 24, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

#define WAIT_TIME_MS    200
#define ESC_KEY         27

int main() {
    /* 1. Creo una imagen de 640x480 pixeles donde se dibujarán las figuras geométricas */
    int point1_x, point1_y, point2_x, point2_y, rgb_red, rgb_green, rgb_blue, diameter, figure_type;
    IplImage* img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);

    /* 2. Creo una ventana */
    cvNamedWindow("Figuras geometricas", CV_WINDOW_AUTOSIZE);

	/* 3. Dibujo figuras geométricas aleatorias hasta que se presione la tecla ESC */
    do {
	    /* 4. Obtengo el tipo de figura geométrica de forma aleatoria */
        figure_type = 1 + (int)(3.0*rand()/(RAND_MAX+1.0));
	    /* 5. Obtengo la posición de la figura de forma aleatoria */
        point1_x = (int)(639.0*rand()/(RAND_MAX+1.0));
        point1_y = (int)(479.0*rand()/(RAND_MAX+1.0));
	    /* 6. Obtengo el color de la figura de forma aleatoria */
        rgb_red = (int)(255.0*rand()/(RAND_MAX+1.0));
        rgb_green = (int)(255.0*rand()/(RAND_MAX+1.0));
        rgb_blue = (int)(255.0*rand()/(RAND_MAX+1.0));

	    /* 7. Dibujo la figura en la imagen */
        switch (figure_type) {
            case 1:
	            /* 8. Obtengo el diámetro del círculo de forma aleatoria */
                diameter = 1 + (int)(100.0*rand()/(RAND_MAX+1.0));
                cvCircle(img, cvPoint(point1_x, point1_y), diameter, cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            case 2:
	            /* 9. Obtengo el segundo punto de la línea de forma aleatoria */
                point2_x = (int)(639.0*rand()/(RAND_MAX+1.0));
                point2_y = (int)(479.0*rand()/(RAND_MAX+1.0));
                cvLine(img, cvPoint(point1_x, point1_y), cvPoint(point2_x, point2_y), cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            case 3:
	            /* 10. Obtengo el punto opuesto del rectángulo de forma aleatoria */
                point2_x = (int)(639.0*rand()/(RAND_MAX+1.0));
                point2_y = (int)(479.0*rand()/(RAND_MAX+1.0));
                cvRectangle(img, cvPoint(point1_x, point1_y), cvPoint(point2_x, point2_y), cvScalar(rgb_red, rgb_green, rgb_blue, 1), 1, 8, 0);
                break;

            default:
                break;
        }

	    /* 11. Muestro la imagen en la ventana */
        cvShowImage("Figuras geometricas", img); 
        /* 12. El bucle termina si se pulsa la tecla ESC */
    } while ((cvWaitKey(WAIT_TIME_MS) & 0xFF) != ESC_KEY);

    /* 13. Libero los recursos (memoria) */
	cvReleaseImage(&img);

    return 0;
}
