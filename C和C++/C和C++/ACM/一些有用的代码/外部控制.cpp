#include"stdafx.h"
#include <afxwin.h>         // MFC 核心和标准组件
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
void operation(const std::string &orgine_name)//需配置MFC库，需配置链接器里的清单文件的UAC控制级别为要求管理员以写入文件
{
	string lasttime = "0";
	CFileFind finder;
	BOOL bWorking = finder.FindFile((LPCTSTR)orgine_name.c_str());

	while (true)
	{
		bWorking = finder.FindFile((LPCTSTR)orgine_name.c_str());
		if (bWorking) {
			bWorking = finder.FindNextFile();
			CTime ftime;
			finder.GetLastWriteTime(ftime);
			string newtime = (string)ftime.Format("%Y-%m-%d %H:%M:%S");//需配置字符集为多字节字符集
			if (lasttime != newtime)
			{
				ifstream in((LPCTSTR)orgine_name.c_str());
				string line;
				if (in) // 有该文件
				{
					while (getline(in, line)) // line中不包括每行的换行符
					{
						if (line[0] != '#')
						{
							system(line.c_str());
						}
					}
					in.close();
				}
			}
			lasttime = newtime;
			finder.Close();
		}
		Sleep(5000);
	}
}

int main(void)
{
	operation("G:\\BaiDuYunDownload\\operation.txt");
}
