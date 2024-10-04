#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<vector>
#include<conio.h>
#include<ctime>
using namespace std;

//매크로 정의

//키보드 값
#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#endif

//장소 값
#ifndef PLACE_CODE
#define PLACE_CODE

#define FISHING 0
#define STAT 1
#define BED 2
#define STORE 3
#define EXIT 4

#endif

//장소 값
#ifndef STAT_CODE
#define STAT_CODE

#define HEALTH 0
#define STRENGTH 2
#define PATIENCE 4

#endif

//색상 값
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


//함수 정의
void titleDraw(); //타이틀 보여주기
int PlaceDraw(); //장소 보여주기
int keyControl(); //키 입력 값
int menuDraw(); //메뉴 보여주기
void gotoxy(int x, int y); //원하는 좌표 이동
void textcolor(int foreground, int background); //색상 지정
void cursorView(); //커서 숨기기
void anyPressKey(); //아무키 누르기
void Wait(); //기다리기
