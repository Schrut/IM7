#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat image_binary;
Mat image_erode;
Mat image_dilate;
Mat image_open;
Mat image_close;

Mat my_erode (Mat image_in, Mat struct_element)
{

  int rows = image_in.rows;
  int cols = image_in.cols;
  int size_selement = struct_element.rows;
  int i, j, k, x, y;

  Mat image_out;
  image_out = image_in.clone();



  for (x = 2 ; x < rows-2 ; x++)
    for (y = 2 ; y < cols-2 ; y++)
    for (k = 2 ; k < 3 ; k++){

      image_in.at<Vec3b>(x,y)[k];

    }
}

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }


    Mat struct_element = getStructuringElement( MORPH_CROSS, Size(2*3+1,2*3+1), Point( 3, 3 ) );

    image = imread( argv[1], 1 );

    if ( !image.data )
    {
      printf("No image data \n");
      return -1;
    }

    cvtColor(image, image_binary, cv::COLOR_BGR2GRAY);

    threshold( image_binary, image_binary, 133, 255,0);

    my_erode (image_binary, struct_element);

    dilate( image, image_dilate, Mat());
    erode( image, image_erode, Mat());

    dilate( image_erode, image_open, Mat());
    erode( image_dilate, image_close, Mat());

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
