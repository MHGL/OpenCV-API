/*************************************************************************
    > File Name: test02.cpp
    > Author: __MHGL__
    > Mail: 1545989994@qq.com 
    > Created Time: 2021年10月13日 星期三 22时29分06秒
 ************************************************************************/
# include <iostream>
# include <opencv2/opencv.hpp>


int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cerr << "usage: " << argv[0] << " <img-file>" << std::endl;
		return -1;
	}

	cv::Mat src_img = cv::imread(argv[1], 1);
	if(src_img.empty())
	{
		std::cerr << "Open img " << argv[1] << " failed !!!" << std::endl;
		return -1;
	}

	// print Mat info
	std::cout << "src img rows = " << src_img.rows << std::endl;
	std::cout << "src img cols = " << src_img.cols << std::endl;
	std::cout << "src img size = " << src_img.size() << std::endl;
	std::cout << "src img type = " << src_img.type() << std::endl;
	std::cout << "src img channels = " << src_img.channels() << std::endl;

	/*
	 * kernel
	 * [  0 -1  0 ]
	 * [ -1  5 -1 ]
	 * [  0 -1  0 ]
	 */
	int rows = src_img.rows;
	int c    = src_img.channels();
	int cols = src_img.cols * c;
	cv::Mat dst_img = cv::Mat::zeros(src_img.size(), src_img.type());

	for(int row = 1; row < rows - 1; ++row)
	{
		const uchar* prev = src_img.ptr(row - 1);
		const uchar* curr = src_img.ptr(row);
		const uchar* next = src_img.ptr(row + 1);
		uchar* w = dst_img.ptr(row);

		for(int col = c; col < cols - c; ++col)
		{
			w[col] = cv::saturate_cast<uchar>((5 * curr[col]) + (-1 * prev[col]) + (-1 * curr[col-c]) + (-1 * curr[col+c]) + (-1 * next[col]));
		}
	}

	cv::namedWindow("filter2D_test", cv::WINDOW_AUTOSIZE);
	cv::imshow("filter2D_test", dst_img);
	cv::waitKey(0);

	return 0;
}
