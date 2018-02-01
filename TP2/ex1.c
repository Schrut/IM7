#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgcodecs/imgcodecs_c.h"

IplImage *my_erode(IplImage *image_in)
{
  int cols = image_in->width;
  int rows = image_in->height;
  //int size_selement = struct_element.rows;
  int i, j;// x, y;

  IplImage* image_out;
  image_out = image_in;

    for (i=0 ; i < rows ; i++);
        for (j=0 ; j < cols ; j++)
            if (image_in->imageData[(i * cols + j)] != 0)
                printf("valeur : %dl\n", image_in->imageData[(i * cols + j)]);

return image_out;
}

int main()
{

    IplImage* image = cvLoadImage("image.jpg",0);
    IplImage* image_binary = image;
    int* i;

    i = malloc (2*sizeof(int));
    i[0]=0;
    i[1]=1;


    //IplConvKernel* struct_element = cvCreateStructuringElementEx(3,3,-1,-1,0,i);

    cvThreshold(image, image_binary, 133, 255, 0);

    image = my_erode(image_binary);

    cvNamedWindow("Display Close Image", CV_WINDOW_AUTOSIZE );
    cvShowImage("Display Close Image", image);

    while(1)
        cvWaitKey(0);
    return 0;
}
