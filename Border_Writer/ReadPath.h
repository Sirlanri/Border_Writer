#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <io.h>

#include "configs.h"
using namespace std;

//传入图像地址，返回所有的细边界信息，一共八条
int ReadFineBorder(string imgName, vector<vector<int>>& borders);

//传入图像名称，返回16粗边界数组
bool ReadRoughBorder16(string imgName, vector<int>& borders);

