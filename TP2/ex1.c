#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgcodecs/imgcodecs_c.h"



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

int main()
{

    IplImage* image = cvLoadImage("image.jpg",0);
    IplImage* image_binary = image;

    //IplConvKernel* struct_element = cvCreateStructuringElementEx(3,3,-1,-1,1);

    cvThreshold(image, image_binary, 133, 255, 0);

    /*my_erode (image_binary, struct_element);*/

    cvNamedWindow("Display Close Image", CV_WINDOW_AUTOSIZE );
    cvShowImage("Display Close Image", image_binary);

    while(1)
        cvWaitKey(0);
    return 0;
}
