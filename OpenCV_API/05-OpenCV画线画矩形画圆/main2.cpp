/*************************************************************************
    > File Name: main.cpp
    > Author: __MHGL__
    > Mail: 1545989994@qq.com 
    > Created Time: 2021年10月25日 星期一 22时03分50秒
 ************************************************************************/
# include <iostream>
# include <string>
# include <opencv2/opencv.hpp>


int main(int argc, char** argv)
{
	cv::Mat dst_img(300, 300, CV_8UC3);

	cv::RNG rng;

	cv::namedWindow("dst img", cv::WINDOW_AUTOSIZE);

	for(int i = 0; i < 1000; i++)
	{
		cv::Point p1(rng.uniform(0, 300), rng.uniform(0, 300));
		cv::Point p2(rng.uniform(0, 300), rng.uniform(0, 300));
		cv::Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		cv::line(dst_img, p1, p2, color, 2, 8);
		cv::imshow("dst img", dst_img);
	}

	cv::waitKey(0);

	return 0;
}
