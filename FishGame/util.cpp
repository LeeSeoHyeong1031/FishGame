#include "util.h"

void titleDraw()
{
	int x = 20;
	int y = 5;
	system("mode con cols=150 lines=50 | title = fishing"); // �ܼ� ũ�� ���� �� Ÿ��Ʋ
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
	int x = 32; //�޴� x��ǥ
	int y = 15; //�޴� y��ǥ
	gotoxy(x-3, y - 2);
	cout << "�� ���� ���ϼ���";
	gotoxy(x - 2, y); //>ǥ�ø� ���� x-2
	cout << "> ������ ����";
	gotoxy(x, y + 1);
	cout << "�� �� â";
	gotoxy(x, y + 2);
	cout << " ħ ��";
	gotoxy(x, y + 3);
	cout << " �� ��";
	gotoxy(x-1, y + 4);
	cout << "�� �� �� ��";

	while (1)
	{
		int input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (y > 15) //15~17�̵�
			{
				gotoxy(x - 2, y); //���� �ڸ� ����
				cout << ' ';
				gotoxy(x - 2, --y); //���� ��ĭ ���� >���
				cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (y < 19) //15~17�̵�
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
			return y - 15; //���ӽ����̸� 12-12 �ؼ� 0, ���丮�� 13-12 �ؼ� 1, ���� ����� 14-12 �ؼ� 2 //0,1,2,3
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
	int x = 32; //�޴� x��ǥ
	int y = 15; //�޴� y��ǥ
	gotoxy(x-2, y); //>ǥ�ø� ���� x-2
	cout << "> �� �� �� ��";
	gotoxy(x, y+1);
	cout << "�� �� ��";
	gotoxy(x-1, y+2);
	cout << "�� �� �� ��";

	while (1)
	{
		int input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (y > 15) //15~17�̵�
			{
				gotoxy(x - 2, y); //���� �ڸ� ����
				cout << ' ';
				gotoxy(x-2, --y); //���� ��ĭ ���� >���
				cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (y < 17) //15~17�̵�
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
			return y - 15; //���ӽ����̸� 12-12 �ؼ� 0, ���丮�� 13-12 �ؼ� 1, ���� ����� 14-12 �ؼ� 2 //0,1,2
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
	cout << "�ƹ�Ű�� �Է��ؼ� ������" << endl;
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
