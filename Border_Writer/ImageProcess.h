#pragma once

#include <fstream>
#include <io.h>
#include <filesystem>

#include "opencv.hpp"
#include "configs.h"

using namespace std::filesystem;

//读取图像列表
bool GetImgs(vector<string>& ImgNames);