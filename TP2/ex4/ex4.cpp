#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat image_gradient;
Mat binary_image;
Mat image_tophat;
Mat open_img;

Mat my_structuring_element;

int is_inside(int posx, int posy, int cols, int rows)
{
  if (posx < 0 || posx > cols)
    return 0;
  if (posy < 0 || posy > rows)
    return 0;

  return 1;
}

Mat my_erode(Mat image_in)
{
  int x, y, i, j, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  /*int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;*/

  Mat image_out = image_in.clone();
  uchar min;

  for (y = 0; y < rows - 1; y++)
    for (x = 0; x < cols - 1; x++)
    {
      min = (uchar)255;
      k = 0;
      for (j = -1; j <= 1; j++)
        for (i = -1; i <= 1; i++)
        {
          if (is_inside(y + i, x + j, cols, rows))
          {
            if (my_structuring_element.at<uchar>(k) == 1)
              if (image_in.at<uchar>(y + i, x + j) < min)
                min = image_in.at<uchar>(y + i, x + j);
          }
          k++;
          image_out.at<uchar>(y, x) = min;
        }
    }
  return image_out;
}

Mat my_dilate(Mat image_in)
{
  int x, y, i, j, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  /*int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;*/

  Mat image_out = image_in.clone();
  uchar max;

  for (y = 0; y < rows - 1; y++)
    for (x = 0; x < cols - 1; x++)
    {
      max = (uchar)0;
      k = 0;
      for (j = -1; j <= 1; j++)
        for (i = -1; i <= 1; i++)
        {
          if (is_inside(y + i, x + j, cols, rows))
          {
            if (my_structuring_element.at<uchar>(k) == 1)
              if (image_in.at<uchar>(y + i, x + j) > max)
                max = image_in.at<uchar>(y + i, x + j);
          }
          k++;
          image_out.at<uchar>(y, x) = max;
        }
    }
  return image_out;
}

Mat my_open(Mat image_in)
{
  Mat image_out;
  image_out = my_erode(image_in);
  image_out = my_dilate(image_out);
  return image_out;
}

int main(int argc, char** argv )
{
  if ( argc != 2 )
  {
      printf("usage: DisplayImage.out <Image_Path>\n");
      return -1;
  }
  image = imread( argv[1], 0 );

  if ( !image.data )
  {
    printf("No image data \n");
    return -1;
  }
  
	my_structuring_element = getStructuringElement ( MORPH_RECT, Size(3,3) );



  morphologyEx(image, open_img, cv::MORPH_OPEN, my_structuring_element);
  morphologyEx(open_img, image_gradient, cv::MORPH_GRADIENT, my_structuring_element);
  morphologyEx(image_gradient, image_tophat, cv::MORPH_TOPHAT, my_structuring_element);

  namedWindow("Gradient", WINDOW_AUTOSIZE);
  namedWindow("TopHat", WINDOW_AUTOSIZE);

  imshow("Gradient", image_gradient);
  imshow("TopHat", image_tophat);


  while(1)
      waitKey(0);
  return 0;
}
