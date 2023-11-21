#include "ImageProcess.h"

bool GetImgs(vector<string>& ImgNames)
{
    //判断目录合法性
    bool isExist = filesystem::exists(ImgPath) && filesystem::is_directory(ImgPath);
    if (!isExist)
    {
        llog::error("图像文件夹路径错误");
        return false;
    }
    //文件句柄
    intptr_t hFile = 0;
    //文件信息，声明一个存储文件信息的结构体
    struct _finddata_t fileinfo;
    string p;//字符串，存放路径
    if ((hFile = _findfirst(p.assign(ImgPath).append("*.jpg").c_str(), &fileinfo)) != -1)//若查找成功，则进入
    {
        do
        {
            ImgNames.push_back(fileinfo.name);
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose函数结束查找
        _findclose(hFile);
    }
    if ((hFile = _findfirst(p.assign(ImgPath).append("*.bmp").c_str(), &fileinfo)) != -1)//若查找成功，则进入
    {
        do
        {
            ImgNames.push_back(fileinfo.name);
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose函数结束查找
        _findclose(hFile);
    }
    if ((hFile = _findfirst(p.assign(ImgPath).append("*.png").c_str(), &fileinfo)) != -1)//若查找成功，则进入
    {
        do
        {
            ImgNames.push_back(fileinfo.name);
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose函数结束查找
        _findclose(hFile);
    }

    //如果该目录没有图像，报错
    if (!ImgNames.size())
    {
        llog::error("当前路径图像为空: " + ImgPath);
        return false;
    }
    return true;
}