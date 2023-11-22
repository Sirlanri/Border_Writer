//存放参数等信息，只能被引用
#pragma once
#include "spdlog/spdlog.h"
#include "opencv2/opencv.hpp"
#include <string>

//Log日志
namespace llog = spdlog;

using namespace std;

//全局信息-图像路径
static string ImgPath = R"(E:\项目数据\轮胎\temp\)";

//绘制细边界的粗细
static int FineLineWidth = 5;

//绘制好的图像保存目录
static string SaveDir = R"(.\border_draw\)";

//颜色
static vector<cv::Scalar> Colors = {
	cv::Scalar(204,255,41),       
	cv::Scalar(0,255,0),        
	cv::Scalar(0,255,255),		
	cv::Scalar(128,0,128),     //紫色
	cv::Scalar(10,215,255), //金色
	cv::Scalar(238,130,238),     //紫罗兰
	cv::Scalar(255,94,116),
	cv::Scalar(218,254,59),
	cv::Scalar(150,157,244),
	cv::Scalar(252,82,79),
	cv::Scalar(112,252,79),

};