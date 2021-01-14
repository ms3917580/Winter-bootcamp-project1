#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat rotate(Mat img, double angle)
{
	Mat img1;
	Point2f pt(img.cols / 2., img.rows / 2.);
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	warpAffine(img, img1, r, Size(img.cols, img.rows));
	return img1;
}
int main()
{
	Mat img = imread("Image.jpg");
	if (img.empty())
	{
		cout << "error !!! no image...";
		return -1;
	}
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Original image", img);
	Mat img1;
	img1 = rotate(img, 90);
	imshow("Rotated image", img1);
	waitKey();
	destroyWindow("Image");
	return 0;
}