/*************************************************************************
    > File Name: main.cpp
    > Author: __MHGL__
    > Mail: 1545989994@qq.com 
    > Created Time: 2021年10月14日 星期四 22时41分03秒
 ************************************************************************/
# include <iostream>
# include <opencv2/opencv.hpp>


int main(int argc, char** argv)
{
	// args
	if(argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <image-file> <image-file02>" << std::endl;
		return -1;
	}

	// cv img
	cv::Mat src_img_01 = cv::imread(argv[1], 1);
	if(src_img_01.empty())
	{
		std::cerr << "Open image " << argv[1] << " Failed !!!" << std::endl;
		return -1;
	}

	cv::Mat src_img_02 = cv::imread(argv[2], 1);
	if(src_img_02.empty())
	{
		std::cerr << "Open image " << argv[2] << " Failed !!!" << std::endl;
		return -1;
	}
	cv::resize(src_img_02, src_img_02, src_img_01.size());

	cv::Mat dst_img;
	// 对像素操作前必须对dst img实例化
	dst_img.create(src_img_01.size(), src_img_01.type());
	double alpha = 0.3, gamma = 0.0;

	/* addWeighted
	cv::addWeighted(src_img_01, alpha, src_img_02, 1 - alpha, gamma, dst_img);
	*/

	/* addWeighted src code
	int rows = src_img_01.rows;
	int c = src_img_01.channels();
	int cols = src_img_01.cols * c;

	for(int row = 0; row < rows; ++row)
	{
		const uchar* ptr_01 = src_img_01.ptr<uchar>(row);
		const uchar* ptr_02 = src_img_02.ptr<uchar>(row);
		uchar* ptr = dst_img.ptr(row);
		for(int col = 0; col < cols; ++col)
			ptr[col] = cv::saturate_cast<uchar>(alpha * ptr_01[col] + (1 - alpha) * ptr_02[col] + gamma);
	}
	*/

	// addWeighted src code
	int rows = src_img_01.rows;
	int cols = src_img_01.cols;
	for(int row = 0; row < rows; ++row)
	{
		for(int col = 0; col < cols; ++col)
		{
			int b_value_01 = src_img_01.at<cv::Vec3b>(row, col)[0];
			int g_value_01 = src_img_01.at<cv::Vec3b>(row, col)[1];
			int r_value_01 = src_img_01.at<cv::Vec3b>(row, col)[2];

			int b_value_02 = src_img_02.at<cv::Vec3b>(row, col)[0];
			int g_value_02 = src_img_02.at<cv::Vec3b>(row, col)[1];
			int r_value_02 = src_img_02.at<cv::Vec3b>(row, col)[2];

			dst_img.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(b_value_01 * alpha + b_value_02 * (1 - alpha) + gamma);
			dst_img.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(g_value_01 * alpha + g_value_02 * (1 - alpha) + gamma);
			dst_img.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(r_value_01 * alpha + r_value_02 * (1 - alpha) + gamma);
		}
	}
	
	// show
	cv::namedWindow("dst img", cv::WINDOW_AUTOSIZE);
	cv::imshow("dst_img", dst_img);
	cv::waitKey(0);

	return 0;
}

