// testOpencv.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include "highgui.h"
using namespace cv;

int main(int argc,char** argv) {
	// 读入一张图片（游戏原画）    
	//Mat img = imread("pic.jpg");
	// 创建一个名为 "游戏原画"窗口    
	//namedWindow("游戏原画");
	// 在窗口中显示游戏原画    
	//imshow("游戏原画", img);
	// 等待6000 ms后窗口自动关闭    
	//waitKey(6000);
	IplImage* img = cvLoadImage(argv[1]);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
}

