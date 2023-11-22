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

bool DrawFineBorders(cv::Mat& img,  const vector<vector<int>>& borders)
{
    //颜色计数
    size_t colorCount = 0;

    //循环处理12条边界
    for (int b = 0; b < borders.size(); b++)
    {
        for (int r = 0; r < img.rows; r++)
        {
            //逐row扫描 绘制
            try
            {
                //根据粗细，多绘制几列
                for (int i = 0; i < FineLineWidth; i++)
                {
                    //判断边界溢出
                    if (borders[b][r] + i>=img.cols)
                    {
                        break;
                    }
                    img.at<cv::Vec3b>(r, borders[b][r]+i)[0] = uchar(Colors.at(colorCount % Colors.size()).val[0]);
                    img.at<cv::Vec3b>(r, borders[b][r]+i)[1] = uchar(Colors.at(colorCount % Colors.size()).val[1]);
                    img.at<cv::Vec3b>(r, borders[b][r]+i)[2] = uchar(Colors.at(colorCount % Colors.size()).val[2]);
                }

                
            }
            catch (const std::exception& e)
            {
                llog::warn("DrawFineBorders- 逐row扫描绘图失败，第{}条边，报错内容：{}.", b,e.what());
                break;
            }
        }
        colorCount++;
        
    }
    return true;
}

bool ReadImg(string imgName, cv::Mat& img)
{
    img = cv::imread(ImgPath + imgName);
    if (img.empty())
    {
        //读取图像失败
        llog::error("DrawFineBorders-读取图像失败：" + ImgPath + imgName);
        return false;
    }
    return true;
}

bool SaveImg(const cv::Mat& img,string imgName)
{
    string fullPath = ImgPath + SaveDir;
    //先确认文件夹在不在
    bool isExist = filesystem::exists(fullPath) && filesystem::is_directory(fullPath);
    if (!isExist)
    {
        llog::info("SaveImg-保存图像 目录不存在，开始创建目录");
        //创建文件夹
        try
        {
            create_directory(fullPath);

        }
        catch (const std::exception&)
        {
            llog::error("SaveImg-保存图像 目录不存在，创建目录失败");
            return false;
        }
    }

    //保存图像
    cv::imwrite(fullPath + imgName + ".jpeg", img);

    return true;
}

