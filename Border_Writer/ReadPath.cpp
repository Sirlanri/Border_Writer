#include "ReadPath.h"

int ReadFineBorder(string imgName, vector<vector<int>>& borders)
{
	//细边界
	string b1 = ImgPath + R"(txt_path\xifenge\1\)";
	string b2 = ImgPath + R"(txt_path\xifenge\2\)";
	string b3 = ImgPath + R"(txt_path\xifenge\3\)";
	string b4 = ImgPath + R"(txt_path\xifenge\4\)";
	string b5 = ImgPath + R"(txt_path\xifenge\5\)";
	string b6 = ImgPath + R"(txt_path\xifenge\6\)";
	string b7 = ImgPath + R"(txt_path\xifenge\7\)";
	string b8 = ImgPath + R"(txt_path\xifenge\8\)";

	//带束层细边界
	string t1 = ImgPath + R"(txt_path\xifenge_tread\1\)";
	string t2 = ImgPath + R"(txt_path\xifenge_tread\2\)";
	string t3 = ImgPath + R"(txt_path\xifenge_tread\3\)";
	string t4 = ImgPath + R"(txt_path\xifenge_tread\4\)";

	string paths[12] = { b1,b2,b3,b4,b5,b6,b7,b8,t1,t2,t3,t4 };

	//获取无后缀的图片文件名
	size_t pointIndex = imgName.rfind("."); //查找后缀名所在的位置下标
	imgName.erase(imgName.begin() + pointIndex, imgName.end());  //截取文件名

    //循环 处理12个边
    for (int i = 0; i < 12; i++)
    {
        //得到完整的txt路径
        paths[i].append(imgName).append(".txt");
        ifstream txtFile;
        //读取txt文件，获取边界
        txtFile.open(paths[i], ios::in);
        if (txtFile.fail())
        {
            llog::error("ReadFineBorder-该图像边界文件可能不存在" + paths[i]);
            return 0;
        }
        //存储临时变量
        vector<int> areaLine; //当前边
        int tempn;  //读取文件内容临时存放
        //判断是数据位（否则为下标）
        bool isdata = false;
        int index = 0;
        //循环读取当前文件，直至结束
        while (!txtFile.eof())
        {
            txtFile >> tempn;
            if (isdata)
            {
                areaLine.push_back(tempn);
                index++;
            }
            isdata = !isdata;
        }
        borders.push_back(areaLine);
        txtFile.close();
    }
    if (borders.size() == 0)
    {
        llog::error("ReadFineBorder-未能读取边界 "+imgName);
        return 0;
    }

	return 1;
}

bool ReadRoughBorder16(string imgName, vector<int>& borders)
{
    //16边界文件
    string b1 = ImgPath + R"(txt_path\cufenge\)";
    //获取无后缀的图片文件名
    size_t pointIndex = imgName.rfind("."); //查找后缀名所在的位置下标
    imgName.erase(imgName.begin() + pointIndex, imgName.end());  //截取文件名

    //拼接txt完整路径
    b1.append(imgName).append(".txt");
    ifstream txtFile;
    //读取txt文件，获取边界
    txtFile.open(b1, ios::in);

    if (txtFile.fail())
    {
        llog::error("ReadRoughBorder16-该图像边界文件可能不存在" + b1);
        return 0;
    }

    int tempn;  //读取文件内容临时存放
    //判断是数据位（否则为下标）
    bool isdata = false;
    int index = 0;
    //循环读取当前文件，直至结束
    while (!txtFile.eof())
    {
        txtFile >> tempn;
        if (isdata)
        {
            borders.push_back(tempn);
            index++;
        }
        isdata = !isdata;
    }
    txtFile.close();


    return true;
}

bool ReadRoughBorderTread(string imgName, vector<int>& borders)
{
    //16边界文件
    string b1 = ImgPath + R"(txt_path\cufenge_tread\)";
    //获取无后缀的图片文件名
    size_t pointIndex = imgName.rfind("."); //查找后缀名所在的位置下标
    imgName.erase(imgName.begin() + pointIndex, imgName.end());  //截取文件名

    //拼接txt完整路径
    b1.append(imgName).append(".txt");
    ifstream txtFile;
    //读取txt文件，获取边界
    txtFile.open(b1, ios::in);

    if (txtFile.fail())
    {
        llog::error("ReadRoughBorderTread-该图像边界文件可能不存在" + b1);
        return 0;
    }

    int tempn;  //读取文件内容临时存放
    //判断是数据位（否则为下标）
    bool isdata = false;
    int index = 0;
    //循环读取当前文件，直至结束
    while (!txtFile.eof())
    {
        txtFile >> tempn;
        if (isdata)
        {
            borders.push_back(tempn);
            index++;
        }
        isdata = !isdata;
    }
    txtFile.close();

    return true;
}
