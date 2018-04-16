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

  int histSize = 256;
  float range[] = {0, 256};
  const float *histRange = {range};

  bool uniform = true;
  bool accumulate = false;

  Mat im_hist;

  calcHist(&image, 1, 0, Mat(), im_hist, 1, &histSize, &histRange, uniform, accumulate);

  kmeans(Z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS);

  // Draw the histograms for B, G and R
  int hist_w = 512;
  int hist_h = 400;
  int bin_w = cvRound((double)hist_w / histSize);

  Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

  // Normalize the result to [ 0, histImage.rows ]
  normalize(im_hist, im_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

  // Draw for each channel
  for (int i = 1; i < histSize; i++)
  {
    line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(im_hist.at<float>(i - 1))),
         Point(bin_w * (i), hist_h - cvRound(im_hist.at<float>(i))),
         Scalar(50, 100, 200), 2, 8, 0);
  }

  namedWindow("Display Image", WINDOW_AUTOSIZE);
  imshow("Display Image", histImage);
  printf("fin\n");

  while (1)
    waitKey(0);
  return 0;
}
