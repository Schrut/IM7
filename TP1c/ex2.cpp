#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat image_erode;
Mat image_dilate;
Mat image_open;
Mat image_close;


int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }



    image = imread( argv[1], 1 );

    if ( !image.data )
    {
      printf("No image data \n");
      return -1;
    }

    dilate( image, image_dilate, Mat(), Point(-1, -1), 1 );
    erode( image, image_erode, Mat(), Point(-1, -1), 1 );

    dilate( image_erode, image_open, Mat(), Point(-1, -1), 1 );
    erode( image_dilate, image_close, Mat(), Point(-1, -1), 1 );

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    namedWindow("Display Dilate Image", WINDOW_AUTOSIZE );
    imshow("Display Dilate Image", image_dilate);

    namedWindow("Display Erode Image", WINDOW_AUTOSIZE );
    imshow("Display Erode Image", image_erode);

    namedWindow("Display Open Image", WINDOW_AUTOSIZE );
    imshow("Display Open Image", image_open);

    namedWindow("Display Close Image", WINDOW_AUTOSIZE );
    imshow("Display Close Image", image_close);


    while(1)
        waitKey(0);

    return 0;
}
