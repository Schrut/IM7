#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat image_Gray;
Mat image_Binary;

int threshold_Value = 0;
int max_Threshold_Value = 255;


const char* trackbar_value = "Value";

void image_With_Threshold (int, void*){
  threshold( image_Gray, image_Binary, threshold_Value, max_Threshold_Value, 0);

  imshow("Display Binary Image", image_Binary);
}


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

    cvtColor(image, image_Gray, cv::COLOR_BGR2GRAY);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    namedWindow("Display Gray Image", WINDOW_AUTOSIZE );
    imshow("Display Gray Image", image_Gray);

    namedWindow("Display Binary Image", WINDOW_AUTOSIZE );

    createTrackbar( trackbar_value, "Display Binary Image", &threshold_Value, max_Threshold_Value, image_With_Threshold );

    waitKey(0);
    imwrite( "image_Gray.jpg", image_Gray );
    imwrite( "image_Binary.jpg", image_Binary );


    while(1)
        waitKey(0);

    return 0;
}
