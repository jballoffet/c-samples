/*!
 * @file   main.c
 * @brief  31. Imágenes - 04. OpenCV - Reproducción de video desde webcam
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 24, 2019
 */
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

#define FPS 25
#define ESC_KEY 27

int main(void)
{
    // Declaro dos descriptores para almacenar cada cuadro (frame) y uno para
    // capturar al video.
    IplImage* frame_color = NULL;
    IplImage* frame_gray = NULL;
    CvCapture* video_capture = NULL;

    // Inicializo dispositivo de video (webcam).
    video_capture = cvCaptureFromCAM(-1);
    if (video_capture == NULL)
    {
        printf("Imposible iniciar captura desde camara!\n");
        exit(1);
    }

    // Creo un frame (imagen) del tamaño del frame original para almacenar el
    // frame en escala de grises.
    frame_color = cvQueryFrame(video_capture);
    frame_gray = cvCreateImage(cvSize(frame_color->width, frame_color->height),
                               frame_color->depth, 1);

    // Creo dos ventanas para mostrar el video en color y en escala de grises.
    cvNamedWindow("Color", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Color", 50, 100);
    cvNamedWindow("Escala de grises", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Escala de grises", 700, 100);

    // Muestro los cuadros a la velocidad de cuadros por segundo que
    // corresponde.
    do
    {
        // Obtengo un nuevo cuadro.
        frame_color = cvQueryFrame(video_capture);
        // Muestro el cuadro en la ventana.
        cvShowImage("Color", frame_color);
        // Convierto y copio el frame a escala de grises.
        cvCvtColor(frame_color, frame_gray, CV_RGB2GRAY);
        // Muestro el cuadro en la otra ventana.
        cvShowImage("Escala de grises", frame_gray);
        // El bucle termina si se pulsa la tecla ESC o el frame obtenido no es
        // válido.
    } while (((cvWaitKey((int)(1000 / FPS)) & 0xFF) != ESC_KEY) &&
             (frame_color != NULL));

    // Libero los recursos (memoria).
    cvDestroyAllWindows();
    cvReleaseCapture(&video_capture);
    cvReleaseImage(&frame_gray);

    return 0;
}
