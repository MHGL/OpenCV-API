/*************************************************************************
    > File Name: test01.cpp
    > Author: __MHGL__
    > Mail: 1545989994@qq.com 
    > Created Time: 2021年10月12日 星期二 22时45分03秒
 ************************************************************************/
# include <iostream>
# include <string>
# include <opencv2/opencv.hpp>


int main(int argc, char** argv)
{
	cv::Mat cv_img;
	// In the case of color images, the decoded images will have the channels stored in B G R order
	cv_img = cv::imread(argv[1]);
	if(cv_img.empty())
	{
		std::cerr << "Open img: " << argv[1] << " failed!!!" << std::endl;
		return -1;
	}

	std::string out_filename = "result.jpg";
	cv::imwrite(out_filename, cv_img);

	cv::Mat gray_img, hls_img;
	cv::cvtColor(cv_img, gray_img, cv::COLOR_BGR2GRAY);
	std::string out_gray_filename = "result_gray.jpg";
	cv::imwrite(out_gray_filename, gray_img);

	cv::cvtColor(cv_img, hls_img, cv::COLOR_BGR2HLS);
	std::string out_hls_filename = "result_hls.jpg";
	cv::imwrite(out_hls_filename, hls_img);

	return 0;
}


