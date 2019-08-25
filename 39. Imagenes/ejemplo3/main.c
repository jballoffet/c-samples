/**
 * \file            main.c
 * \brief           39. Imágenes - Ejemplo 3 - OpenCV - Reproducción de video (frame a frame)
 * \author          Javier Balloffet
 * \date            Aug 24, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

#define ESC_KEY 27

int main() {
    /* 1. Declaro un descriptor para almacenar cada cuadro (frame) y uno para capturar al video */
    IplImage* frame = NULL;
	CvCapture* video_capture = NULL;
	double fps;

    /* 2. Abro archivo de video */
	video_capture = cvCreateFileCapture("sample.flv");
	if (video_capture == NULL) {
        printf("Imposible abrir archivo de video!\n");
		exit(1);
	}

	/* 3. Obtengo cantidad cuadros por segundo del video (frames per second), si es 0 asigno 25 */
	fps = cvGetCaptureProperty(video_capture, CV_CAP_PROP_FPS);
    if (fps == 0) {
        fps = 25;
    }
	printf("Cuadros por segundo: %f\n", fps);

	/* 4. Creo una ventana para mostrar el video */
    cvNamedWindow("Ejemplo", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Ejemplo", 100, 100);

	/* 5. Muestro los cuadros a la velocidad de cuadros por segundo que corresponde */
    do {
        /* 6. Obtengo un nuevo cuadro */
        frame = cvQueryFrame(video_capture);
	    /* 7. Muestro el cuadro en la ventana */
        cvShowImage("Ejemplo", frame);
        /* 8. El bucle termina si se pulsa la tecla ESC o termina el video */
    } while (((cvWaitKey((int)(1000/fps)) & 0xFF) != ESC_KEY) && (frame != NULL));

    /* 9. Libero los recursos (memoria) */
   	cvDestroyAllWindows();
    cvReleaseCapture(&video_capture);

    return 0;
}
