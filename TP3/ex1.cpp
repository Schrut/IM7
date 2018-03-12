#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;


Mat image;
Mat binary_image;
Mat map;


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
  int x, y, i, j, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  /*int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;*/

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
  int x, y, i, j, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

  /*int struct_cols = my_structuring_element.cols;
  int struct_rows = my_structuring_element.rows;*/

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

int max (int a, int b)
{
	if (a > b)
		return a;
	else 
		return b;
}

int min (int a, int b)
{
	if (a > b)
		return b;
	else 
		return a;
}

int labelling(Mat image_in, Mat map)
{
	int cols = image_in.cols;
	int rows = image_in.rows;
	int nb_label=0;
	int max_, min_;
	int i, x, y, l, t;

	
	int* label = new int[5];
	for (i=0 ; i < 5 ; i++)
		label[i] = i*50 + 25;

	for (x = 0 ; x < rows ; x++)
		for (y = 0; y < cols; y++)
		{
			l = 0;
			t = 0;
			if (image_in.at<uchar>(x, y) != 0)
			{
				if (y - 1 >= 0) l = map.at<uchar>(x, y - 1);
				if (x - 1 >= 0) t = map.at<uchar>(x - 1, y);

				if (l == 0 && t == 0)
				{
					map.at<uchar>(x, y) = label[nb_label];
					nb_label++;
				}
        else 
        {
          if (l == 0 && t > 0)
            map.at<uchar>(x, y) = t;
          else 
          if (l > 0 && t == 0)
            map.at<uchar>(x, y) = l;
          else
          if (l == t )
            map.at<uchar>(x, y) = l;
          else
          {
            min_ = min(l,t);
            max_ = max(l,t);
            map.at<uchar>(x, y) = min_;
            nb_label --;
            for (i = 0 ; i < (x*cols+y) ; i++)
              {
                if (map.at<uchar>(i) == max_)
                  map.at<uchar>(i) = min_;
              }
          }
        }
        }
		}
	delete []label;
	return nb_label;
}

/* IT IS NOT WORKING */
Mat conditional_dilate(Mat image_in, Mat map, Mat my_structuring_element)
{
  int x, y, i, j, k;
  int cols = image_in.cols;
  int rows = image_in.rows;

	Mat image_out = image_in.clone();
  uchar max;
	for (i = 0; i < rows * cols; i++)
		map.at<uchar>(i) = 0;

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
							if (image_in.at<uchar>(y + i, x + j) > max && map.at<uchar>(y + i, x + j) == 255 )
								max = image_in.at<uchar>(y + i, x + j);
          }
          k++;
        }
        if (map.at<uchar>(x,y) == 255 && max > 0)
        {
          image_out.at<uchar>(y, x) = max; 
          map.at<uchar>(x,y) = 0;
        }
    }
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

  Mat erode_image;
  int i;
	
  erode_image = my_erode (image);
  /*for(i = 0 ; i < 28 ; i++)
    erode_image = my_erode (erode_image);
  for(i = 0 ; i < 29 ; i++)
    map = my_dilate (map);*/

	erode_image = image.clone();
  map = erode_image.clone();

  int nbforme = 0;
	int nberode = 0;

	while (nbforme != 3)
	{
		for (i = 0; i < map.rows * map.cols; i++)
				map.at<uchar>(i) = 0;
		erode_image = my_erode(erode_image);
		nberode++;
    map = erode_image.clone();
    nbforme = labelling(erode_image, map);
	}


  for (i=0; i < nberode; i++)
		map = conditional_dilate(map, image, my_structuring_element);

  namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", map);
	printf("fin %d\n", nbforme);

  while(1)
      waitKey(0);
  return 0;
}
