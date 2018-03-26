#include <stdio.h>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


Mat image;
Mat canny_image;

RNG rng(12345);

int main(int argc, char** argv )
{
  vector<vector<Point> > contours;
  if (argc != 2)
  {
      printf("usage: DisplayImage.out <Image_Path>\n");
      return -1;
  }
  image = imread( argv[1], IMREAD_GRAYSCALE );

  if ( !image.data )
  {
    printf("No image data \n");
    return -1;
  }

  Canny(image, canny_image,100, 150, 3);

  findContours(canny_image, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

/*  Mat drawing = Mat::zeros(canny_image.size(), CV_8UC3);
  for (int i = 0; i < contours.size(); i++)
  {
    Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
    drawContours(drawing, contours, i, color);
  }*/

  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly(contours.size());
  vector<Rect> boundRect(contours.size());
  vector<Point2f> center(contours.size());
  vector<float> radius(contours.size());

  for (int i = 0; i < contours.size(); i++)
  {
    approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
    boundRect[i] = boundingRect(Mat(contours_poly[i]));
  }

  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros(canny_image.size(), CV_8UC3);
  for (int i = 0; i < contours.size(); i++)
  {
    Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
    drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
    rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color);
  }

  namedWindow("Display Image", WINDOW_AUTOSIZE);
  imshow("Display Image", drawing);
  printf("fin\n");

  while(1)
      waitKey(0);
  return 0;
}
