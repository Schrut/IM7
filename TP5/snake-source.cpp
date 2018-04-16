 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/core/core.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/legacy/legacy.hpp"
 #include <iostream>
 #include <cstdio>
 #include <vector>
 
 using namespace std;
 using namespace cv;
 
 typedef struct parameter Parameter;
 struct parameter {
     float alpha;
     float beta;
     float gamma;
     int length;
 };

 CvPoint *contour_snake; Parameter param_snake ;

 int es_alpha =XXX; // Weight of continuity energy
 int es_beta = XXX;  // Weight of curvature energy
 int es_gamma = XXX; // Weight of image energy
 int es_length = XXX;

int main(int argc, char** argv)
{
char* filename = argv[1];
IplImage* img_color = cvLoadImage(filename, 1);
IplImage *img_gray=cvCreateImage(cvGetSize(img_color),IPL_DEPTH_8U,1);
IplImage* img_bin = cvCreateImage(cvGetSize(img_gray),IPL_DEPTH_8U,1);

cvCvtColor(img_color,img_gray,CV_RGB2GRAY);
cvThreshold(img_gray, img_bin, 220, 255, CV_THRESH_BINARY  );

cvShowImage("Threshold", img_bin);

param_snake.alpha = (float)es_alpha/100.; 
param_snake.beta = (float)es_beta/100.;
param_snake.gamma = (float)es_gamma/100.; 
param_snake.length = es_length;

CvPoint center;
center.x = XXX ;
center.y = XXX ;
contour_snake = (CvPoint *) cvAlloc (sizeof (CvPoint) * param_snake.length);

for (int i = 0; i < param_snake.length; i++)
{
contour_snake[i].x = XXX;
contour_snake[i].y = XXX;
}

for (int i = 0; i < param_snake.length - 1; i++)
{
cvLine(img_color, contour_snake[i], contour_snake[i + 1],CV_RGB(255, 0, 0), 1, 8, 0);
cvCircle(img_color, contour_snake[i], 5,CV_RGB(255, 0, 0), 1, 8, 0);
}

cvLine (img_color, contour_snake[param_snake.length - 1], contour_snake[0], CV_RGB (255, 0, 0), 1, 8, 0);

cvSnakeImage (img_bin, contour_snake, param_snake.length, &param_snake.alpha, &param_snake.beta, &param_snake.gamma,CV_VALUE, cvSize(XXX, XXX), TermCriteria(CV_TERMCRIT_ITER, XXX,XXX), X);

for (int i = 0; i < param_snake.length - 1; i++)
{
cvLine(img_color, contour_snake[i], contour_snake[i + 1],CV_RGB(0, 255, 0), 1, 8, 0);
cvCircle(img_color, contour_snake[i], 5,CV_RGB(0, 255, 0), 1, 8, 0);
}
cvLine (img_color, contour_snake[param_snake.length - 1], contour_snake[0], CV_RGB (0, 255, 0), 1, 8, 0);
cvShowImage("Results", img_color);
waitKey(0);
return 0;
}
 

