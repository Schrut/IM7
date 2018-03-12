#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;


int C1[9] = { 1, 1, 1, -1, 1, -1, 0, 0, 0 };
int C2[9] = { 0, 0, 0, -1, 1, -1, 1, 1, 1 };
int C3[9] = { 1, -1, 0, 1, 1, 0, 1, -1, 0 };
int C4[9] = { 0, -1, 1, 0, 1, 1, 0, -1, 1 };
int C5[9] = { -1, 1, -1, 1, 1, 0, -1, 0,0 };
int C6[9] = { -1, 1, -1, 0, 1, 1, 0, 0, -1};
int C7[9] = { 0, 0, -1, 0, 1, 1, -1, 1, -1};
int C8[9] = { -1, 0, 0, 1, 1, 0, -1, 1, -1};

int *Cn[8]= {C1, C2, C3, C4, C5, C6, C7, C8};

int is_inside(int posx, int posy, int cols, int rows){
  if (posx < 0 || posx > cols)
    return 0;
  if (posy < 0 || posx > rows)
    return 0;

  return 1;
}

Mat diff_sym (Mat image_a, Mat image_b)
{
  Mat image_out;
  Mat image_first;
  Mat image_scd;
  image_out= Mat(image_a.cols, image_a.rows, image_a.type());
	image_first = Mat(image_a.cols, image_a.rows, image_a.type());
	image_scd = Mat(image_a.cols, image_a.rows, image_a.type());

	for (int i = 0; i < image_a.rows; i++)
  {
		for (int j = 0; j < image_a.cols; j++)
		{
    //Union
    if (image_a.at<uchar>(i,j) == 255 || image_b.at<uchar>(i,j) == 255 )
			image_first.at<uchar>(i, j) = 255;
		else
			image_first.at<uchar>(i, j) = 0;
		}
  }
	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			//Intersection
			if ((image_a.at<uchar>(i,j) == 255 && image_b.at<uchar>(i,j) == 255 ))
				image_scd.at<uchar>(i, j) = 255;
			else
				image_scd.at<uchar>(i, j) = 0;
		}
	}


	for (int i = 0; i < image_a.rows; i++)
	{
		for (int j = 0; j < image_a.cols; j++)
		{
			image_out.at<uchar>(i, j) = image_first.at<uchar>(i, j) - image_scd.at<uchar>(i, j);
		}
	}


	

		return image_out;
}

Mat toutouRien (Mat image_in, int **Cn_)
{

	int k;
	int is_true;


	Mat image_out;
	image_out = image_in.clone();
	for (int i = 0; i < image_in.cols * image_in.rows ; i++)
		image_out.at<uchar>(i) = 0;

	for (int x = 0; x < image_in.rows; x++)
	{
		for (int y = 0; y < image_in.cols; y++)
		{
			for (int n_c = 0; n_c < 8; n_c++)
			{
				k = 0;
				is_true = 1;
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{

						if (is_inside(x + i, y + j, image_in.cols, image_in.rows))
						{
							if (Cn[n_c][k] != -1)
							{
								if ( (Cn[n_c][k] == 1 && image_in.at<uchar>(x + i, y + j) == 0 )|| (Cn[n_c][k] == 0 && image_in.at<uchar>(x + i, y + j) != 0))
								{
									is_true = 0;
									break;
								}
							}
						}
						k++;
					}
				}
				if (is_true)
					image_out.at<uchar>(x,y) = 255;
				else
					is_true = 1;
      }
		}
	}
			image_out = diff_sym(image_in, image_out);
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
  
	Mat image1 = image.clone();
for (int i = 0 ; i < 20 ; i++)
	image = toutouRien(image, Cn);

	//image1 = diff_sym(image1, image);

	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	printf("fin\n");

  while(1)
      waitKey(0);
  return 0;
}
