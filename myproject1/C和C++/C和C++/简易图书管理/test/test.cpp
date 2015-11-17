# include "stdafx.h"
# include "iostream"
# include "string"

using namespace std;

class book
{
public:
	int num;
	double price;
	string name;
	book*next;
};

book *head = NULL;

bool check(string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if ((str[i]>'9' || str[i] < '0') && str[i] != '.')
			return false;
	}
	return true;
}

book *creat()
{
	book *p, *pNext;
	pNext = new book;
	head = pNext;
	p = pNext;
	cout << "��ţ�";
	string str;
	cin >> str;
	while (!check(str))
	{
		cout << "Error!" << endl;
		cout << "��ţ�";
		cin >> str;
	}
	pNext->num = atoi(str.c_str());
	if (pNext->num != 0)
	{
		cout << "���ƣ�";
		cin >> pNext->name;
		cout << "�۸�";
		cin >> str;
		while (!check(str))
		{
			cout << "Error!" << endl;
			cout << "�۸�";
			cin >> str;
		}
		pNext->price = atof(str.c_str());
	}
	else
	{
		delete pNext;
		p = NULL;
		head = NULL;
		return head;
	}
	while (pNext->num != 0)
	{
		p = pNext;
		pNext = new book;
		cout << "��ţ�";
		cin >> str;
		while (!check(str))
		{
			cout << "Error!" << endl;
			cout << "��ţ�";
			cin >> str;
		}
		pNext->num = atoi(str.c_str());
		if (pNext->num != 0)
		{
			cout << "���ƣ�";
			cin >> pNext->name;
			cout << "�۸�";
			cin >> str;
			while (!check(str))
			{
				cout << "Error!" << endl;
				cout << "�۸�";
				cin >> str;
			}
			pNext->price = atof(str.c_str());
			p->next = pNext;
		}
	}
	delete pNext;
	p->next = NULL;
	return head;
}

bool del(book *head, int num)
{
	if (::head == NULL)
		return false;
	book *p, *q;
	p = ::head;
	if (num == 1)
	{
		q = p->next;
		::head = q;
		delete p;
		p = NULL;
		return true;
	}
	if (num == 2)
	{
		q = p->next;
		p->next = p->next->next;
		delete q;
		p = NULL;
		return true;
	}
	for (int i = 1; i < num - 1; ++i)
	{
		p = p->next;
	}
	if (p == NULL)
		return false;
	q = p->next;
	p->next = p->next->next;
	delete q;
	q = NULL;
	return true;
}

bool show(book *head)
{
	book *p;
	p = ::head;
	if (::head == NULL)
		return false;
	while (p != NULL)
	{
		cout << "��ţ�" << p->num << endl;
		cout << "���ƣ�" << p->name << endl;
		cout << "�۸�" << p->price << endl;
		p = p->next;
	}
	return true;
}

void HeadInsert(book *head, int num, string name, double price)
{
	book*p = new book;
	p->num = num;
	p->name = name;
	p->price = price;
	p->next = head;
	::head = p;
}

void TailInsert(book *head, int num, string name, double price)
{
	book *p = new book;
	book *l = head, *m = head;
	while (l)
	{
		m = l;
		l = l->next;
	}
	m->next = p;
	p->num = num;
	p->name = name;
	p->price = price;
	p->next = NULL;
}

void OrderlyInsert(book *head, int num, string name, double price)
{
	if (num <= ::head->num)
	{
		HeadInsert(head, num, name, price);
		return;
	}
	else
	{
		book *p = new book;
		book *l = ::head, *m = ::head;
		p->num = num;
		p->name = name;
		p->price = price;
		while (l->num < num)
		{
			m = l;
			l = l->next;
			if (l == NULL)
			{
				break;
			}
		}
		m->next = p;
		p->next = l;
		return;
	}
}

int GetBookNum(book *head)
{
	int num = 0;
	book *p;
	p = head;
	while (p)
	{
		p = p->next;
		num++;
	}
	return num;
}

int main(void)
{
	string str;
begin:
	cout << "1->�ؽ�ͼ��2->��ʾͼ��3->����ͼ��4->ɾ��ͼ��5->ͳ��ͼ����ĿQ->�˳�" << endl;
	cin >> str;
	if (str[0] == '1')
	{
		::head = creat();
		system("cls");
		goto begin;
	}
	if (str[0] == '2')
	{
		if (head == NULL)
		{
			cout << "Empty" << endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		else
		{
			show(head);
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
	}
	if (str[0] == '3')
	{
		if (head == NULL)
		{
			cout << "Empty" << endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		else
		{
			int num;
			string name;
			double price;
			string str;
			cout << "��ţ�";
			cin >> str;
			while (!check(str))
			{
				cout << "Error!" << endl;
				cout << "��ţ�";
				cin >> str;
			}
			num = atoi(str.c_str());
			cout << "���ƣ�" << endl;
			cin >> name;
			cout << "�۸�";
			cin >> str;
			while (!check(str))
			{
				cout << "Error!" << endl;
				cout << "�۸�";
				cin >> str;
			}
			price = atof(str.c_str());
			OrderlyInsert(head, num, name, price);
			system("cls");
			goto begin;
		}
	}
	if (str[0] == '4')
	{
		if (head == NULL)
		{
			cout << "Empty" << endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		else
		{
			string str;
			int num;
			cin >> str;
			while (!check(str))
			{
				cout << "Error!" << endl;
				cout << "��ţ�";
				cin >> str;
			}
			num = atoi(str.c_str());
			if (!del(head, num))
			{
				cout << "ɾ��ʧ��" << endl;
			}
			system("cls");
			goto begin;
		}
	}
	if (str[0] == '5')
	{
		if (head == NULL)
		{
			cout << "Empty" << endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
		else
		{
			cout << GetBookNum(head) << endl;
			cin.get();
			cin.get();
			system("cls");
			goto begin;
		}
	}
	if (str[0] == 'Q' || str[0] == 'q')
	{
		exit(0);
	}
}