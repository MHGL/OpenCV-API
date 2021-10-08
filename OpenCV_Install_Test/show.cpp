/*************************************************************************
    > File Name: show.cpp
    > Author: __MHGL__
    > Mail: 1545989994@qq.com 
    > Created Time: 2021年10月08日 星期五 22时59分17秒
 ************************************************************************/
# include <iostream>
# include <opencv2/opencv.hpp>


int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "usage: " << argv[0] << " <image-path>" << std::endl;
		return -1;
	}

	cv::Mat cv_img = cv::imread(argv[1], 1);
	
	if(cv_img.empty())
	{
		std::cout << "open img " << argv[1] << " failed!!!" << std::endl;
		return -1;
	}

	cv::namedWindow("opencv_install_test", cv::WINDOW_AUTOSIZE);
	cv::imshow("opencv_install_test", cv_img);
	cv::waitKey(0);

	return 0;
}
