#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<vector>
#include<conio.h>
#include<ctime>
using namespace std;

//��ũ�� ����

//Ű���� ��
#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#endif

//��� ��
#ifndef PLACE_CODE
#define PLACE_CODE

#define FISHING 0
#define STAT 1
#define BED 2
#define STORE 3
#define EXIT 4

#endif

//��� ��
#ifndef STAT_CODE
#define STAT_CODE

#define HEALTH 0
#define STRENGTH 2
#define PATIENCE 4

#endif

//���� ��
#ifndef COLOR_CODE
#define COLOR_CODE

#define BLACK 0
#define DARKBLUE 1
#define DARKGreen 2
#define DARKSkyBlue 3
#define DARKRed 4
#define DARKPurple 5
#define DARKYellow 6
#define GRAY 7
#define DARKGray 8
#define BLUE 9
#define GREEN 10
#define SKYBlue	11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

#endif


//�Լ� ����
void titleDraw(); //Ÿ��Ʋ �����ֱ�
int PlaceDraw(); //��� �����ֱ�
int keyControl(); //Ű �Է� ��
int menuDraw(); //�޴� �����ֱ�
void gotoxy(int x, int y); //���ϴ� ��ǥ �̵�
void textcolor(int foreground, int background); //���� ����
void cursorView(); //Ŀ�� �����
void anyPressKey(); //�ƹ�Ű ������
void Wait(); //��ٸ���
