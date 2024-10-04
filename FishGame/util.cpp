#include "util.h"

void titleDraw()
{
	int x = 20;
	int y = 5;
	system("mode con cols=150 lines=50 | title = fishing"); // 콘솔 크기 설정 및 타이틀
	gotoxy(x, y);
	cout<<"######   ######   ######   ##  ##   ######   ##  ##   ######"<<endl;
	gotoxy(x, y+1);
	cout << "######     ##     ###      ##  ##     ##     ### ##   ######" << endl;
	gotoxy(x, y+2);
	cout << "##         ##     ######   ######     ##     ######   ##" << endl;
	gotoxy(x, y+3);
	cout << "####       ##         ##   ######     ##     ## ###   ## ###" << endl;
	gotoxy(x, y+4);
	cout << "##       ######   ######   ##  ##   ######   ##  ##   ##  ##" << endl;
	gotoxy(x, y+5);
	cout << "##       ######   ######   ##  ##   ######   ##  ##   ######" << endl;
}

int PlaceDraw()
{
	int x = 32; //메뉴 x좌표
	int y = 15; //메뉴 y좌표
	gotoxy(x-3, y - 2);
	cout << "갈 곳을 정하세요";
	gotoxy(x - 2, y); //>표시를 위해 x-2
	cout << "> 낚시터 가기";
	gotoxy(x, y + 1);
	cout << "스 텟 창";
	gotoxy(x, y + 2);
	cout << " 침 대";
	gotoxy(x, y + 3);
	cout << " 상 점";
	gotoxy(x-1, y + 4);
	cout << "메 인 으 로";

	while (1)
	{
		int input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (y > 15) //15~17이동
			{
				gotoxy(x - 2, y); //현재 자리 지움
				cout << ' ';
				gotoxy(x - 2, --y); //위로 한칸 가서 >출력
				cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (y < 19) //15~17이동
			{
				gotoxy(x - 2, y);
				cout << ' ';
				gotoxy(x - 2, ++y);
				cout << '>';
			}
			break;
		}
		case SUBMIT:
		{
			return y - 15; //게임시작이면 12-12 해서 0, 스토리면 13-12 해서 1, 게임 종료는 14-12 해서 2 //0,1,2,3
		}
		}
	}

	return 0;
}

int keyControl()
{
	char temp = _getch();

	if (temp == 'w') return UP;
	else if (temp == 's') return DOWN;
	else if (temp == 'a') return LEFT;
	else if (temp == 'd') return RIGHT;
	else if (temp == ' ') return SUBMIT;
}

int menuDraw()
{
	int x = 32; //메뉴 x좌표
	int y = 15; //메뉴 y좌표
	gotoxy(x-2, y); //>표시를 위해 x-2
	cout << "> 게 임 시 작";
	gotoxy(x, y+1);
	cout << "스 토 리";
	gotoxy(x-1, y+2);
	cout << "게 임 종 료";

	while (1)
	{
		int input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (y > 15) //15~17이동
			{
				gotoxy(x - 2, y); //현재 자리 지움
				cout << ' ';
				gotoxy(x-2, --y); //위로 한칸 가서 >출력
				cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (y < 17) //15~17이동
			{
				gotoxy(x - 2, y);
				cout << ' ';
				gotoxy(x-2, ++y);
				cout << '>';
			}
			break;
		}
		case SUBMIT:
		{
			return y - 15; //게임시작이면 12-12 해서 0, 스토리면 13-12 해서 1, 게임 종료는 14-12 해서 2 //0,1,2
		}
		}
	}

	return 0;
}

void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x*2;
    pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void cursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void anyPressKey()
{
	cout << "아무키나 입력해서 나가기" << endl;
	while (1)
	{
		if (_kbhit() && _getch() != ' ') break;
	}
}

void Wait()
{
	while (1)
	{
		if (_kbhit() && _getch() == ' ') break;
	}
}
