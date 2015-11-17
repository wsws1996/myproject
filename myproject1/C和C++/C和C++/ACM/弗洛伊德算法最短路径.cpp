#include"stdafx.h"
#include<iostream>
using namespace std;
#define numVertexes 9
void ShortestPath_Floyd()
{
	int v, w, k;
	int G[numVertexes][numVertexes];
	int Pathmatirx[numVertexes][numVertexes];
	int ShortPathTable[numVertexes][numVertexes];
	for (v = 0; v < numVertexes; v++)
	{
		for (w = 0; w < numVertexes; w++)
		{
			cin >> G[v][w];
		}
	}  
	for (v = 0; v < numVertexes; ++v)
	{
		for (w = 0; w < numVertexes; ++w)
		{
			ShortPathTable[v][w] = G[v][w];
			Pathmatirx[v][w] = w;
		}
	}
	for (k = 0; k < numVertexes; ++k)
	{
		for (v = 0; v < numVertexes; v++)
		{
			for (w = 0; w < numVertexes; w++)
			{
				if (ShortPathTable[v][w]>ShortPathTable[v][k] + ShortPathTable[k][w])
				{
					ShortPathTable[v][w] = ShortPathTable[v][k] + ShortPathTable[k][w];
					Pathmatirx[v][w] = Pathmatirx[v][k];
				}
			}
		}
	}
	//ʹ��·������������
	for (v = 0; v < numVertexes; ++v)
	{
		for (w = 0; w < numVertexes; ++w)
		{
			cout << Pathmatirx[v][w] << " ";
		}
		cout << endl;
	}
	//����Ϊʹ��·��������֣��������ݹ��࣬������ʹ�ô��ַ�ʽ���
	//w = 0;
	//for (v = 0; v < numVertexes; ++v)
	//{
	//	for (w = 0; w < numVertexes; ++w)
	//	{
	//		cout << v << "->" << w << ":" << endl;
	//		cout << v << " ";
	//		k = w;
	//		cout << Pathmatirx[v][w] << " ";
	//		while (Pathmatirx[v][w]!=k)
	//		{
	//			v = Pathmatirx[v][w];
	//			cout << Pathmatirx[v][w]<<" ";
	//		}
	//		cout << endl;
	//	}
	//}
	//cout << "end" << endl;
}
int main(void)
{
	ShortestPath_Floyd();
	return 0;
}