#include"stdafx.h"
#include <afxwin.h>         // MFC ���ĺͱ�׼���
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
void operation(const std::string &orgine_name)//������MFC�⣬����������������嵥�ļ���UAC���Ƽ���ΪҪ�����Ա��д���ļ�
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
			string newtime = (string)ftime.Format("%Y-%m-%d %H:%M:%S");//�������ַ���Ϊ���ֽ��ַ���
			if (lasttime != newtime)
			{
				ifstream in((LPCTSTR)orgine_name.c_str());
				string line;
				if (in) // �и��ļ�
				{
					while (getline(in, line)) // line�в�����ÿ�еĻ��з�
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
