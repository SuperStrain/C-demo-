#pragma once
#include<iostream>
using namespace std;
class Wall
{
public:
	enum 
	{
		ROW = 26,
	    COL = 26
	};
	void initwall();//����ǽ��
	void draw();//�������������Ϸ�ռ��ڵ�����ͼ��
	void setwall(int x,int y,char c);//��������������Ϸ�ռ��ڵķ���
	char getwall(int x,int y);			//����������õ�ǰλ�õķ���
private:
	char gamearray[ROW][COL];
};


