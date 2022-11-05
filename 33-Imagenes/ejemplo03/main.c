/*!
 * @file   main.c
 * @brief  31. Imágenes - 03. OpenCV - Reproducción de video (frame a frame)
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Aug 24, 2019
 */
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

#define ESC_KEY 27

int main(void)
{
    // Declaro un descriptor para almacenar cada cuadro (frame) y uno para
    // capturar al video.
    IplImage* frame = NULL;
    CvCapture* video_capture = NULL;
    double fps;

    // Abro archivo de video.
    video_capture = cvCreateFileCapture("sample.flv");
    if (video_capture == NULL)
    {
        printf("Imposible abrir archivo de video!\n");
        exit(1);
    }

    // Obtengo cantidad cuadros por segundo del video (frames per second), si es
    // 0 asigno 25.
    fps = cvGetCaptureProperty(video_capture, CV_CAP_PROP_FPS);
    if (fps == 0)
    {
        fps = 25;
    }
    printf("Cuadros por segundo: %f\n", fps);

    // Creo una ventana para mostrar el video.
    cvNamedWindow("Ejemplo", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Ejemplo", 100, 100);

    // Muestro los cuadros a la velocidad de cuadros por segundo que
    // corresponde.
    do
    {
        // Obtengo un nuevo cuadro.
        frame = cvQueryFrame(video_capture);
        // Muestro el cuadro en la ventana.
        cvShowImage("Ejemplo", frame);
        // El bucle termina si se pulsa la tecla ESC o termina el video.
    } while (((cvWaitKey((int)(1000 / fps)) & 0xFF) != ESC_KEY) &&
             (frame != NULL));

    // Libero los recursos (memoria).
    cvDestroyAllWindows();
    cvReleaseCapture(&video_capture);

    return 0;
}
