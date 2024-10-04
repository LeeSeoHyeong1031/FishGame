#include "UIManager.h"

GameManager& gm = GameManager::GetInstance();

UIManager& UIManager::GetInstance()
{
	static UIManager inst;
	return inst;
}

void UIManager::ShowExp()
{
		cout << "���� : " << gm.level << " ����ġ : " << gm.exp << "/" << gm.expByLevel[gm.level-1] << endl;
}

void UIManager::ShowHealth(Unit* player)
{
	cout << "ü���� �Һ��Ͽ����ϴ�. ���� ü�� : " << player->getHealth() << endl;
	if (player->getHealth() <= 0)
	{
		gm.GameOver();
		textcolor(RED, BLACK);
		cout << "����� ���λ�� ����߽��ϴ�." << endl;
		textcolor(WHITE, BLACK);
		return;
	}
	else if (player->getHealth() <= 20) cout << "�� �׷��� �׾�" << endl;
	else if (player->getHealth() <= 40) cout << "���� ����..." << endl;
	else if (player->getHealth() <= 60) cout << "���ư��� �������� ����..." << endl;
}

int UIManager::ShowTime(time_t startTime, time_t currentTime, int timeLimit)
{
	double diffTime = difftime(currentTime, startTime); // ��� �ð� ���
	int remainingTime = timeLimit - (int)diffTime; // ���� �ð� ���
	if (remainingTime <= 0) remainingTime = 0;
	// ���� �ð� ���
	gotoxy(20, 2);
	cout << "  �÷��� �ð� : " << remainingTime << "�� " << endl;
	return remainingTime;
}

void UIManager::ShowTextGameOver(int num)
{
	int y = 10;
	for (int i = 0; i < num; i++)
	{
	gotoxy(30, y);
	cout << "GAME OVER";
	y += 2;
	Sleep(100);
	}
}

void UIManager::ShowDay()
{
	gotoxy(38,13);
	cout <<"(" << gm.days << " Day)" << endl;
}

void UIManager::ShowEnding()
{
	gotoxy(30, 10);
	cout << "30���� �������ϴ�." << endl;
	gotoxy(30, 11);
	cout << "�����մϴ�." << endl;
	gotoxy(30, 12);
	cout << "�÷��� ���ּż� �����մϴ�. ���� �� �����ϴ� fishing company�� �ǰڽ��ϴ�." << endl;
}

void UIManager::ShowStat(Player* player)
{
	system("cls");
	int y = 10;
	gotoxy(27, y-3);
	cout << "----------- ��   ��   â -----------";
	gotoxy(30, y-1);
	cout << "   ���� : " << gm.level<<" ("<<gm.exp<<"/"<<gm.expByLevel[gm.level-1] << ")";
	gotoxy(30, y+1);
	cout << "   �̸� : " << player->getName();
	gotoxy(30, y + 3);
	cout << "   ü�� : " << player->getHealth()<<"/"<<player->getMaxHealth();
	gotoxy(30, y + 5);
	cout << "   �ٷ� : " << player->getAttack();
	gotoxy(30, y + 7);
	cout << "   �γ��� : " << player->getPatience();
	gotoxy(30, y + 9);
	cout << "   �� : " << gm.money_P<<"��";
	gotoxy(27, y + 11);
	cout << "------------------------------------";
	gotoxy(29, y + 13);
	anyPressKey();
	cout << endl;
}

int UIManager::ShowLevelUpStat(Player* player)
{
	system("cls");
	int y = 13;
	gotoxy(27, y - 9);
	cout << "          ! ��   ��   �� !          ";
	gotoxy(22, y - 7);
	cout << "��ȭ�Ͻ� ������ ��� �ּ���. (ü�� +10  �ٷ� +1  �γ��� +10)";
	gotoxy(27, y - 5);
	cout << "----------- ��   ��   â -----------";
	gotoxy(30, y - 2);
	cout << "   �̸� : " << player->getName();
	gotoxy(29, y);
	cout << "->   ü�� : " << player->getHealth() << "/" << player->getMaxHealth();
	gotoxy(30, y + 2);
	cout << "   �ٷ� : " << player->getAttack();
	gotoxy(30, y + 4);
	cout << "   �γ��� : " << player->getPatience();
	gotoxy(27, y + 6);
	cout << "------------------------------------";
	while (1)
	{
		int key = keyControl();
		switch (key)
		{
		case UP:
			if (y > 13)
			{
				gotoxy(29, y);
				cout << "  ";
				y -= 2;
				gotoxy(29, y);
				cout << "->";
			}
			break;
		case DOWN:
			if (y < 17)
			{
				gotoxy(29, y);
				cout << "  ";
				y += 2;
				gotoxy(29, y);
				cout << "->";
			}
			break;
		case SUBMIT:
			return y - 13; //0,2,4 ��ȯ
		}
	}
}

int UIManager::npcTalk()
{
	int y = 24;
	gotoxy(0, y - 2);
	cout << "-------------------------------------------------------------";
	gotoxy(0, y + 2);
	cout << "-------------------------------------------------------------";
	gotoxy(3, y);
	cout << "�������� ������� �ִ�.";
	Sleep(500);
	gotoxy(3, y + 1);
	cout << "��� �ұ�?";
	while(1) if (_getch() == ' ') break;

	gotoxy(0, y - 2);
	cout << "-------------------------------------------------------------";
	gotoxy(1, y);
	cout << "->  1. ������� ��ȭ�Ѵ�     ";
	gotoxy(3, y + 1);
	cout << "2. ���� ���Ҽ� ����, �Ȱ��� �������";
	gotoxy(0, y + 2);
	cout << "-------------------------------------------------------------";
	
	while (1)
	{
		int key = keyControl();
		switch (key)
		{
		case UP:
			if (y > 24)
			{
				gotoxy(1, y);
				cout << "  ";
				gotoxy(1, --y);
				cout << "->";
			}
			break;
		case DOWN:
			if (y < 25)
			{
				gotoxy(1, y);
				cout << "  ";
				gotoxy(1, ++y);
				cout << "->";
			}
			break;
		case SUBMIT:
			gotoxy(1, 24);
			cout << "                                                   ";
			gotoxy(1, 25);
			cout << "                                                  ";
			return y - 24; //0,1 ��ȯ
		}
	}
}

void UIManager::npc0()
{
	gotoxy(3, 24);
	cout << "�÷��̾�: �ȳ��ϼ���! ���Ͽ��� �Խ��ϴ�!";
	Wait();
	gotoxy(2, 24);
	cout << "������: �Ӷ�?? ���Ͽ��� �Դٰ�?! 30�� ����!@";
	Wait();
	gotoxy(2, 24);
	cout << "                                                    ";
}

void UIManager::npc1()
{
	gotoxy(3, 24);
	cout << "������: ��, �� �׷��� ������� ���� ?";
	Wait();
	gotoxy(3, 24);
	cout <<"�÷��̾�: ����� ���� ���ݾ�.             ";
	Wait();
	gotoxy(3, 24);
	cout << "������: ��ǡ� ���� ����� ����� ������";
	Wait();
	gotoxy(3, 24);
	cout << "������: ����! ��ǰ�̳� ��!               ";
	Wait();
	gotoxy(3, 24);
	cout <<"�÷��̾�: (�̻��� �������̴�)                   ";
	Wait();
	gotoxy(2, 24);
	cout << "                                                    ";
}
