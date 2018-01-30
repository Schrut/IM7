#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include "opencv2/imgproc/imgproc_c.h"




/*Mat my_erode (Mat image_in, Mat struct_element)
{
  using std::cout;
  using std::endl;

  int rows = image_in.rows;
  int cols = image_in.cols;
  int size_selement = struct_element.rows;
  int i, j, x, y;

  Mat image_out;
  image_out = image_in.clone();



  for (x = 2 ; x < rows ; x++)
    for (y = 2 ; y < cols ; y++){

          image_out.at<int>(x,y) = 255;

    }
}*/

int main(int argc, char** argv )
{

    IplImage *image = cvLoadImage("image.jpg");
    /*if ( argc != 2 )
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
    imshow("Display Open Image", image_open);*/

    cvNamedWindow("Display Close Image", CV_WINDOW_AUTOSIZE );
    cvShowImage("Display Close Image", image);


    while(1)
        cvwaitKey(0);


    return 0;
}
