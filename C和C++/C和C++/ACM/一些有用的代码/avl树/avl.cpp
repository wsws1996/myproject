#include <iostream>
#include <string>
using namespace std;
#include "avl.h"
int main()
{
	cout << "---此程序实现平衡二叉树操作---" << endl << endl;
	AVL<int, int> avl;
	int n, x, select;
	bool  flag = 0;
	cout << "请输入要插入的元素个数：";
	cin >> n;
	cout << "请依次输入待插入的元素：";
	while (n--){
		cin >> x;
		avl.Insert(x, x);
	}
	do{
		cout << "请选择操作：1. 插入 2. 删除 3. 查找 4. 显示树的深度 5.中序遍历平衡二叉树 6.退出" << endl;
		cin >> select;
		switch (select){
		case 1:
			cout << "请输入待插入元素：";
			cin >> x;
			if (!avl.Insert(x, x))
				cout << "   结果：插入失败！";
			else
				cout << "   结果：插入成功！";
			break;
		case 2:
			cout << "请输入待删除元素：";
			cin >> x;
			if (!avl.Delete(x))
				cout << "   结果：删除失败！";
			else
				cout << "   结果：删除成功！";
			break;
		case 3:
			cout << "请输入待查找元素：";
			cin >> x;
			if (!avl.Search(x))
				cout << "   结果：查找失败！";
			else
				cout << "   结果：查找成功！";
			break;
		case 4:
			cout << "这棵平衡二叉树深度为：";
			cout << avl.GetDepth();
			cout << endl << endl;
			break;
		case 5:
			cout << endl << "该二叉排序树中序遍历为：";
			avl.InorderTraverse();
			cout << endl << endl;
			break;
		case 6:
			flag = 1;
			break;
		default:
			flag = 1;
			break;
		}
	} while (flag == 0);
	return 0;
}