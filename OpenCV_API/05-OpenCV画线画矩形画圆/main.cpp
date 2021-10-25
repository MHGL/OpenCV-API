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
	if(argc != 2)
	{
		std::cerr << "Usage: ./opencv <img-file>" << std::endl;
		return -1;
	}

	std::string img_file = argv[1];
	cv::Mat src_img = cv::imread(img_file, 1);
	if(src_img.empty())
	{
		std::cerr << "Open img: " << img_file << " failed !!!" << std::endl;
		return -1;
	}

	cv::Point p1(0, 0), p2(300, 300);
	cv::Scalar color(255, 0, 0);
	int radius = 100, thickness = 2, line_type = 4;

	cv::Mat dst_img = src_img.clone();

	// 画线
	cv::line(dst_img, p1, p2, color, thickness, line_type);

	// 画矩形
	cv::rectangle(dst_img, p1, p2, color, thickness, line_type);

	// 画圆
	cv::circle(dst_img, p2, radius, color, thickness, line_type);

	// 画椭圆
	// ellipse(img, center, axes, angle, startAngle, endAngle, color[, thickness[, lineType[, shift]]])
	cv::ellipse(dst_img, p2, cv::Size(100, 20), 0, 0, 360, color, thickness, line_type);
	

	cv::namedWindow("dst img", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst img", dst_img);
	cv::waitKey(0);

	return 0;
}
