#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat binary_image;


Mat my_structuring_element;

int max_threshold_value = 255;

int is_inside(int posx, int posy, int cols, int rows){
  if (posx < 0 || posx > cols)
    return 0;
  if (posy < 0 || posx > rows)
    return 0;

  return 1;
}

Mat my_erode (Mat image_in)
{
  int x, y, i, j, vois, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;

  Mat image_out = image_in.clone();
  uchar min;

  for (y = 0 ; y < rows-1 ; y++)
    for (x = 0 ; x < cols-1 ; x++)
    {
      min = (uchar) 255;
      k = 0;
      for (j = -1 ; j <= 1 ; j++)
        for (i = -1 ; i <= 1 ; i++)
        {
          if (is_inside(y+i, x+j,cols,rows))
          {
          if (my_structuring_element.at<uchar>(k) == 1)
            if (image_in.at<uchar>(y+i ,x+j) < min )
              min = image_in.at<uchar>(y+i ,x+j);
          }
      k++;
      image_out.at<uchar>(y,x) = min;
        }
    }
    return image_out;
}

Mat my_dilate (Mat image_in)
{
  int x, y, i, j, vois, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;

  Mat image_out = image_in.clone();
  uchar max;

  for (y = 0 ; y < rows-1 ; y++)
    for (x = 0 ; x < cols-1 ; x++)
    {
      max = (uchar) 0;
      k = 0;
      for (j = -1 ; j <= 1 ; j++)
        for (i = -1 ; i <= 1 ; i++)
        {
          if (is_inside(y+i, x+j,cols,rows))
          {
          if (my_structuring_element.at<uchar>(k) == 1)
            if (image_in.at<uchar>(y+i ,x+j) > max )
              max = image_in.at<uchar>(y+i ,x+j);
          }
      k++;
      image_out.at<uchar>(y,x) = max;
        }
    }
    return image_out;
}

Mat my_open (Mat image_in)
{
  Mat image_out;
  image_out = my_erode(image_in);
  image_out = my_dilate(image_out);
  return image_out;
}

Mat my_close (Mat image_in)
{
  Mat image_out;
  image_out = my_dilate(image_in);
  image_out = my_erode(image_out);
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
  threshold( image, binary_image, 133, max_threshold_value, 0);


  my_structuring_element = getStructuringElement (MORPH_CROSS, Size(3,3) );

  Mat erode_image;
  Mat erode_gray_image;

  Mat dilate_image;
  Mat dilate_gray_image;

  Mat open_image;
  Mat open_gray_image;

  Mat close_image;
  Mat close_gray_image;

  erode_image = my_erode (binary_image);
  erode_gray_image = my_erode (image);

  dilate_image = my_dilate (binary_image);
  dilate_gray_image = my_dilate (image);

  open_image = my_open (binary_image);
  open_gray_image = my_open (image);

  close_image = my_close (binary_image);
  close_gray_image = my_close (image);



  namedWindow("Display my erode Image", WINDOW_AUTOSIZE );
  imshow("Display my erode Image", erode_image);
  namedWindow("Display my gray erode Image", WINDOW_AUTOSIZE );
  imshow("Display my gray erode Image", erode_gray_image);

  namedWindow("Display my dilate Image", WINDOW_AUTOSIZE );
  imshow("Display my dilate Image", dilate_image);
  namedWindow("Display my gray dilate Image", WINDOW_AUTOSIZE );
  imshow("Display my gray dilate Image", dilate_gray_image);


  namedWindow("Display my open Image", WINDOW_AUTOSIZE );
  imshow("Display my open Image", open_image);
  namedWindow("Display my gray open Image", WINDOW_AUTOSIZE );
  imshow("Display my gray open Image", open_gray_image);


  namedWindow("Display my close Image", WINDOW_AUTOSIZE );
  imshow("Display my close Image", close_image);
  namedWindow("Display my gray close Image", WINDOW_AUTOSIZE );
  imshow("Display my gray close Image", close_gray_image);

  printf("fin\n" );



  while(1)
      waitKey(0);
  return 0;
}
