/**
 * \file            main.c
 * \brief           39. Imágenes - Ejemplo 4 - OpenCV - Reproducción de video desde webcam
 * \author          Javier Balloffet
 * \date            Aug 24, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

#define FPS         25
#define ESC_KEY     27

int main() {
    /* 1. Declaro dos descriptores para almacenar cada cuadro (frame) y uno para capturar al video */
	IplImage* frame_color = NULL;
    IplImage* frame_gray = NULL;
	CvCapture* video_capture = NULL;

    /* 2. Inicializo dispositivo de video (webcam) */	
	video_capture = cvCaptureFromCAM(-1);
    if (video_capture == NULL) {
        printf("Imposible iniciar captura desde camara!\n");
        exit(1);
    }

    /* 3. Creo un frame (imagen) del tamaño del frame original para almacenar el frame en escala de grises */
	frame_color = cvQueryFrame(video_capture);
    frame_gray = cvCreateImage(cvSize(frame_color->width, frame_color->height), frame_color->depth, 1);

	/* 4. Creo dos ventanas para mostrar el video en color y en escala de grises */
    cvNamedWindow("Color", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Color", 50, 100);
	cvNamedWindow("Escala de grises", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Escala de grises", 700, 100);

	/* 5. Muestro los cuadros a la velocidad de cuadros por segundo que corresponde */
    do {
        /* 6. Obtengo un nuevo cuadro */
        frame_color = cvQueryFrame(video_capture);
	    /* 7. Muestro el cuadro en la ventana */
	    cvShowImage("Color", frame_color);
	    /* 8. Convierto y copio el frame a escala de grises */
	    cvCvtColor(frame_color, frame_gray, CV_RGB2GRAY);
	    /* 9. Muestro el cuadro en la otra ventana */
	    cvShowImage("Escala de grises", frame_gray);
        /* 10. El bucle termina si se pulsa la tecla ESC o el frame obtenido no es válido */
    } while (((cvWaitKey((int)(1000/FPS)) & 0xFF) != ESC_KEY) && (frame_color != NULL));

    /* 11. Libero los recursos (memoria) */
    cvDestroyAllWindows();
    cvReleaseCapture(&video_capture);
	cvReleaseImage(&frame_gray);

    return 0;
}
