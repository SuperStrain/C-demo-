#pragma once
#include<iostream>
using namespace std;
#include"wall.h"
#include"food.h"
class snake
{
public:
	snake(Wall &tempwall,Food &tempfood);//******
	struct Point
	{
		int x;
		int y;
		Point* next;
	};
	enum {
		UP='w', DOWN='s', LEFT='a', RIGHT='d' 
	};
	Point* head;
	Wall &wall;//******
	Food &food;
	bool isRool;
	int getSore();
	void Initsnake();
	void DestroyAllPonit();
	void addpoint(int x,int y);
	void deletepoint();
	bool move(char key);
	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();
private:

};
