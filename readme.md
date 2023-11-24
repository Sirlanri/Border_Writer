# 轮胎边界绘制程序

**轮胎项目专用**

将边界txt文件绘制到图像中，便于判断边界的情况

# 使用方法

打开[release](https://github.com/Sirlanri/Border_Writer/releases)页面，下载 ``Border_Writer.exe`` 和 ``fmt.dll``两个文件

将 ``Border_Writer.exe`` 和 ``fmt.dll`` 复制到图像目录，确保目录内有txt_path文件夹，双击运行exe文件即可

使用spdlog模块，实现了相对完善的log，出现错误会在控制台记录，程序不会轻易崩溃哦

# 开发环境

* visual studio 2022 （C++ 17）
* OpenCV 4.5
* spdlog
