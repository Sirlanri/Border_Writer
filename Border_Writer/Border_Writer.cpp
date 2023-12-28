// Border_Writer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "configs.h"
#include "ReadPath.h"
#include "ImageProcess.h"

int main()
{
    /*局部变量*/
    //图像名称
    vector<string> ImageNames;
    //流程是否正常
    bool ok = true;


    /*主流程*/
    llog::info("系统启动");

    //获取图像列表
    ok=GetImgs(ImageNames);
    if (!ok)
    {
        //读取图像失败，程序直接退出
        llog::error("当前目录没有图像，程序退出 "+ ImgPath);
        system("pause");
        return 0;
    }
    
    //处理每张图
    for (int i = 0; i < ImageNames.size(); i++)
    { 
        /*临时数据*/

        //所有的细边界
        vector<vector<int>> fineBorders;
        //16粗边界
        vector<int> roughBorders16;
        //带束层粗边界
        vector<int> roughBorderTread;
        //当前图像Mat
        cv::Mat img;

        //读取细边界
        ok = ReadFineBorder(ImageNames[i], fineBorders);
        if (!ok)
        {
            //当前图像读取txt失败，从列表中删除此图像
            ImageNames.erase(ImageNames.begin() + i);
            //停止处理此图形
            continue;
        }


        //读取图像
        ok = ReadImg(ImageNames[i], img);
        if (!ok) continue;

        //16粗边界图像和带束层粗边界
        cv::Mat imgRough = img.clone();

        //绘制图像细边界
        ok = DrawFineBorders(img, fineBorders);
        if (!ok) continue;

        //保存图像
        ok = SaveImgFine(img, ImageNames[i]);
        if (!ok) continue;

    }

    system("pause");

    return 1;
}