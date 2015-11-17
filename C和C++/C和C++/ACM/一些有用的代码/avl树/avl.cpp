#include <iostream>
#include <string>
using namespace std;
#include "avl.h"
int main()
{
	cout << "---�˳���ʵ��ƽ�����������---" << endl << endl;
	AVL<int, int> avl;
	int n, x, select;
	bool  flag = 0;
	cout << "������Ҫ�����Ԫ�ظ�����";
	cin >> n;
	cout << "����������������Ԫ�أ�";
	while (n--){
		cin >> x;
		avl.Insert(x, x);
	}
	do{
		cout << "��ѡ�������1. ���� 2. ɾ�� 3. ���� 4. ��ʾ������� 5.�������ƽ������� 6.�˳�" << endl;
		cin >> select;
		switch (select){
		case 1:
			cout << "�����������Ԫ�أ�";
			cin >> x;
			if (!avl.Insert(x, x))
				cout << "   ���������ʧ�ܣ�";
			else
				cout << "   ���������ɹ���";
			break;
		case 2:
			cout << "�������ɾ��Ԫ�أ�";
			cin >> x;
			if (!avl.Delete(x))
				cout << "   �����ɾ��ʧ�ܣ�";
			else
				cout << "   �����ɾ���ɹ���";
			break;
		case 3:
			cout << "�����������Ԫ�أ�";
			cin >> x;
			if (!avl.Search(x))
				cout << "   ���������ʧ�ܣ�";
			else
				cout << "   ��������ҳɹ���";
			break;
		case 4:
			cout << "���ƽ����������Ϊ��";
			cout << avl.GetDepth();
			cout << endl << endl;
			break;
		case 5:
			cout << endl << "�ö����������������Ϊ��";
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