#include <iostream>
using namespace std;
#include "snake.h"
#include"wall.h"
#include"food.h"
#include<Windows.h>

void gotoxy1(HANDLE hOut1, int x, int y)//����x��y������������෴�ģ�ע������
{
    COORD pos;
    pos.X = x;             //������
    pos.Y = y;            //������
    SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);

snake::snake(Wall& tempwall, Food& tempfood):wall(tempwall),food(tempfood)
{
	head = NULL;
	isRool = false;
}


void snake::DestroyAllPonit()
{
	Point* t = head;
	while (head!=NULL)
	{
		t = head->next;
		delete head;
		head = t;
	}
}

void snake::addpoint(int x, int y)
{
	Point* newpoint = new Point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;
	if (head != NULL)//���ԭ����ͷ��Ϊ�գ���Ϊ����
	{
		wall.setwall(head->x, head->y, '=');
		gotoxy1(hOut1, head->y * 2, head->x);
		cout << "=" ;
	}
		newpoint->next = head;
		head = newpoint;
		wall.setwall(head->x, head->y, '@');
		gotoxy1(hOut1, head->y * 2, head->x);
		cout << "@";
}

void snake::deletepoint()
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	else
	{

		Point* pre = head;
		Point* p = head->next;
		while (p->next!=NULL)
		{
			pre = pre->next;
			p = p->next;
		}
		wall.setwall(p->x, p->y, ' ');
		gotoxy1(hOut1, p->y * 2, p->x);
		cout << " ";
		delete p;
		pre->next = NULL;
	}
}

bool snake::move(char key)
{
	int x = head->x;
	int y = head->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	//�����������β�ͣ���Ӧ��������
	Point* pre = head;
	Point* p = head->next;
	while (p->next != NULL)
	{
		pre = pre->next;
		p = p->next;
	}
	if (p->x == x && p->y == y)
	{
		isRool = true;
	}
	else
	{
		if (wall.getwall(x, y) == '*'|| wall.getwall(x, y) == '=')
		{
			addpoint(x, y);
			deletepoint();
			system("cls");
			wall.draw();
			cout << "�÷֣�" << getSore() << "��" << endl;
			cout << "GAME OVER!" << endl;
			system("pause");
			return false;
		}
	}
	if (wall.getwall(x, y) == '#')
	{
		addpoint(x, y);//����ߵĳ���
		food.setfood();//�����µ�ʳ��
	}
	if (wall.getwall(x, y) == ' ')
	{
		addpoint(x, y);
		deletepoint();
		if (isRool == true)
		{
			wall.setwall(x, y, '@');
			gotoxy1(hOut1, y * 2, x);
			cout << "@";
		}
	}
	return true;
}

int snake::getSleepTime()
{
	int sleepTime = 0;
	int size = countList();
	if (size < 5)
	{
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 8)
	{
		sleepTime = 200;
	}
	else
		sleepTime = 100;
	return sleepTime;
}

int snake::countList()
{
	int size = 0;
	Point* p = head;
	while (p!=NULL)
	{
		size++;
		p = p->next;
	}
	return size;
}

int snake::getSore()
{
	int size = countList();
	int score = (size - 3) * 100;
	return score;
}

void snake::Initsnake()
{
	DestroyAllPonit();//�������нڵ�
	addpoint(5, 3);
	addpoint(5, 4);
	addpoint(5, 5);
}
