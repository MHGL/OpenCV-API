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

	// 亮度和对比度变化
	// f(x) = alpha * x + beta
	// alpha 对比度  beta 亮度
	cv::Mat dst_img;
	dst_img.create(src_img.size(), src_img.type());

	int rows = src_img.rows;
	int cols = src_img.cols;
	int c    = src_img.channels();
	float alpha = 1.5, beta = -5.0;

	/* ptr
	for(int row = 0; row < rows; row++)
	{
		const uchar* ptr = src_img.ptr(row);
		uchar* dptr = dst_img.ptr(row);
		for(int col = 0; col < cols * c; col++)
			dptr[col] = cv::saturate_cast<uchar>(ptr[col] * alpha + beta);
	}
	*/

	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < cols; col++)
		{
			for(int i = 0; i < c; i++)
			{
				dst_img.at<cv::Vec3b>(row, col)[i] = cv::saturate_cast<uchar>(src_img.at<cv::Vec3b>(row, col)[i] * alpha + beta);
			}
		}
	}

	cv::namedWindow("dst img", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst img", dst_img);
	cv::waitKey(0);

	return 0;
}
