#pragma once

#include <fstream>
#include <io.h>
#include <filesystem>

#include "opencv.hpp"
#include "configs.h"

using namespace std::filesystem;

//读取图像列表
bool GetImgs(vector<string>& ImgNames);

//在图像上绘制细边界。
bool DrawFineBorders(cv::Mat& img, const vector<vector<int>>& borders);

//读取图像
bool ReadImg(string imgName, cv::Mat& img);

//保存绘制后的图像
bool SaveImg(const cv::Mat& img, string imgName);