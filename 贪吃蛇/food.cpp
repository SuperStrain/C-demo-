#include <iostream>
using namespace std;
#include "food.h"
#include"wall.h"
#include<Windows.h>

void gotoxy2(HANDLE hOut2, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall& tempwall):wall(tempwall)
{
}
void Food::setfood()
{
	while (true)
	{
		foodx = rand() % (Wall::ROW - 2) + 1;
		foody = rand() % (Wall::COL - 2) + 1;
		//�������λ������������������ʳ��λ��
		if (wall.getwall(foodx, foody) == ' ')
		{
			wall.setwall(foodx, foody, '#');
			gotoxy2(hOut2, foody*2, foodx);
			cout << "#";
			break;
		}
	}
}	
