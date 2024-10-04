#include "UIManager.h"

GameManager& gm = GameManager::GetInstance();

UIManager& UIManager::GetInstance()
{
	static UIManager inst;
	return inst;
}

void UIManager::ShowExp()
{
		cout << "레벨 : " << gm.level << " 경험치 : " << gm.exp << "/" << gm.expByLevel[gm.level-1] << endl;
}

void UIManager::ShowHealth(Unit* player)
{
	cout << "체력을 소비하였습니다. 남은 체력 : " << player->getHealth() << endl;
	if (player->getHealth() <= 0)
	{
		gm.GameOver();
		textcolor(RED, BLACK);
		cout << "당신은 과로사로 사망했습니다." << endl;
		textcolor(WHITE, BLACK);
		return;
	}
	else if (player->getHealth() <= 20) cout << "너 그러다 죽어" << endl;
	else if (player->getHealth() <= 40) cout << "집에 가자..." << endl;
	else if (player->getHealth() <= 60) cout << "돌아가서 좋은데이 한잔..." << endl;
}

int UIManager::ShowTime(time_t startTime, time_t currentTime, int timeLimit)
{
	double diffTime = difftime(currentTime, startTime); // 경과 시간 계산
	int remainingTime = timeLimit - (int)diffTime; // 남은 시간 계산
	if (remainingTime <= 0) remainingTime = 0;
	// 남은 시간 출력
	gotoxy(20, 2);
	cout << "  플레이 시간 : " << remainingTime << "초 " << endl;
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
	cout << "30일이 지났습니다." << endl;
	gotoxy(30, 11);
	cout << "감사합니다." << endl;
	gotoxy(30, 12);
	cout << "플레이 해주셔서 감사합니다. 더욱 더 발전하는 fishing company가 되겠습니다." << endl;
}

void UIManager::ShowStat(Player* player)
{
	system("cls");
	int y = 10;
	gotoxy(27, y-3);
	cout << "----------- 스   텟   창 -----------";
	gotoxy(30, y-1);
	cout << "   레벨 : " << gm.level<<" ("<<gm.exp<<"/"<<gm.expByLevel[gm.level-1] << ")";
	gotoxy(30, y+1);
	cout << "   이름 : " << player->getName();
	gotoxy(30, y + 3);
	cout << "   체력 : " << player->getHealth()<<"/"<<player->getMaxHealth();
	gotoxy(30, y + 5);
	cout << "   근력 : " << player->getAttack();
	gotoxy(30, y + 7);
	cout << "   인내심 : " << player->getPatience();
	gotoxy(30, y + 9);
	cout << "   돈 : " << gm.money_P<<"원";
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
	cout << "          ! 레   벨   업 !          ";
	gotoxy(22, y - 7);
	cout << "강화하실 스텟을 찍어 주세요. (체력 +10  근력 +1  인내심 +10)";
	gotoxy(27, y - 5);
	cout << "----------- 스   텟   창 -----------";
	gotoxy(30, y - 2);
	cout << "   이름 : " << player->getName();
	gotoxy(29, y);
	cout << "->   체력 : " << player->getHealth() << "/" << player->getMaxHealth();
	gotoxy(30, y + 2);
	cout << "   근력 : " << player->getAttack();
	gotoxy(30, y + 4);
	cout << "   인내심 : " << player->getPatience();
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
			return y - 13; //0,2,4 반환
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
	cout << "주인장이 노려보고 있다.";
	Sleep(500);
	gotoxy(3, y + 1);
	cout << "어떻게 할까?";
	while(1) if (_getch() == ' ') break;

	gotoxy(0, y - 2);
	cout << "-------------------------------------------------------------";
	gotoxy(1, y);
	cout << "->  1. 주인장과 대화한다     ";
	gotoxy(3, y + 1);
	cout << "2. 나만 당할수 없지, 똑같이 노려본다";
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
			return y - 24; //0,1 반환
		}
	}
}

void UIManager::npc0()
{
	gotoxy(3, 24);
	cout << "플레이어: 안녕하세요! 경일에서 왔습니다!";
	Wait();
	gotoxy(2, 24);
	cout << "주인장: 머라구?? 경일에서 왔다고?! 30퍼 할인!@";
	Wait();
	gotoxy(2, 24);
	cout << "                                                    ";
}

void UIManager::npc1()
{
	gotoxy(3, 24);
	cout << "주인장: 흠, 왜 그렇게 노려보는 거지 ?";
	Wait();
	gotoxy(3, 24);
	cout <<"플레이어: 당신이 먼저 했잖아.             ";
	Wait();
	gotoxy(3, 24);
	cout << "주인장: 사실… 내가 당신을 노려본 이유는";
	Wait();
	gotoxy(3, 24);
	cout << "주인장: 떼잉! 상품이나 봐!               ";
	Wait();
	gotoxy(3, 24);
	cout <<"플레이어: (이상한 주인장이다)                   ";
	Wait();
	gotoxy(2, 24);
	cout << "                                                    ";
}
